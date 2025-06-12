#ifndef DOWNLOADVACANCIESID_H
#define DOWNLOADVACANCIESID_H

#include "Hh_Search/downloadjsondata.h"
#include <QJsonArray>
#include <QTimer>
#include <QObject>

#include <QNetworkAccessManager>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>


class DownloadVacanciesId: public DownloadJSONData
{
    Q_OBJECT
public:
    DownloadVacanciesId(const QString& text="EmptyGET",int max_pages=1,QObject *parent = nullptr);
    void hh_search_JSON_items(int page=0, const QString& text="EmptyGET") override;
    void saveVacanciesToFile();
private:
    QNetworkAccessManager *manager;
    int currentPage = 0;
    int maxPages = 1;
    QStringList vacancyIdsToFetch;
    QJsonArray detailedVacancies;
    int repliesReceived = 0;
    QStringList vacancyQueue;
    QTimer *vacancyTimer = nullptr;

    QString m_text;

    int m_currentPage=0;
    QStringList m_vacancyIdsToFetch;
    int m_maxPages=0;
    QByteArray m_response;
    QJsonDocument m_jsonDoc;
    QJsonObject m_jsonObj;
    QJsonArray m_items;
    QStringList m_vacancyQueue;
    QJsonArray m_allVacancyObjects;
    int m_repliesReceived = 0; //счетчик реплаев
    bool raz=true;


public slots:
    void onReplyFinished();
    void fetchNextVacancyDetails(QString& id);
    void onVacancyDetailsFetched();
    void processNextVacancyInChain();
signals:
    void sig_progressbar(const QString& text);
    void sig_progressbar_close();
};

#endif // DOWNLOADVACANCIESID_H
