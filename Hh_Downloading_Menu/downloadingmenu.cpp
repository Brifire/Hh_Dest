#include "downloadingmenu.h"
#include "Hh_Search/downloadvacanciesid.h"
#include <QDialog>
#include <qevent.h>
#include "Hh_Data_Structures/datastructures.h"

DownloadingMenu::DownloadingMenu(QWidget *parent)
    : QWidget{parent}
    ,ui(new Ui::DownloadingMenu)
    ,data_find(new DownloadVacanciesId)
{
    init_DownloadingMenu();
    connect(data_find,&DownloadVacanciesId::sig_progressbar,this,&DownloadingMenu::progress_bar_text_changed);
    connect(data_find,&DownloadVacanciesId::sig_progressbar_close,this,&DownloadingMenu::on_progress_bar_closed);
}

DownloadingMenu::~DownloadingMenu()
{

}

void DownloadingMenu::closeEvent(QCloseEvent *event)
{
     DataStructure::instance().clear(choiceEnum::JobInfo);
     DataStructure::instance().clear(choiceEnum::KeySkillsCount);
     emit sig_fill_widgets();
     this->close();
}

void DownloadingMenu::init_DownloadingMenu()
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    this->setWindowTitle("Загрузка данных");
    connect(ui->spinBox,&QSpinBox::valueChanged,ui->lcdNumber,[=](int t){this->ui->lcdNumber->display(t);});
}

void DownloadingMenu::init_QProgressDialog()
{
    progress = new QProgressDialog("Загрузка данных...", "Отмена", 0, 0, this);
    progress->setWindowModality(Qt::WindowModal);
    progress->setCancelButton(nullptr);
    progress->show();
}

void DownloadingMenu::on_pushButton_clicked()
{
    QString text=ui->lineEdit->text();
    DataStructure::instance().clear(choiceEnum::KeySkillsCount);
    data_find->hh_search_JSON_items((ui->spinBox->value()/20),text);
    init_QProgressDialog();
}

void DownloadingMenu::progress_bar_text_changed(const QString &text)
{
    progress->setLabelText("Загрузка данных...   "+text);
}

void DownloadingMenu::on_progress_bar_closed()
{
    progress->close();
    QCloseEvent e;
    this->closeEvent(&e);
}

