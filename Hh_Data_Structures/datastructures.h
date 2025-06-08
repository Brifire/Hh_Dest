#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <QHash>
#include <QUrl>
#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <QMap>
#include <QPair>
#include <QUrl>
#include <QString>
#include <vector>
#include <QMutex>

struct JobInfoStruct
{
    QPair<int, int> salaryRange;
    QUrl url;
    std::vector<QString> skills;
    QString vacancyName;
    QString companyName;
    QString currency;
    QString experience;
    QString area;
};
enum class choiceEnum
{
    KeySkillsCount,
    JobInfo
};

class DataStructure
{
public:
    // Получить доступ к синглтону
    static DataStructure& instance();

    // Доступ к данным
    QMap<QString, int>& m_qmap_keySkills_amount();
    std::vector<JobInfoStruct>& m_jobInfo();

    // Утилиты
    void clear(choiceEnum choice);
    void show_value_qDebug(choiceEnum choice);

private:
    // Приватный конструктор и запрет копирования
    DataStructure() = default;
    ~DataStructure() = default;

    DataStructure(const DataStructure&) = delete;
    DataStructure& operator=(const DataStructure&) = delete;

    // Данные
    QMap<QString, int> m_qmap_keySkills;
    std::vector<JobInfoStruct> m_vec_jobInfo;

};

#endif // DATASTRUCTURE_H


#endif // DATASTORAGE_H
