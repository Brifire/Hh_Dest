#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <QObject>

class DataStructure : public QObject
{
    Q_OBJECT
public:
    explicit DataStructure(QObject *parent = nullptr);

signals:
};

#endif // DATASTRUCTURE_H
