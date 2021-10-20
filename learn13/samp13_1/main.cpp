#include "widget.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("qtdb.db");
    db.setUserName("qtdb");
    db.setPassword("123456");
    if (db.open()) {
        qDebug() << "db success";
    } else {
        qDebug() << "db fail";
    }
    QSqlQuery query;
    bool success = query.exec("create table automoile (id int primary key,"
                              "attribute varchar,"
                              "type varchar,"
                              "kind varchar,"
                              "nation int,"
                              "carnumber int,"
                              "elevaltor int,"
                              "distance int,"
                              "uil int,"
                              "temperature int)");
    if (success) {
        qDebug() << "create table success";
    } else {
         qDebug() << "create table fail";
    }
    query.exec("select * from automoile");
    QSqlRecord record = query.record();
    qDebug() << "table attribute conunt: " << record.count();
    QTime t;
    t.start();
    query.prepare("insert into automoile values(?,?,?,?,?,?,?,?,?,?)");
    long records = 100;
    for (int i = 0; i < records; i++) {
        query.bindValue(0, i);
        query.bindValue(1, "四轮");
        query.bindValue(2, "轿车");
        query.bindValue(3, "大巴");
        query.bindValue(4, rand() % 100);
        query.bindValue(5, rand() % 10000);
        query.bindValue(6, rand() % 300);
        query.bindValue(7, rand() % 2000);
        query.bindValue(8, rand() % 52);
        query.bindValue(9, rand() % 100);
        success = query.exec();
        if (!success) {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << " insert fail";
        }
    }
    qDebug() << QObject::tr("insert %1 records, time: %2").arg(records).arg(t.elapsed());

    t.restart();

    success = query.exec("select * from automobile order by id desc");
    qDebug() << QObject::tr("select %1 records, time: %2").arg(records).arg(t.elapsed());


    Widget w;
    w.show();
    return a.exec();
}
