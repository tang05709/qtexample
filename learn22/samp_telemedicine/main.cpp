#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createMySqlConn()) {
        return -1;
    }
    MainWindow w;
    w.show();
    return a.exec();
}
