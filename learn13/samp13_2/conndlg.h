#ifndef CONNDLG_H
#define CONNDLG_H

#include <QDialog>

class QSqlError;
namespace Ui {
class ConnDlg;
}

class ConnDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConnDlg(QWidget *parent = nullptr);
    ~ConnDlg();

    QString driverName() const;
    QString databaseName() const;
    QString userName() const;
    QString password() const;
    QString hostName() const;
    int port() const;
    QSqlError addConnection(
            const QString &driver,
            const QString &dbName,
            const QString &host,
            const QString &user,
            const QString &password,
            int port = -1);
    void createDb();
    void addSqliteConnection();

private slots:
    void driverChanged(const QString&);

    void on_btnConnect_clicked();

private:
    Ui::ConnDlg *ui;
};

#endif // CONNDLG_H
