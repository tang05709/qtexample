#include "userwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserWidget w;
    w.show();
    return a.exec();
}
