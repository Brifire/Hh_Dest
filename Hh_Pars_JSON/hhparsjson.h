#ifndef HHPARSJSON_H
#define HHPARSJSON_H

#include <QObject>

#include <QJsonArray>
#include <QJsonObject>

#include <QHash>

class HhParsJSON : public QObject
{
    Q_OBJECT
public:
    explicit HhParsJSON(QObject *parent = nullptr);
    void make_json_key_skills();
    void file_id_open();
    void make_qhash_from_Json_skills();
    void save_skills_json();
private:
    QJsonDocument m_json_doc;
    QJsonArray    m_json_arr;
    QJsonValue    m_json_value;
    QJsonObject   m_result;
    QHash<QString,int> m_keySkills;
    QJsonArray m_final_array;


signals:
};

#endif // HHPARSJSON_H
