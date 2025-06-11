#ifndef VACANCYDATAPROVIDER_H
#define VACANCYDATAPROVIDER_H

#include <QObject>
#include <qstandarditemmodel.h>
#include "abstractmodeldataprovider.h"
#include "abstractprocessingstrategy.h"

class VacancyDataProvider : public AbstractModelDataProvider
{
public:
    explicit VacancyDataProvider(AbstactProcessingStrategy* strategy) : m_strategy(strategy){};
    void process(const QList <QVariant> &data, QStandardItemModel *model) override;
private:
    AbstactProcessingStrategy* m_strategy;
};

#endif // VACANCYDATAPROVIDER_H
