#ifndef CUSTOMMESSAGEBOX_H
#define CUSTOMMESSAGEBOX_H

#include "abstractmessagebox.h"
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>

class CustomMessageBox : public AbstractMessageBox {
    Q_OBJECT
public:
    explicit CustomMessageBox(QWidget *parent = nullptr);
    CustomMessageBox(QWidget *parent,const QString &text, const QString &title);
    ~CustomMessageBox() override = default;

    void setText(const QString &text) override;
    void setTitle(const QString &title) override;
    void show_window() override;
private:

    QMessageBox box;
    QPushButton *buttonA;
    QPushButton *buttonB;
    QPushButton *cancelButton;
    QFileDialog *m_fileDialog;
};

#endif // CUSTOMMESSAGEBOX_H
