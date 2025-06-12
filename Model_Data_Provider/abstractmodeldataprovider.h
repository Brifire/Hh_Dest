#ifndef ABSTRACTMODELDATAPROVIDER_H
#define ABSTRACTMODELDATAPROVIDER_H

#include <QObject>
#include <QAbstractItemModel>
#include <QVariantList>
#include <qstandarditemmodel.h>


class AbstractModelDataProvider: public QObject
{
    Q_OBJECT
public:
    virtual ~AbstractModelDataProvider()=default;
    virtual void process(QStandardItemModel *model) = 0;
};

#endif // ABSTRACTMODELDATAPROVIDER_H
