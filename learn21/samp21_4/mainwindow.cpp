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
    myQimg = QImage((const unsigned char*)(myImg.data), myImg.cols, myImg.rows, QImage::Format_BGR888);
    imgShow();
}

void MainWindow::imgShow()
{
    ui->labView->setPixmap(QPixmap::fromImage(myQimg.scaled(ui->labView->size(), Qt::KeepAspectRatio)));
}

void MainWindow::imgProc(float angle, float scale)
{
    cv::Point2f srcMatrix[3];
    cv::Point2f dstMatrix[3];

    cv::Mat imgRot;
    cv::Mat imgSrc = myImg;
    cv::Mat imgDst;

    cv::Point centerPoint = cv::Point(imgSrc.cols / 2, imgSrc.rows / 2);
    imgRot = cv::getRotationMatrix2D(centerPoint, angle, scale);
    cv::warpAffine(imgSrc, imgDst, imgRot, imgSrc.size());
    myQimg = QImage((const unsigned char*)(imgDst.data), imgDst.cols, imgDst.rows, QImage::Format_BGR888);
    imgShow();
}



void MainWindow::on_sliderScale_sliderMoved(int position)
{
    imgProc(float(ui->sliderRotate->value() - 360), position / 100.0);
}

void MainWindow::on_sliderScale_valueChanged(int value)
{
    imgProc(float(ui->sliderRotate->value() - 360), value / 100.0);
}

void MainWindow::on_sliderRotate_sliderMoved(int position)
{
     imgProc(float(position - 360), ui->sliderScale->value() / 100.0);
}

void MainWindow::on_sliderRotate_valueChanged(int value)
{
    imgProc(float(value - 360), ui->sliderScale->value() / 100.0);
}
