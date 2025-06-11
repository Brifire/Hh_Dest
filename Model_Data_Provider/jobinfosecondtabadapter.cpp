#include "jobinfosecondtabadapter.h"

JobInfoSecondTabAdapter::JobInfoSecondTabAdapter() {}

QStringList JobInfoSecondTabAdapter::to_string_list() const
{
    return {m_jobInfoStruct.companyName,
            m_jobInfoStruct.vacancyName,
            m_jobInfoStruct.area,
            m_jobInfoStruct.currency,
            // m_jobInfoStruct.
            // QString::number(m_jobInfoStruct.),
            // QString::number(v.experience)

           };
}


