#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initMainwindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainwindow()
{
    /*QString imgPath = "test.jpg";
    cv::Mat imgData = cv::imread(imgPath.toLatin1().data());
    cv::cvtColor(imgData, imgData, cv::COLOR_BGR2GRAY);
    myImg = imgData;
    myQimg = QImage((const unsigned char*)(imgData.data), imgData.cols, imgData.rows, QImage::Format_RGB888);
    imgShow();*/
    myImg = cv::imread("test.jpg");
    myQimg = QImage((const unsigned char*)(myImg.data), myImg.cols, myImg.rows, myImg.step, QImage::Format_RGB888);
    imgShow();
}

void MainWindow::imgShow()
{
    ui->labView->setPixmap(QPixmap::fromImage(myQimg.scaled(ui->labView->size(), Qt::KeepAspectRatio)));
}

void MainWindow::imgProc(float contrast, int bright)
{
    cv::Mat imgSrc = myImg;
    cv::Mat imgDst = cv::Mat::zeros(imgSrc.size(), imgSrc.type());
    imgSrc.convertTo(imgDst, -1, contrast, bright);
    myQimg = QImage((const unsigned char*)(imgDst.data), imgDst.cols, imgDst.rows, QImage::Format_RGB888);
    imgShow();
}


void MainWindow::on_sliderContrast_sliderMoved(int position)
{
    imgProc(position / 33.3, 0);
}

void MainWindow::on_sliderContrast_valueChanged(int value)
{
    imgProc(value / 33.3, 0);
}

void MainWindow::on_sliderBright_sliderMoved(int position)
{
    imgProc(1.0, position);
}

void MainWindow::on_sliderBright_valueChanged(int value)
{
    imgProc(1.0, value);
}
