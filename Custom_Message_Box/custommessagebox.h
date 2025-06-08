#ifndef CUSTOMMESSAGEBOX_H
#define CUSTOMMESSAGEBOX_H

#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>


enum class MsgBoxchoice
{
    MsgFileNotFound
};

class CustomMessageBox : public QWidget {
    Q_OBJECT
public:
    explicit CustomMessageBox(QWidget *parent = nullptr, MsgBoxchoice messageType=MsgBoxchoice::MsgFileNotFound,std::function<void()> callback=nullptr);
    ~CustomMessageBox() = default;

    void setText(const QString &text) ;
    void setTitle(const QString &title) ;
    void msg_file_not_found();

public slots:
    void show_file_dialog();

private:
    std::function<void()> m_callback;
    MsgBoxchoice messageType;
    QMessageBox box;
    QPushButton *buttonY;
    QPushButton *cancelButton;
    QFileDialog *m_fileDialog;
};

#endif // CUSTOMMESSAGEBOX_H
