#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Sign in yout personal page");
    w.resize(300, 300);
    w.show();
    return a.exec();
}
