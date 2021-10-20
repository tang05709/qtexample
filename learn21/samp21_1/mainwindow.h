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

    void initMainwindow();
    void imgProc(float contrast, int bright);
    void imgShow();

private slots:
    void on_sliderContrast_sliderMoved(int position);

    void on_sliderContrast_valueChanged(int value);

    void on_sliderBright_sliderMoved(int position);

    void on_sliderBright_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    cv::Mat myImg;
    QImage myQimg;
};
#endif // MAINWINDOW_H
