#ifndef JOBINFOSECONDTAB_H
#define JOBINFOSECONDTAB_H

#include "Model_Data_Provider/abstactrowdata.h"
#include <qobject.h>

class JobInfoSecondTabAdapter : public AbstractRowData
{
public:
    JobInfoSecondTabAdapter();
    QStringList to_string_list() const override;
private:
    struct Vacancy
    {
        QString title;
        double salary;
        double experience;

    };
    Vacancy v;
};

#endif // JOBINFOSECONDTAB_H
