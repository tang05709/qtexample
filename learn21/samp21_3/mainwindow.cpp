#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    myImg = cv::imread("test123.jpg");
    myQimg = QImage((const unsigned char*)(myImg.data), myImg.cols, myImg.rows, QImage::Format_BGR888);
    imgShow();
}

void MainWindow::imgShow()
{
    ui->labView->setPixmap(QPixmap::fromImage(myQimg.scaled(ui->labView->size(), Qt::KeepAspectRatio)));
}

void MainWindow::imgProc(float alpha)
{
    cv::Mat myImg2 = cv::imread("test456.jpg");
    cv::Mat myDst;
    cv::addWeighted(myImg2, alpha, myImg, 1 - alpha, 0, myDst);
    myQimg = QImage((const unsigned char*)(myDst.data), myDst.cols, myDst.rows, QImage::Format_BGR888);
    imgShow();
}

void MainWindow::on_slider_sliderMoved(int position)
{
    imgProc(position / 100.0);
}

void MainWindow::on_slider_valueChanged(int value)
{
    imgProc(value / 100.0);
}
