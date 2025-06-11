#ifndef JOBINFOSECONDTABADAPTER_H
#define JOBINFOSECONDTABADAPTER_H

#include "Model_Data_Provider/abstactrowdata.h"
#include <qobject.h>
#include "Hh_Data_Structures/datastructures.h"

class JobInfoSecondTabAdapter : public AbstractRowData
{
public:
    JobInfoSecondTabAdapter();
    QStringList to_string_list() const override;

private:

    JobInfoStruct m_jobInfoStruct;
};

#endif // JOBINFOSECONDTABADAPTER_H
