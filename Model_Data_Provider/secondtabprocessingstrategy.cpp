#include "secondtabprocessingstrategy.h"
#include <qvariant.h>
#include "Hh_Data_Structures/datastructures.h"

SecondTabProcessingStrategy::SecondTabProcessingStrategy() {}



QVariant SecondTabProcessingStrategy::compute()
{

        m_qHashDetStat.clear();

        QHash<QString, QVector<double>> skillSalaryMap;

        // Собираем данные
        const auto& jobs = DataStructure::instance().m_jobInfo();
        for (const auto& job : jobs) {
            double from = job.salaryRange.first;
            double to = job.salaryRange.second;
            if (from <= 0 || to <= 0 || from > to) continue;

            double midSalary = (from + to) / 2.0;

            for (const auto& skill : job.skills) {
                skillSalaryMap[skill].append(midSalary);
            }
        }

        // Вычисляем статистику по каждому навыку
        for (auto it = skillSalaryMap.begin(); it != skillSalaryMap.end(); ++it) {
            const QString& skill = it.key();
            const QVector<double>& salaries = it.value();

            if (salaries.isEmpty()) continue;

            DetailStat stat{};
            int n = salaries.size();

            // Средние salaryFrom/To (предположим, midSalary — представление общего уровня зарплаты)
            stat.salaryFrom = std::accumulate(salaries.begin(), salaries.end(), 0.0) / n;
            stat.salaryTo = stat.salaryFrom; // Или вынеси from/to отдельно, если нужно точно

            // Медиана
            QVector<double> sorted = salaries;
            std::sort(sorted.begin(), sorted.end());
            if (n % 2 == 0)
                stat.mediana = (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
            else
                stat.mediana = sorted[n / 2];

            // Мода (чаще всего встречающееся значение)
            std::map<int, int> freq;
            for (double val : salaries)
                freq[static_cast<int>(val)]++;

            int maxFreq = 0, modaVal = 0;
            for (const auto& [value, count] : freq) {
                if (count > maxFreq) {
                    maxFreq = count;
                    modaVal = value;
                }
            }
            stat.moda = modaVal;

            // Дисперсия и стандартное отклонение
            double mean = stat.salaryFrom;
            double sqSum = 0.0;
            for (double val : salaries)
                sqSum += (val - mean) * (val - mean);

            stat.dispersion = sqSum / n;
            stat.standardDeviation = qSqrt(stat.dispersion);

            // Запись
            m_qHashDetStat.insert(skill, stat);
        }
        QString ss;
        return m_qHashDetStat;
}

QHash<QString, DetailStat> SecondTabProcessingStrategy::comp_QHash()
{
    m_qHashDetStat.clear();

    QHash<QString, QVector<double>> skillSalaryMap;

    // Собираем данные
    const auto& jobs = DataStructure::instance().m_jobInfo();
    for (const auto& job : jobs) {
        double from = job.salaryRange.first;
        double to = job.salaryRange.second;
        if (from <= 0 || to <= 0 || from > to) continue;

        double midSalary = (from + to) / 2.0;

        for (const auto& skill : job.skills) {
            skillSalaryMap[skill].append(midSalary);
        }
    }

    // Вычисляем статистику по каждому навыку
    for (auto it = skillSalaryMap.begin(); it != skillSalaryMap.end(); ++it) {
        const QString& skill = it.key();
        const QVector<double>& salaries = it.value();

        if (salaries.isEmpty()) continue;

        DetailStat stat{};
        int n = salaries.size();

        // Средние salaryFrom/To (предположим, midSalary — представление общего уровня зарплаты)
        stat.salaryFrom = std::accumulate(salaries.begin(), salaries.end(), 0.0) / n;
        stat.salaryTo = stat.salaryFrom; // Или вынеси from/to отдельно, если нужно точно

        // Медиана
        QVector<double> sorted = salaries;
        std::sort(sorted.begin(), sorted.end());
        if (n % 2 == 0)
            stat.mediana = (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
        else
            stat.mediana = sorted[n / 2];

        // Мода (чаще всего встречающееся значение)
        std::map<int, int> freq;
        for (double val : salaries)
            freq[static_cast<int>(val)]++;

        int maxFreq = 0, modaVal = 0;
        for (const auto& [value, count] : freq) {
            if (count > maxFreq) {
                maxFreq = count;
                modaVal = value;
            }
        }
        stat.moda = modaVal;

        // Дисперсия и стандартное отклонение
        double mean = stat.salaryFrom;
        double sqSum = 0.0;
        for (double val : salaries)
            sqSum += (val - mean) * (val - mean);

        stat.dispersion = sqSum / n;
        stat.standardDeviation = qSqrt(stat.dispersion);

        // Запись
        m_qHashDetStat.insert(skill, stat);
    }
    return m_qHashDetStat;
}




