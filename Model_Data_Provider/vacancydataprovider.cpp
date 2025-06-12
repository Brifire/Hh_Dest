#include "vacancydataprovider.h"
#include "Hh_Data_Structures/datastructures.h"
#include "Model_Data_Provider/secondtabprocessingstrategy.h"

void VacancyDataProvider::process(QStandardItemModel *model)
{
    model->clear();
    model->setHorizontalHeaderLabels({
        "Навык",
        "Средняя з/п",
        "Медиана",
        "Мода",
        "Дисперсия",
        "Ст. отклонение"
    });

    // Прямой вызов метода стратегии
    QHash<QString, DetailStat> skillStats = m_strategy->compute();

    for (auto it = skillStats.begin(); it != skillStats.end(); ++it) {
        const QString& skill = it.key();
        const DetailStat& stat = it.value();

        QList<QStandardItem*> row;
        row << new QStandardItem(skill)
            << new QStandardItem(QString::number((stat.salaryFrom + stat.salaryTo) / 2.0, 'f', 0))
            << new QStandardItem(QString::number(stat.mediana, 'f', 0))
            << new QStandardItem(QString::number(stat.moda, 'f', 0))
            << new QStandardItem(QString::number(stat.dispersion, 'f', 1))
            << new QStandardItem(QString::number(stat.standardDeviation, 'f', 1));

        model->appendRow(row);
    }
}
