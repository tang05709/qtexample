#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QLabel>
#include <QTableView>
#include <QListWidget>
#include <QFile>
#include <QDomDocument>
#include <QDomNode>
#include <QSqlRelationalTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &factoryTable, const QString &carTable, QFile *carDetails, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addCar();
    void changeFactory(QModelIndex index);
    void delCar();
    void showCarDetails(QModelIndex index);
    void showFactoryProfile(QModelIndex index);
    void on_actAdd_triggered();

    void on_actDelete_triggered();

    void on_qctQuit_triggered();

private:
    Ui::MainWindow *ui;

    QGroupBox *createCarGroupBox();
    QGroupBox *createFactoryGroupBox();
    QGroupBox *createDetailsGroupBox();

    QTableView *tviewCar;
    QTableView *tviewFactory;
    QListWidget *listAttrib;

    QLabel *labProfile;
    QLabel *labTitle;

    void decreaseCarCount(QModelIndex index);
    void getAttribList(QDomNode car);
    QModelIndex indexOfFactory(const QString &factory);
    void readCarData();
    void removeCarFromDatabase(QModelIndex index);
    void removeCarFromFile(int id);
    QDomDocument carData;
    QFile *file;
    QSqlRelationalTableModel *carModel;
    QSqlTableModel *factoryModel;


};
#endif // MAINWINDOW_H
