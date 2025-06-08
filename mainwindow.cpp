#include "mainwindow.h"
#include "Hh_Downloading_Menu/downloadingmenu.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include "Custom_Message_Box/custommessagebox.h"

#include "Hh_Settings/settingsmanager.h"

#include "Hh_Analyzer/datainsert.h"

#include "Hh_Data_Structures/datastructures.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QMap>

#include <Tabs_Filler/tabskillsfiller.h>

#include <Tabs_Filler/tabskillsfiller.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connects();
    check_json_files();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check_json_files()
{
    QString path=SettingsManager::instance().value("vacancies_dir").toString();
    #ifdef DEBUG_MACRO
        qDebug() << path;
    #endif
    if (QFile::exists(path+"/vacancies_id.json")) {
    #ifdef DEBUG_MACRO
        qDebug() << "Файлы найдены!";
    #endif
    } else{
        #ifdef DEBUG_MACRO
        qDebug() << "Файлы отсутствуют!";
        #endif
        CustomMessageBox *start=new CustomMessageBox(this,MsgBoxchoice::MsgFileNotFound,[this]()
        {
            this->check_json_files();
        });
        delete start;
    }
    fill_widgets();

}

void MainWindow::fill_widgets()
{
    DataInsert::instance()->insert_data_json_skills_amount();
    DataInsert::instance()->insert_data_json_jobInfo();
    DataStructure::instance().show_value_qDebug(choiceEnum::JobInfo);
    AbstractTabFiller* filler = new TabSkillsFiller();
    filler->fill_tab(ui->tab_amount_skills);
    delete filler;
}

void MainWindow::fill_tab()
{
    ui->tableWidget_skills_value->setRowCount(DataStructure::instance().m_qmap_keySkills_amount().count());
    ui->tableWidget_skills_value->setColumnCount(2);
    QStringList headers = {"Навыки", "Количество"};
    ui->tableWidget_skills_value->setHorizontalHeaderLabels(headers);

    const QMap<QString, int>& skills = DataStructure::instance().m_qmap_keySkills_amount();
    QVector<QPair<QString, int>> sortedList;
    for (auto it = skills.constBegin(); it != skills.constEnd(); ++it) {
        sortedList.append(qMakePair(it.key(), it.value()));
    }
    std::sort(sortedList.begin(), sortedList.end(), [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
        return a.second > b.second;
    });

    for (int row = 0; row < sortedList.size(); ++row) {
        ui->tableWidget_skills_value->setItem(row, 0, new QTableWidgetItem(sortedList[row].first));
        ui->tableWidget_skills_value->setItem(row, 1, new QTableWidgetItem(QString::number(sortedList[row].second)));
    }
}


void MainWindow::fill_qt_chart()
{
    QBarSet *set = new QBarSet("Навыки");
    QStringList categories;

    int rowCount = ui->tableWidget_skills_value->rowCount();
    QVector<QPair<QString, int>> data;

    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem *keyItem = ui->tableWidget_skills_value->item(row, 0);
        QTableWidgetItem *valueItem = ui->tableWidget_skills_value->item(row, 1);

        if (keyItem && valueItem) {
            QString key = keyItem->text();
            bool ok = false;
            int value = valueItem->text().toInt(&ok);

            if (ok) {
                data.append(qMakePair(key, value));
            }
        }
    }

    // Сортировка по убыванию значений
    std::sort(data.begin(), data.end(), [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
        return a.second > b.second;
    });

    // Добавление 15 первых
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
    axisX->setLabelsAngle(-45); // по желанию

    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    chart->createDefaultAxes();
    chart->legend()->setVisible(false);

    // Отображение в виджете
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Очистка
    QLayout *oldLayout = ui->chartView_skills->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    // Добавление нового layout
    QVBoxLayout *layout = new QVBoxLayout(ui->chartView_skills);
    layout->addWidget(chartView);

}

void MainWindow::connects()
{
connect(ui->OpenDolwnloadingMenu,SIGNAL(triggered(bool)),this,SLOT(open_menu_download()));
}

void MainWindow::open_menu_download()
{
   #ifdef DEBUG_MACRO
   qDebug()<<"open_menu_download()"<<Qt::endl;
   #endif
   m_menu=new DownloadingMenu(this);
   m_menu->setAttribute(Qt::WA_DeleteOnClose);
   connect(m_menu,SIGNAL(sig_fill_widgets()),this,SLOT(fill_widgets()));
   m_menu->show();
}


void MainWindow::download_vacancies()
{
    search_json=new Hh_Search(this);
}


