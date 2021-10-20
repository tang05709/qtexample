#include "conndlg.h"
#include "ui_conndlg.h"
#include <QSqlDatabase>
#include <QtSql>

ConnDlg::ConnDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnDlg)
{
    ui->setupUi(this);
    QStringList drivers = QSqlDatabase::drivers();
    ui->cmbDriver->addItems(drivers);
    connect(ui->cmbDriver, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(driverChanged(const QString&)));
    ui->labStatus->setText(tr("准备连接数据库！"));
}

ConnDlg::~ConnDlg()
{
    delete ui;
}

void ConnDlg::driverChanged(const QString &driver)
{
    if (driver == "QSQLITE") {
        ui->leDatabase->setEnabled(false);
        ui->leUser->setEnabled(false);
        ui->lePassword->setEnabled(false);
        ui->leHost->setEnabled(false);
        ui->spbPort->setEnabled(false);
    } else {
        ui->leDatabase->setEnabled(true);
        ui->leUser->setEnabled(true);
        ui->lePassword->setEnabled(true);
        ui->leHost->setEnabled(true);
        ui->spbPort->setEnabled(true);
    }
}

QString ConnDlg::driverName() const
{
    return ui->cmbDriver->currentText();
}

QString ConnDlg::databaseName() const
{
    return ui->leDatabase->text();
}

QString ConnDlg::userName() const
{
    return ui->leUser->text();
}

QString ConnDlg::password() const
{
    return ui->lePassword->text();
}

QString ConnDlg::hostName() const
{
    return ui->leHost->text();
}

int ConnDlg::port() const
{
    return ui->spbPort->value();
}

void ConnDlg::on_btnConnect_clicked()
{
    if (ui->cmbDriver->currentText().isEmpty()) {
        ui->labStatus->setText(tr("请选择一个数据库驱动"));
        ui->cmbDriver->setFocus();
    } else if (ui->cmbDriver->currentText() == "QSQLITE") {
        addSqliteConnection();
        createDb();
        accept();
    } else {
        QSqlError err = addConnection(
                    driverName(),
                    databaseName(),
                    hostName(),
                    userName(),
                    password(),
                    port());
        if (err.type() != QSqlError::NoError) {
            ui->labStatus->setText(err.text());
        } else {
            ui->labStatus->setText(tr("连接数据库成功"));
            accept();
        }
    }

}


QSqlError ConnDlg::addConnection(const QString &driver, const QString &dbName, const QString &host, const QString &user, const QString &password, int port)
{
    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    if (!db.open(user, password)) {
        err = db.lastError();
    }
    return err;
}

void ConnDlg::addSqliteConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("databasefile");
    if (!db.open()) {
        ui->labStatus->setText(db.lastError().text());
        return;
    }
    ui->labStatus->setText(tr("创建sqlite数据库成功"));
}

void ConnDlg::createDb()
{
    QSqlQuery query;
    query.exec("create table factory (id int primary key, manufactory varchar(40), address varchar(40))");
    query.exec(tr("insert into factory values(1, '一汽大众', '长春')"));
    query.exec(tr("insert into factory values(2, '二汽神龙', '武汉')"));
    query.exec(tr("insert into factory values(3, '上海大众', '上海')"));

    query.exec("create table cars (carid int primary key, name varchar(50), factoryid int, year int, foreign key(factoryid) references factory)");
    query.exec(tr("insert into cars values(1, '奥迪A6', 1, 2005)"));
    query.exec(tr("insert into cars values(2, '捷达', 1, 1993)"));
    query.exec(tr("insert into cars values(3, '宝来', 1, 2000)"));
    query.exec(tr("insert into cars values(4, '毕加索', 2, 1999)"));
    query.exec(tr("insert into cars values(5, '富康', 2, 2004)"));
    query.exec(tr("insert into cars values(6, '标致', 2, 2001)"));
    query.exec(tr("insert into cars values(7, '桑塔纳', 3, 1995)"));
    query.exec(tr("insert into cars values(8, '帕萨特', 3, 2000)"));
}
