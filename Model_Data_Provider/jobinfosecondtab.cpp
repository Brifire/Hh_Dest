#include "jobinfosecondtab.h"

JobInfoSecondTabAdapter::JobInfoSecondTabAdapter() {}

QStringList JobInfoSecondTabAdapter::to_string_list() const
{
    return {v.title,
            QString::number(v.salary),
            QString::number(v.experience)

           };
}


