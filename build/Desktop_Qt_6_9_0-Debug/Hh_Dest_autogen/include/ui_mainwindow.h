/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *OpenDolwnloadingMenu;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_amount_skills;
    QHBoxLayout *horizontalLayout_2;
    QChartView *chartView_skills;
    QTableWidget *tableWidget_skills_value;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1014, 633);
        OpenDolwnloadingMenu = new QAction(MainWindow);
        OpenDolwnloadingMenu->setObjectName("OpenDolwnloadingMenu");
        OpenDolwnloadingMenu->setEnabled(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab_amount_skills = new QWidget();
        tab_amount_skills->setObjectName("tab_amount_skills");
        horizontalLayout_2 = new QHBoxLayout(tab_amount_skills);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        chartView_skills = new QChartView(tab_amount_skills);
        chartView_skills->setObjectName("chartView_skills");

        horizontalLayout_2->addWidget(chartView_skills);

        tableWidget_skills_value = new QTableWidget(tab_amount_skills);
        tableWidget_skills_value->setObjectName("tableWidget_skills_value");

        horizontalLayout_2->addWidget(tableWidget_skills_value, 0, Qt::AlignmentFlag::AlignRight);

        tabWidget->addTab(tab_amount_skills, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(tab_2);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1014, 23));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(OpenDolwnloadingMenu);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        OpenDolwnloadingMenu->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\274\320\265\320\275\321\216 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\262\320\260\320\272\320\260\320\275\321\201\320\270\320\271", nullptr));
#if QT_CONFIG(accessibility)
        tab_amount_skills->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        tabWidget->setTabText(tabWidget->indexOf(tab_amount_skills), QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\277\320\276 \320\272\320\273\321\216\321\207\320\265\320\262\321\213\320\274 \320\275\320\260\320\262\321\213\320\272\320\260\320\274", nullptr));
#if QT_CONFIG(accessibility)
        tab_2->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\227\320\264\320\265\321\201\321\214 \320\275\320\270\321\207\320\265\320\263\320\276 \320\275\320\265\321\202", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
