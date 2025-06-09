#include "custommessagebox.h"
#include <QFileDialog>
#include "../Hh_Settings/settingsmanager.h"
#include <Hh_Data_Structures/datainsert.h>

CustomMessageBox::CustomMessageBox(QWidget *parent, MsgBoxchoice messageType,std::function<void()> callback)
    : QWidget(parent), m_callback(callback)
{
    switch (messageType)
    {
    case MsgBoxchoice::MsgFileNotFound:
        msg_file_not_found();
        break;
    default:
        break;
    }
}


void CustomMessageBox::setText(const QString &text) {
    box.setText(text);
}

void CustomMessageBox::setTitle(const QString &title) {
    box.setWindowTitle(title);
}

void CustomMessageBox::msg_file_not_found()
{
    box.setIcon(QMessageBox::Question);
    box.setText("Файл vacanices_id.json не найден. Укажите папку с данным файлом.(Если данного файла у вас нет, его можно загрузить из главного меню)");
    buttonY = box.addButton("Ок", QMessageBox::YesRole);
    cancelButton = box.addButton("Отмена", QMessageBox::RejectRole);
    connect(buttonY,SIGNAL(clicked(bool)),this,SLOT(show_file_dialog()));
    box.exec();
}



void CustomMessageBox::show_file_dialog()
{
    QString path=QFileDialog::getExistingDirectory();
    qDebug()<<path<<Qt::endl;
    if (QFile::exists(path+"/vacancies_id.json")) {
#ifdef DEBUG_MACRO
        qDebug() << "Файлы найдены!";
#endif
    SettingsManager::instance().setValue("vacancies_dir",path);
    if(m_callback) m_callback();

    } else{
#ifdef DEBUG_MACRO
        qDebug() << "Файлы отсутствуют!";
#endif
        box.exec();
    }

}
