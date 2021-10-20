#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxObject>
#include <QAxWidget>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeExcel();

private slots:
    void on_btnOpen_clicked();

    void on_btnStatis_clicked();

    void viewExcel(QString& filename);

private:
    Ui::MainWindow *ui;

    QAxObject *myExcel;
    QAxObject *myWorks;
    QAxObject *workbook;
    QAxObject *mySheets;
    QAxWidget *myWidget;


};
#endif // MAINWINDOW_H
