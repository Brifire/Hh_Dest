#ifndef VACANCYDATAPROVIDER_H
#define VACANCYDATAPROVIDER_H

#include <QObject>
#include <qstandarditemmodel.h>
#include "Hh_Data_Structures/datastructures.h"
#include "Model_Data_Provider/secondtabprocessingstrategy.h"
#include "abstractmodeldataprovider.h"
#include "abstractprocessingstrategy.h"

class VacancyDataProvider : public AbstractModelDataProvider
{
public:
    explicit VacancyDataProvider(SecondTabProcessingStrategy* strategy) : m_strategy(strategy){};
    void process(QStandardItemModel *model) override;
private:
    SecondTabProcessingStrategy* m_strategy;
};

#endif // VACANCYDATAPROVIDER_H
