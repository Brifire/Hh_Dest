#include "hhparssearch.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <QThread>



HhParsSearch::HhParsSearch(QObject *parent)
    : QObject{parent}
{}
