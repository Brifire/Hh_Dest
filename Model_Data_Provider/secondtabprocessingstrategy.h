#ifndef SECONDTABPROCESSINGSTRATEGY_H
#define SECONDTABPROCESSINGSTRATEGY_H

#include "Model_Data_Provider/abstractprocessingstrategy.h"
#include <qdeadlinetimer.h>
#include <set>
#include <vector>
#include <QHash>


struct DetailStat
{
    double salaryFrom;
    double salaryTo;
    double mediana;
    double moda;
    double dispersion;
    double standardDeviation;
};

using SkillStatMap = QHash<QString, DetailStat>;

class SecondTabProcessingStrategy : public AbstactProcessingStrategy
{
public:
    SecondTabProcessingStrategy();
    QVariant compute() override;
    QHash<QString,DetailStat> comp_QHash();
private:
    QHash<QString,DetailStat> m_qHashDetStat;
};

Q_DECLARE_METATYPE(SkillStatMap)
#endif // SECONDTABPROCESSINGSTRATEGY_H
