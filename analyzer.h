#ifndef ANALYZER_H
#define ANALYZER_H

#include <QObject>

class Analyzer : public QObject
{
    Q_OBJECT
public:
    explicit Analyzer(QObject *parent = nullptr);

signals:
};

#endif // ANALYZER_H
