#include "datainsert.h"
#include "Hh_Settings/settingsmanager.h"
#include <QFile>
#include "Hh_Data_Structures/datastructures.h"


DataInsert::DataInsert(QObject *parent)
    : QObject{parent}
{

}

void DataInsert::insert_data_json_skills_amount()
{
    vacancies_id_open();
    m_json_arr=m_json_doc.array();
    //Перебираем каждый элемент массива вакансий,преобразуем,извлекаем массив навыков, записываем в DataStructure::QMapKeySkills
    for(const QJsonValue &val: m_json_arr)
    {
        QJsonObject obj=val.toObject();
        QJsonArray skills = obj["key_skills"].toArray();
        for (const QJsonValue &skillVal : skills)
        {
            if (skillVal.isObject())
            {
                QJsonObject skillObj = skillVal.toObject();
                if (skillObj.contains("name"))
                {
                    DataStructure::instance().m_qmap_keySkills_amount()[(skillObj["name"].toString())]+=1;

                }
            }
        }
    }
    #ifdef DEBUG_MACRO
    DataStructure::instance().show_value_qDebug(choiceEnum::KeySkillsCount);
    #endif
}

void DataInsert::insert_data_json_jobInfo()
{
    vacancies_id_open();
    m_json_arr=m_json_doc.array();
    for(const QJsonValue &val: m_json_arr)
    {
        JobInfoStruct jobInfo;
        QJsonObject obj=val.toObject();
        jobInfo.url=obj["alternate_url"].toString();
        jobInfo.area=obj["area"].toObject()["name"].toString();
        jobInfo.experience=obj["experience"].toObject()["name"].toString();
        jobInfo.vacancyName=obj["name"].toString();
        jobInfo.companyName=obj["employer"].toObject()["name"].toString();

        QJsonArray skills = obj["key_skills"].toArray();
        QJsonObject salaryObj = obj["salary"].toObject();

        for (const QJsonValue &skillVal : skills)
        {
            if (skillVal.isObject())
            {
                QJsonObject skillObj = skillVal.toObject();
                if (skillObj.contains("name"))
                {
                    jobInfo.skills.push_back(skillObj["name"].toString());
                }
            }
        }
        if (!salaryObj.isEmpty())
        {
            if (salaryObj.contains("currency"))
                jobInfo.currency = salaryObj["currency"].toString();
            if (salaryObj.contains("from"))
                jobInfo.salaryRange.first = salaryObj["from"].toInt();
            if (salaryObj.contains("to"))
                jobInfo.salaryRange.second = salaryObj["to"].toInt();  // ← не from!
        }
        DataStructure::instance().m_jobInfo().push_back(jobInfo);
    }
#ifdef DEBUG_MACRO
    DataStructure::instance().show_value_qDebug(choiceEnum::JobInfo);
#endif
}

void DataInsert::vacancies_id_open()
{
    QString path=SettingsManager::instance().value("vacancies_dir").toString();
    qDebug() << path;
    path+="/vacancies_id.json";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
#ifdef DEBUG_MACRO
        qWarning("Не удалось открыть файл!");
#endif
        return;
    }
    QByteArray json_data_id=file.readAll();
    file.close();
    QJsonParseError parseError;
    m_json_doc = QJsonDocument::fromJson(json_data_id, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Ошибка парсинга JSON:" << parseError.errorString();
        return;
    }
}
