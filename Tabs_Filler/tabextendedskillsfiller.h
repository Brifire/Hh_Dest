#ifndef TABEXTENDEDSKILLSFILLER_H
#define TABEXTENDEDSKILLSFILLER_H

#include "abstracttabfiller.h"

class TabExtendedSkillsFiller: public AbstractTabFiller
{
public:
    TabExtendedSkillsFiller();
    void fill_tab(QWidget* tab) override;
};

#endif // TABEXTENDEDSKILLSFILLER_H
