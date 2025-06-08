#ifndef ABSTRACTMESSAGEBOX_H
#define ABSTRACTMESSAGEBOX_H

#include <QWidget>

class AbstractMessageBox : public QWidget {
    Q_OBJECT
public:
    explicit AbstractMessageBox(QWidget *parent = nullptr) : QWidget(parent) {}
    virtual ~AbstractMessageBox() = default;

    enum UserChoice {
        ChoiceA,
        ChoiceB,
        Cancel,
        None
    };

    virtual UserChoice showDialog() = 0;
    virtual void setText(const QString &text) = 0;
    virtual void setTitle(const QString &title) = 0;
};

#endif // ABSTRACTMESSAGEBOX_H
