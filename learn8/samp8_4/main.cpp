#include "mainwindow.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>
#include <QFile>
#include <QTextStream>
#include "datedelegate.h"
#include "combodelegate.h"
#include "spindelegate.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStandardItemModel model(4, 4);
    QTableView table;
    table.setModel(&model);
    DateDelegate dateDelegate;
    table.setItemDelegateForColumn(1, &dateDelegate);
    ComboDelegate comboDelegate;
    table.setItemDelegateForColumn(2, &comboDelegate);
    SpinDelegate spinDelegate;
    table.setItemDelegateForColumn(3, &spinDelegate);
    model.setHeaderData(0, Qt::Horizontal, QObject::tr("姓名"));
    model.setHeaderData(0, Qt::Horizontal, QObject::tr("生日"));
    model.setHeaderData(0, Qt::Horizontal, QObject::tr("职业"));
    model.setHeaderData(0, Qt::Horizontal, QObject::tr("收入"));
    QFile file("test.txt");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString line;
        model.removeRows(0, model.rowCount(QModelIndex()), QModelIndex());
        int row = 0;
        do {
            line = stream.readLine();
            if (!line.isEmpty()) {
                model.insertRows(row, 1, QModelIndex());
                QStringList pieces = line.split(",", QString::SkipEmptyParts);
                model.setData(model.index(row, 0, QModelIndex()), pieces.value(0));
                model.setData(model.index(row, 1, QModelIndex()), pieces.value(1));
                model.setData(model.index(row, 2, QModelIndex()), pieces.value(2));
                model.setData(model.index(row, 3, QModelIndex()), pieces.value(3));
                row++;
            }
        } while (!line.isEmpty());
        file.close();
    }

    table.setWindowTitle(QObject::tr("Delegate"));
    table.resize(600, 400);
    table.show();
    //MainWindow w;
    //w.show();
    return a.exec();
}
