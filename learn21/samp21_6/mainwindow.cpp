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

void MainWindow::imgProc()
{
    cv::CascadeClassifier face_detector; // 人脸识别
    cv::CascadeClassifier eyes_detector; // 人眼识别

    std::string faceDetectorPath = "haarcascade_frontalface_alt.xml";
    face_detector.load(faceDetectorPath);
    std::string eyeDetectorPath = "haarcascade_eye_tree_eyeglasses.xml";
    eyes_detector.load(eyeDetectorPath);

    std::vector<cv::Rect> faces;
    cv::Mat imgSrc = myImg;
    cv::Mat imgGray;
    cvtColor(imgSrc, imgGray, cv::COLOR_BGRA2GRAY);
    cv::equalizeHist(imgGray, imgGray);
    // CV_HAAR_SCALE_IMAGE 没识别出来，暂时用2代替
    face_detector.detectMultiScale(imgGray, faces, 1.1, 2, 0 | 2, cv::Size(30, 30));

    for (int i = 0; i < faces.size(); i++) {
        cv::Point center(
                    faces[i].x + faces[i].width * 0.5,
                    faces[i].y + faces[i].height * 0.5);
        cv::ellipse(
                    imgSrc,
                    center,
                    cv::Size(faces[i].width * 0.5, faces[i].height * 0.5),
                    0, 0, 360,
                    cv::Scalar(255, 0, 255),
                    4, 8, 0);
        cv::Mat faceROI = imgGray(faces[i]);
        std::vector<cv::Rect> eyes;
        // CV_HAAR_SCALE_IMAGE 没识别出来，暂时用2代替
        eyes_detector.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | 2, cv::Size(30, 30));
        for (int j = 0; j < eyes.size(); j++) {
            cv::Point center(
                        faces[i].x + eyes[j].width * 0.5,
                        faces[i].y + eyes[j].height * 0.5
                        );
            int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
            cv::circle(imgSrc, center, radius, cv::Scalar(255, 0, 0), 4, 8, 0);
        }
    }
    cv::Mat imgDst = imgSrc;
    myQimg = QImage((const unsigned char*)(imgDst.data), imgDst.cols, imgDst.rows, QImage::Format_BGR888);
    imgShow();
}

void MainWindow::on_btnDetect_clicked()
{
    imgProc();
}
