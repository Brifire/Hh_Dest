#ifndef DOWNLOADINGMENU_H
#define DOWNLOADINGMENU_H

#include <QObject>
#include <QWidget>

#include "Hh_Downloading_Menu/ui_downloadingmenu.h"
#include "Hh_Search/downloadvacanciesid.h"
#include <QProgressDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class DownloadingMenu;
}
QT_END_NAMESPACE

class DownloadingMenu : public QWidget
{
    Q_OBJECT
public:
    explicit DownloadingMenu(QWidget *parent = nullptr);
    ~DownloadingMenu();
    void closeEvent(QCloseEvent *event)override;
    void init_DownloadingMenu();
    void init_QProgressDialog();
private:
    Ui::DownloadingMenu *ui;
    DownloadVacanciesId* data_find;
    QProgressDialog *progress;

signals:
    void sig_fill_widgets();

private slots:
    void on_pushButton_clicked();
    void progress_bar_text_changed(const QString &text);
    void on_progress_bar_closed();
};

#endif // DOWNLOADINGMENU_H
