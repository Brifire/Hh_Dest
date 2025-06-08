#include "downloadvacanciesid.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QFile>
#include <QDebug>
#include <QThread>

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "Hh_Settings/settingsmanager.h"

#include <QFile>
#include <QMessageBox>

#include <QFileDialog>


DownloadVacanciesId::DownloadVacanciesId(const QString& text,int max_pages, QObject *parent):m_text(text),m_maxPages(max_pages),manager(new QNetworkAccessManager(this))
{

}

void DownloadVacanciesId::hh_search_JSON_items(int page, const QString& text)
{
    m_text=text;
    QUrl url("https://api.hh.ru/vacancies");
    QUrlQuery query;
    query.addQueryItem("text", m_text);
    query.addQueryItem("area", "113");// РОССИЯ
    query.addQueryItem("page", QString::number(page));
    url.setQuery(query);  // применяем параметры к URL
    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Qt)");
    QNetworkReply *reply = manager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(onReplyFinished()));
}

void DownloadVacanciesId::processNextVacancyInChain()
{
    QString text="processNextVacancyInChain() вызван. Осталось ID:"+ QString::number(m_vacancyQueue.size());
    qDebug() << text;
    emit sig_progressbar(text);
    if (m_vacancyQueue.isEmpty()) {
    emit sig_progressbar("Очередь пуста, всё обработано.");

        return;
    }

    QString nextId = m_vacancyQueue.takeFirst();
    fetchNextVacancyDetails(nextId);
}

void DownloadVacanciesId::saveVacanciesToFile()
{
    if(!SettingsManager::instance().contains("vacancies_dir"))
    {
        QMessageBox::information(nullptr, " ", "Выберете папку для сохранения файла");
        QString path=QFileDialog::getExistingDirectory();
        SettingsManager::instance().setValue("vacancies_dir",path);
    };
    QFile file(SettingsManager::instance().value("vacancies_dir").toString()+"/vacancies_id.json");
    if (file.open(QIODevice::WriteOnly))
    {
        QJsonDocument doc(m_allVacancyObjects);
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
        emit sig_progressbar("Очередь пуста, всё обработано.");
        qDebug() << "Данные сохранены в vacancies_id.json";
        emit sig_progressbar_close();
    }
}



void DownloadVacanciesId::onReplyFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    if (reply->error()) {
        qWarning() << "Ошибка запроса:" << reply->errorString();
        reply->deleteLater();
        return;
    }
    m_response = reply->readAll();
    reply->deleteLater();
    m_jsonDoc = QJsonDocument::fromJson(m_response);
    m_jsonObj = m_jsonDoc.object();
    m_items = m_jsonObj["items"].toArray();

    if (m_currentPage == 0)
    {
        int debug_maxPages = m_jsonObj["pages"].toInt(); // получаем общее число страниц
        qDebug() << "Всего страниц:" << debug_maxPages;
    }
    for (const QJsonValue &value : m_items) {
        QJsonObject obj = value.toObject();
        QString id = obj["id"].toString();
        m_vacancyIdsToFetch << id;
    }
    m_currentPage++;
    if (m_currentPage < m_maxPages) {
        hh_search_JSON_items(m_currentPage);
    } else {
        m_vacancyQueue = m_vacancyIdsToFetch;
#ifdef DEBUG_MACRO
        qDebug() << "Всего ID: " << m_vacancyQueue.size();
#endif
        processNextVacancyInChain();

    }

}

void DownloadVacanciesId::fetchNextVacancyDetails(QString& id)
{
    QUrl url("https://api.hh.ru/vacancies/" + id);
    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Qt)");
    QNetworkReply *reply = manager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(onVacancyDetailsFetched()));
}

void DownloadVacanciesId::onVacancyDetailsFetched()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;
    if (reply->error()) {
#ifdef DEBUG_MACRO
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        QString reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        QString contentType = reply->header(QNetworkRequest::ContentTypeHeader).toString();
        QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
        QString rawHeaderKeys;
        for (const QByteArray &key : reply->rawHeaderList()) {
            rawHeaderKeys += QString("%1: %2\n").arg(QString(key), QString(reply->rawHeader(key)));
        }
        qWarning() << "ОШИБКА ЗАПРОСА";
        qWarning() << "URL запроса:" << reply->url().toString();
        qWarning() << "HTTP статус:" << statusCode;
        qWarning() << "Причина отказа (reason):" << reason;
        qWarning() << "Тип контента (Content-Type):" << contentType;
        qWarning() << "Код ошибки Qt:" << reply->error();
        qWarning() << "Текст ошибки:" << reply->errorString();
        qWarning() << "Заголовки ответа:\n" << rawHeaderKeys;

        if (redirectionTarget.isValid()) {
            qWarning() << "Перенаправление на:" << redirectionTarget.toUrl().toString();
        }

        QByteArray body = reply->readAll();
        if (!body.isEmpty()) {
            qWarning() << "Ответ от сервера:" << QString::fromUtf8(body);
        }
#endif
        reply->deleteLater();
        m_repliesReceived++;
        if (m_repliesReceived == m_vacancyIdsToFetch.size()) {
            saveVacanciesToFile();
        }
        return;
    }
    QByteArray response = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(response);
    QJsonObject obj = doc.object();
    m_allVacancyObjects.append(obj);
    m_repliesReceived++;
    if (m_repliesReceived == m_vacancyIdsToFetch.size())
    {
        saveVacanciesToFile();
    }
    QTimer::singleShot(1000, this, SLOT(processNextVacancyInChain()));
    reply->deleteLater();
}
