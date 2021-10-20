#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btnExcelWrite_clicked();

    void on_btnExcelRead_clicked();

    void on_btnWordWrite_clicked();

    void on_btnWordRead_clicked();

private:
    Ui::MainWindow *ui;

    QAxObject *myExcel;
    QAxObject *myWorks;
    QAxObject *workbook;
    QAxObject *mySheets;

    QAxObject *myWord;
    QAxObject *myDocs;
    QAxObject *document;
    QAxObject *paragraph;

};
#endif // MAINWINDOW_H
