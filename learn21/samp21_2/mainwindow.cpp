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
    myImg = cv::imread("test.jpg");
    imgProc();
}


void MainWindow::imgShow()
{
    ui->labBlurView->setPixmap(QPixmap::fromImage(myBlurImg.scaled(ui->labBlurView->size(), Qt::KeepAspectRatio)));
    ui->labGaussianView->setPixmap(QPixmap::fromImage(myGaussianImg.scaled(ui->labGaussianView->size(), Qt::KeepAspectRatio)));
    ui->labMedianView->setPixmap(QPixmap::fromImage(myMedianImg.scaled(ui->labMedianView->size(), Qt::KeepAspectRatio)));
    ui->labBilateralView->setPixmap(QPixmap::fromImage(myBilateralImg.scaled(ui->labBilateralView->size(), Qt::KeepAspectRatio)));
}


void MainWindow::imgProc()
{
    cv::Mat imgSrc = myImg;

    // 均值滤波
    cv::Mat dstBlur = imgSrc.clone();
    for (int i = 1; i < 10; i = i + 2) cv::blur(imgSrc, dstBlur, cv::Size(i, i), cv::Point(-1, -1));
    myBlurImg = QImage((const unsigned char *)(dstBlur.data), dstBlur.cols, dstBlur.rows, QImage::Format_RGB888);

    // 高斯滤波
    cv::Mat dstGaussian = imgSrc.clone();
    for (int i = 1; i < 10; i = i + 2) cv::GaussianBlur(imgSrc, dstGaussian, cv::Size(i, i), 0, 0);
    myGaussianImg = QImage((const unsigned char *)(dstGaussian.data), dstGaussian.cols, dstGaussian.rows, QImage::Format_RGB888);

    // 中值滤波
    cv::Mat dstMedian = imgSrc.clone();
    for (int i = 1; i < 10; i = i + 2) cv::medianBlur(imgSrc, dstMedian, i);
    myMedianImg = QImage((const unsigned char *)(dstMedian.data), dstMedian.cols, dstMedian.rows, QImage::Format_RGB888);

    // 双边滤波
    cv::Mat dstBilateral = imgSrc.clone();
    for (int i = 1; i < 10; i = i + 2) cv::bilateralFilter(imgSrc, dstBilateral, i, i * 2, i / 2);
    myBilateralImg = QImage((const unsigned char *)(dstBilateral.data), dstBilateral.cols, dstBilateral.rows, QImage::Format_RGB888);

    imgShow();
}
