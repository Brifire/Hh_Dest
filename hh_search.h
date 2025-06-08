#ifndef HH_SEARCH_H
#define HH_SEARCH_H

#include <QObject>
#include <QWidget>

class Hh_Search : public QObject
{
    Q_OBJECT
public:
    explicit Hh_Search(QObject *parent = nullptr);

signals:
};

#endif // HH_SEARCH_H
