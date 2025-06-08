#ifndef HH_PARS_H
#define HH_PARS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>

class Hh_pars : public QObject
{
    Q_OBJECT
public:
    explicit Hh_pars(QObject *parent = nullptr);
    void setMaxPages(int& pages);
    void saveVacanciesToFile();
private:
    int m_currentPage=0;
    QStringList m_vacancyIdsToFetch;
    int m_maxPages;

    QByteArray m_response;
    QJsonDocument m_jsonDoc;
    QJsonObject m_jsonObj;
    QJsonArray m_items;
    QStringList m_vacancyQueue;
    QJsonArray m_allVacancyObjects;
    int m_repliesReceived = 0; //счетчик реплаев

signals:
    void sig_fetchVacan(int page);
    void sig_fetchVacancyDetails(const QString &id);

private slots:
    void onVacancyDetailsFetched();
    void onReplyFinished();
    void processNextVacancyInChain();
};

#endif // HH_PARS_H
