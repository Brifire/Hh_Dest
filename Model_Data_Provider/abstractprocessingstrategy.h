#ifndef ABSTRACTPROCESSINGSTRATEGY_H
#define ABSTRACTPROCESSINGSTRATEGY_H

#include <qobject.h>

class AbstactProcessingStrategy {
public:
    virtual ~AbstactProcessingStrategy() = default;
    virtual QString compute(const IRowData& data) const = 0;
};

#endif // ABSTRACTPROCESSINGSTRATEGY_H
