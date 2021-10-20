#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxObject>
#include <QAxWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef struct record
{
    QString year;
    QString total;
    QString admit;
    QString rate;
} Record;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void viewWord(QString& filename);

private:
    Ui::MainWindow *ui;

    QAxObject *myWord;
    QAxObject *myDocs;
    QAxObject *document;
    QAxObject *myTable;
    QList<Record> myRecord;
    QAxWidget *myWidget;

};
#endif // MAINWINDOW_H
