#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initMainWindow();
    void imgProc();
    void imgShow();


private slots:
    void on_btnFind_clicked();

private:
    Ui::MainWindow *ui;

    cv::Mat myImg;
    QImage myQimg;
};
#endif // MAINWINDOW_H
