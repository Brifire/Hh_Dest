#include "vacancydataprovider.h"
#include "Hh_Data_Structures/datastructures.h"
#include "Model_Data_Provider/abstactrowdata.h"

void VacancyDataProvider::process(const QList <QVariant> &data, QStandardItemModel *model)
{
    model->clear();
    model->setHorizontalHeaderLabels({"Вакансия", "Компания", "Оклад от", "Оклад до", "Навыки", "Статистика"});

    // ❗️ Выполняем расчёт статистики один раз по всем данным
    QVariant computedStats = m_strategy->compute();

    SkillStatMap skillStats;
    if (computedStats.canConvert<SkillStatMap>())
        skillStats = computedStats.value<SkillStatMap>();

    for (const QVariant& item : data) {
        if (!item.canConvert<JobInfoStruct>())
            continue;

        JobInfoStruct job = item.value<JobInfoStruct>();

        QList<QStandardItem*> row;
        row << new QStandardItem(job.vacancyName)
            << new QStandardItem(job.companyName)
            << new QStandardItem(QString::number(job.salaryRange.first))
            << new QStandardItem(QString::number(job.salaryRange.second))
            << new QStandardItem(job.skills.join(", "));

        // ⚡️ Поиск статистики по каждому навыку
        QStringList statLines;
        for (const QString& skill : job.skills) {
            if (skillStats.contains(skill)) {
                const DetailStat& stat = skillStats[skill];
                statLines << QString("%1: ⌀ %.0f | Мода %.0f | σ %.0f")
                                 .arg(skill)
                                 .arg((stat.salaryFrom + stat.salaryTo) / 2.0)
                                 .arg(stat.moda)
                                 .arg(stat.standardDeviation);
            }
        }

        row << new QStandardItem(statLines.join("\n"));
        model->appendRow(row);
    }

}
