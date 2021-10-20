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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initMainWindow();
    void imgProc();
    void imgShow();

private:
    Ui::MainWindow *ui;

    cv::Mat myImg;
    QImage myBlurImg;
    QImage myGaussianImg;
    QImage myMedianImg;
    QImage myBilateralImg;
};
#endif // MAINWINDOW_H
