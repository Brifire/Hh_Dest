#ifndef ABSTRACTMODELDATAPROVIDER_H
#define ABSTRACTMODELDATAPROVIDER_H

#include <QObject>
#include <QAbstractItemModel>
#include <QVariantList>

class AbstractModelDataProvider:QObject
{
    Q_OBJECT
public:
    AbstractModelDataProvider();
    virtual ~AbstractModelDataProvider()=default;
    virtual void process(const QVariantList& rawData, QAbstractItemModel* model) = 0;
};

#endif // ABSTRACTMODELDATAPROVIDER_H
