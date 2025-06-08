#ifndef MESSAGEBOXSTARTWINDOW_H
#define MESSAGEBOXSTARTWINDOW_H

#include <QObject>
#include <QWidget>

class MessageBoxStartWindow : public QObject
{
    Q_OBJECT
public:
    explicit MessageBoxStartWindow(QObject *parent = nullptr);

signals:
};

#endif // MESSAGEBOXSTARTWINDOW_H
