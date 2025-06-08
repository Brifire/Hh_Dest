#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Hh_Downloading_Menu/downloadingmenu.h"
#include "Hh_Search/hh_search.h"
#include <QMessageBox>
#include <QAction>
#include "Hh_Analyzer/datainsert.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fill_tab();
    void fill_qt_chart();
    void connects();

private:
    Ui::MainWindow *ui;
    Hh_Search *search_json;
    QMessageBox m_msgBox;
    QAction *m_download_action;
    DataInsert *m_data_insert;
    DownloadingMenu *m_menu;
public slots:
    void open_menu_download();
    void download_vacancies();
    void check_json_files();
    void fill_widgets();
};
#endif // MAINWINDOW_H
