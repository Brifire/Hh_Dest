#ifndef HH_SEARCH_H
#define HH_SEARCH_H

#include <QObject>
#include <QWidget>

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>
#include "hh_pars.h"

class Hh_Search : public QWidget
{
    Q_OBJECT
public:
    explicit Hh_Search(QWidget *parent = nullptr, const QString &text = QString());
    ~Hh_Search();

private:
    QNetworkAccessManager *manager;
    int currentPage = 0;
    int maxPages = 1;
    QStringList vacancyIdsToFetch;
    QJsonArray detailedVacancies;
    int repliesReceived = 0;
    bool check_data;

    QStringList vacancyQueue;
    QTimer *vacancyTimer = nullptr;

    QString m_text;


    Hh_pars *pars;
private slots:

    void fetchVacancies(int page);
    void fetchNextVacancyDetails(const QString &id);

signals:
};

#endif // HH_SEARCH_H
