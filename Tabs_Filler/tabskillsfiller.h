#ifndef TABSKILLSFILLER_H
#define TABSKILLSFILLER_H

#include <QObject>
#include <qtablewidget.h>
#include "abstracttabfiller.h"

class TabSkillsFiller: public AbstractTabFiller
{
public:
    TabSkillsFiller();
    void fill_tab(QWidget* tab) override;
private:
    void fill_table(QTableWidget* tableWidget);
    void fill_chart(QWidget* chartContainer, QTableWidget* tableWidget);
};

#endif // TABSKILLSFILLER_H
