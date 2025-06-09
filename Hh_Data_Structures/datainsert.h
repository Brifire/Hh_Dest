#ifndef DATAINSERT_H
#define DATAINSERT_H

#include <QObject>
#include <QHash>
#include <QJsonArray>
#include <qjsonobject.h>

class DataInsert : public QObject
{
    Q_OBJECT
public:
    static DataInsert* instance()
    {
        static DataInsert* _instance = new DataInsert;
        return _instance;
    }
    void insert_data_json_skills_amount();
    void insert_data_json_jobInfo();
    void vacancies_id_open();

private:
    explicit DataInsert(QObject *parent = nullptr);
    QJsonDocument m_json_doc;
    QJsonArray    m_json_arr;
    QJsonValue    m_json_value;
    QJsonObject   m_result;
    QJsonArray m_final_array;
signals:
};

#endif // DATAINSERT_H
