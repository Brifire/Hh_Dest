#include "custommessagebox.h"
#include <QFileDialog>

CustomMessageBox::StartCustomMessageBox(QWidget *parent)
    : AbstractMessageBox(parent)
{
    box.setIcon(QMessageBox::Question);
    box.setText("Файл vacanices_id.json не найден. Укажите папку с данным файлом.(Если данного файла у вас нет, его можно загрузить из главного меню");
    buttonA = box.addButton("Ок", QMessageBox::YesRole);
    cancelButton = box.addButton("Отмена", QMessageBox::RejectRole);
    connect(buttonA,SIGNAL(clicked(bool)))
}

CustomMessageBox::StartCustomMessageBox(QWidget *parent, const QString &text, const QString &title)
{
    box.setText(text);
    box.setWindowTitle(title);
}

void CustomMessageBox::setText(const QString &text) {
    box.setText(text);
}

void CustomMessageBox::setTitle(const QString &title) {
    box.setWindowTitle(title);
}

void CustomMessageBox::show_window()
{
    box.exec();
}
