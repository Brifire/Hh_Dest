#include "hhparsjson.h"
#include <QFile>
#include "../Hh_Settings/settingsmanager.h"
#include <QFile>



HhParsJSON::HhParsJSON(QObject *parent)
    : QObject{parent}
{

}

void HhParsJSON::make_json_key_skills()
{
    file_id_open();
    m_json_arr=m_json_doc.array();
    //Перебираем каждый элемент массива вакансий,преобразуем,извлекаем массив навыков, преобразуем в массив
    for (const QJsonValue &val : m_json_arr) {
        QJsonObject obj = val.toObject();
        if (obj.contains("key_skills") && obj["key_skills"].isArray()) {
            QJsonArray skills = obj["key_skills"].toArray();
            for (const QJsonValue &skillVal : skills) {
                if (skillVal.isObject()) {
                    QJsonObject skillObj = skillVal.toObject();
                    if (skillObj.contains("name")) {
                        m_final_array.append(skillObj["name"]);
                    }
                }
            }
        }
    }
    save_skills_json();
}

void HhParsJSON::file_id_open()
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

void HhParsJSON::make_qhash_from_Json_skills()
{


}

void HhParsJSON::save_skills_json()
{
    QFile json_skills(SettingsManager::instance().value("vacancies_dir").toString()+"/vacancies_skills.json");
    if (json_skills.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(m_final_array);
        json_skills.write(doc.toJson(QJsonDocument::Indented));
        json_skills.close();
        qDebug() << "Данные сохранены в vacancies_skills.json";
    } else {
        qWarning() << "Не удалось сохранить файл skills!";
    }
}



