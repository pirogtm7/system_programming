#include "mainwindow.h"

#include <QApplication>

// Робота студентів групи ІТ-81, Пиріг Віри та Федчук Олени

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
