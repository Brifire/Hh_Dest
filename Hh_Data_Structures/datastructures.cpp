#include "datastructures.h"

#include <QDebug>






DataStructure &DataStructure::instance()
{
    static DataStructure instance;
    return instance;
}

QMap<QString, int> &DataStructure::m_qmap_keySkills_amount()
{
    return m_qmap_keySkills;
}

std::vector<JobInfoStruct> &DataStructure::m_jobInfo()
{
    return m_vec_jobInfo;
}

void DataStructure::clear(choiceEnum choice)
{
    switch (choice) {
    case choiceEnum::KeySkillsCount:
    {
        m_qmap_keySkills.clear();
        break;
    }
    case choiceEnum::JobInfo:
    {
        m_vec_jobInfo.clear();
        break;
    }
    default:
        break;
    }
}

void DataStructure::show_value_qDebug(choiceEnum choice)
{
#ifdef DEBUG_MACRO
    switch (choice) {
    case choiceEnum::KeySkillsCount:
    {
        for (auto it =m_qmap_keySkills.constBegin(); it == m_qmap_keySkills.constEnd(); ++it)
        {
            qDebug()<<"Навык: "<<it.key()<< "Количество: "<<it.value();
        }
        break;
    }
    case choiceEnum::JobInfo:
    {
        for (auto it = m_vec_jobInfo.begin(); it !=m_vec_jobInfo.end(); ++it)
        {
            qDebug()<<"Компания: "<<it->companyName<< "Разброс зарплат: от "<<it->salaryRange.first<<" до "<<it->salaryRange.second<<" "<<it->currency<<"   "<<it->url;
            int i=1;
            for (QString var : it->skills)
            {
                qDebug()<<"Skill N"<<i<<" "<<var;
                ++i;
            }
        }
        break;
    }
    default:
        break;
    }
#endif
}
