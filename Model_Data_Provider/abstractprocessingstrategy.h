#ifndef ABSTRACTPROCESSINGSTRATEGY_H
#define ABSTRACTPROCESSINGSTRATEGY_H

#include "Model_Data_Provider/abstactrowdata.h"
#include <qobject.h>


class AbstactProcessingStrategy {
public:
    virtual ~AbstactProcessingStrategy() = default;
    virtual QVariant compute()= 0;
};

#endif // ABSTRACTPROCESSINGSTRATEGY_H
