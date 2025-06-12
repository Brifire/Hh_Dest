#ifndef ABSTRACTPROCESSINGSTRATEGY_H
#define ABSTRACTPROCESSINGSTRATEGY_H

#include <qobject.h>



class AbstactProcessingStrategy {
public:
    virtual ~AbstactProcessingStrategy() = default;
    //virtual QHash<QString, DetailStat> compute()= 0;
};

#endif // ABSTRACTPROCESSINGSTRATEGY_H
