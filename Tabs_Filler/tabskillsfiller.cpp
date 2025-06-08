#include "tabskillsfiller.h"
#include <Hh_Data_Structures/datastructures.h>
#include <QtCharts>

TabSkillsFiller::TabSkillsFiller() {}

void TabSkillsFiller::fill_tab(QWidget *tab)
{
    if (!tab) return;

    auto *table = tab->findChild<QTableWidget*>("tableWidget_skills_value");
    auto *chartContainer = tab->findChild<QWidget*>("chartView_skills");

    if (!table || !chartContainer) {
        qWarning() << "Не найдены нужные виджеты в tab.";
        return;
    }

    fill_table(table);
    fill_chart(chartContainer, table);
}

void TabSkillsFiller::fill_table(QTableWidget *tableWidget)
{
    const QMap<QString, int>& skills = DataStructure::instance().m_qmap_keySkills_amount();

    QVector<QPair<QString, int>> sortedList;
    for (auto it = skills.constBegin(); it != skills.constEnd(); ++it) {
        sortedList.append(qMakePair(it.key(), it.value()));
    }

    std::sort(sortedList.begin(), sortedList.end(), [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
        return a.second > b.second;
    });

    tableWidget->setRowCount(sortedList.size());
    tableWidget->setColumnCount(2);
    tableWidget->setHorizontalHeaderLabels({"Навыки", "Количество"});

    for (int row = 0; row < sortedList.size(); ++row) {
        tableWidget->setItem(row, 0, new QTableWidgetItem(sortedList[row].first));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(sortedList[row].second)));
    }

}

void TabSkillsFiller::fill_chart(QWidget *chartContainer, QTableWidget *tableWidget)
{
    QBarSet *set = new QBarSet("Навыки");
    QStringList categories;
    QVector<QPair<QString, int>> data;

    int rowCount = tableWidget->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem *keyItem = tableWidget->item(row, 0);
        QTableWidgetItem *valueItem = tableWidget->item(row, 1);

        if (keyItem && valueItem) {
            QString key = keyItem->text();
            bool ok = false;
            int value = valueItem->text().toInt(&ok);
            if (ok) {
                data.append(qMakePair(key, value));
            }
        }
    }

    std::sort(data.begin(), data.end(), [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
        return a.second > b.second;
    });

    int limit = std::min(15, static_cast<int>(data.size()));
    for (int i = 0; i < limit; ++i) {
        *set << data[i].second;
        categories << data[i].first;
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Топ-15 навыков");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setLabelsAngle(-45);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    chart->createDefaultAxes();
    chart->legend()->setVisible(false);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Очистка контейнера
    if (QLayout* oldLayout = chartContainer->layout()) {
        QLayoutItem* item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    QVBoxLayout *layout = new QVBoxLayout(chartContainer);
    layout->addWidget(chartView);
}
