#ifndef DOWNLOADJSONDATA_H
#define DOWNLOADJSONDATA_H

#include <QObject>


class DownloadJSONData : public QObject
{
    Q_OBJECT
public:
    \
    virtual void hh_search_JSON_items(int page=0,const QString& text="EmptyGet")=0;

private:

public slots:

signals:
};

#endif // DOWNLOADJSONDATA_H
