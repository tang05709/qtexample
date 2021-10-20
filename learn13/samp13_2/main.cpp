#include "mainwindow.h"
#include "conndlg.h"

#include <QApplication>
#include <QFile>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    ConnDlg dialog;
    if (dialog.exec() != QDialog::Accepted) {
        return -1;
    }
    QFile *carDetails = new QFile("attribs.xml");
    MainWindow window("factory", "cars", carDetails);
    window.show();

    return a.exec();
}
