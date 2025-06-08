#include "hh_pars.h"
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include "../Hh_Settings/settingsmanager.h"
#include <QMessageBox>

Hh_pars::Hh_pars(QObject *parent)
    : QObject{parent}
{}

void Hh_pars::setMaxPages(int& pages)
{
    m_maxPages=pages;
}

void Hh_pars::onReplyFinished()
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
        m_maxPages = m_jsonObj["pages"].toInt(); // получаем общее число страниц
        qDebug() << "Всего страниц:" << m_maxPages;
    }
    for (const QJsonValue &value : m_items) {
        QJsonObject obj = value.toObject();
        QString id = obj["id"].toString();
        m_vacancyIdsToFetch << id;
    }

    m_currentPage++;
    if (m_currentPage < m_maxPages) {
        sig_fetchVacan(m_currentPage);
    } else {
        m_vacancyQueue = m_vacancyIdsToFetch;
        #ifdef DEBUG_MACRO
        qDebug() << "Всего ID: " << m_vacancyQueue.size();
        #endif
        processNextVacancyInChain();

    }

}

void Hh_pars::onVacancyDetailsFetched()
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

void Hh_pars::processNextVacancyInChain()
{
    qDebug() << "processNextVacancyInChain() вызван. Осталось ID:" << m_vacancyQueue.size();

    if (m_vacancyQueue.isEmpty()) {
        qDebug() <<"Очередь пуста, всё обработано.";
        return;
    }

    QString nextId = m_vacancyQueue.takeFirst();
    sig_fetchVacancyDetails(nextId);
}
 //VACANCIES_ID
void Hh_pars::saveVacanciesToFile()
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
        qDebug() << "Данные сохранены в vacancies_id.json";
    }

}
