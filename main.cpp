#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include "mainwindow.h"
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main;
    QObject::connect(&main, SIGNAL(destroyed), &a, SLOT(quit));
    main.show();

    return a.exec();
}
