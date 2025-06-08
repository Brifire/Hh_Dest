#include "hh_search.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <QThread>


Hh_Search::Hh_Search(QWidget *parent,const QString& text)
    : QWidget{parent}
    , manager(new QNetworkAccessManager(this))
    , pars(new Hh_pars(this))
    , m_text(text)

{
    connect(pars, SIGNAL(sig_fetchVacan(int)), this, SLOT(fetchVacancies(int))); //сигналы в Hh_pars
    connect(pars, SIGNAL(sig_fetchVacancyDetails(QString)), this, SLOT(fetchNextVacancyDetails(QString)));
    fetchVacancies(currentPage);
}

Hh_Search::~Hh_Search()
{

}
//поиск файла по вакансии
void Hh_Search::fetchVacancies(int page)
{
    QUrl url("https://api.hh.ru/vacancies");
    QUrlQuery query;
    query.addQueryItem("text", m_text);
    query.addQueryItem("area", "113");// РОССИЯ
    query.addQueryItem("page", QString::number(page));
    url.setQuery(query);  // применяем параметры к URL
    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Qt)");
    QNetworkReply *reply = manager->get(request);
    pars->setMaxPages(maxPages);
    connect(reply, SIGNAL(finished()), pars, SLOT(onReplyFinished())); //парс в Hh_pars
}
//поиск по id вакансии
void Hh_Search::fetchNextVacancyDetails(const QString &id)
{
    QUrl url("https://api.hh.ru/vacancies/" + id);
    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Qt)");
    QNetworkReply *reply = manager->get(request);
    connect(reply, SIGNAL(finished()), pars, SLOT(onVacancyDetailsFetched()));
}


