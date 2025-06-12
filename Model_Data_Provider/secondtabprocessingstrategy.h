#ifndef SECONDTABPROCESSINGSTRATEGY_H
#define SECONDTABPROCESSINGSTRATEGY_H

#include "Model_Data_Provider/abstractprocessingstrategy.h"
#include <qdeadlinetimer.h>
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


class SecondTabProcessingStrategy : public AbstactProcessingStrategy
{
public:
    SecondTabProcessingStrategy();
    QHash<QString, DetailStat> compute() ;
    QHash<QString,DetailStat> comp_QHash();
private:
    QHash<QString,DetailStat> m_qHashDetStat;
};


#endif // SECONDTABPROCESSINGSTRATEGY_H
