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

void MainWindow::imgProc()
{
    int METHOD = cv::TM_CCOEFF;
    cv::Mat imgSrc = myImg;
    cv::Mat imgFish = cv::imread("fish.jpg");

    cv::Mat imgRes;
    cv::Mat imgDisplay;
    imgSrc.copyTo(imgDisplay);

    int rescols = imgSrc.cols - imgFish.cols + 1;
    int resrows = imgSrc.rows - imgFish.rows + 1;

    imgRes.create(rescols, resrows, 1);
    cv::matchTemplate(imgSrc, imgFish, imgRes, METHOD);
    cv::normalize(imgRes, imgRes, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    double minVal;
    double maxVal;
    cv::Point minLoc;
    cv::Point maxLoc;
    cv::Point matchLoc;

    cv::minMaxLoc(imgRes, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());

    if (METHOD == cv::TM_SQDIFF || METHOD == cv::TM_SQDIFF_NORMED) {
        matchLoc = minLoc;
    } else {
        matchLoc = maxLoc;
    }

    cv::rectangle(imgDisplay,
                  matchLoc,
                  cv::Point(matchLoc.x + imgFish.cols, matchLoc.y + imgFish.rows), cv::Scalar::all(0),
                  2, 8, 0);

    cv::rectangle(imgRes,
                  matchLoc,
                  cv::Point(matchLoc.x + imgFish.cols, matchLoc.y + imgFish.rows), cv::Scalar::all(0),
                  2, 8, 0);
    myQimg = QImage((const unsigned char*)(imgDisplay.data), imgDisplay.cols, imgDisplay.rows, QImage::Format_BGR888);
    imgShow();

}

void MainWindow::on_btnFind_clicked()
{
    imgProc();
}
