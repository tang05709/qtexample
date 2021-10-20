#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <vector>
#include <QBuffer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();

    // 基本信息
    model = new QSqlTableModel(this);
    model->setTable("basic_inf");
    model->select();

    // 附加信息
    model_d = new QSqlTableModel(this);
    model_d->setTable("details_inf");
    model_d->select();

    ui->baseTableView->setModel(model);
    onTableSelectChange(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{

    myCtImg = cv::imread("image/CT.jpg");
    myCtQimg = QImage((const unsigned char*)(myCtImg.data), myCtImg.cols, myCtImg.rows, QImage::Format_BGR888);
    ctImgShow();

    // 时间更新
    QDate date = QDate::currentDate();
    int year = date.year();
    ui->yearLcdNumber->display(year);
    int month = date.month();
    ui->monthLcdNumber->display(month);
    int day = date.day();
    ui->dayLcdNumber->display(day);

    myTimer = new QTimer();
    myTimer->setInterval(1000); // 设置定时器每隔多少毫秒发送一个timeOut()信号
    myTimer->start();

    // 绑定消息槽函数
    connect(myTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
}

void MainWindow::onTableSelectChange(int row)
{
    int r = 1;
    if (row != 0) {
        r = ui->baseTableView->currentIndex().row();
    }
    QModelIndex index;
    index = model->index(r, 1);
    ui->nameLabel->setText(model->data(index).toString());
    index = model->index(r, 2);
    QString sex = model->data(index).toString();
    (sex.compare("男") == 0) ? ui->maleRadioButton->setChecked(true) : ui->femaleRadioButton->setChecked(true);
    index = model->index(r, 4);
    QDate date;
    int now = date.currentDate().year();
    int bir = model->data(index).toDate().year();
    ui->ageSpinBox->setValue(now - bir);
    index = model->index(r, 3);
    QString ethnic = model->data(index).toString();
    index = model->index(r, 0);
    QString ssn = model->data(index).toString();
    ui->ssnLineEdit->setText(ssn);
    showUserPhoto();
}

void MainWindow::showUserPhoto()
{
    QPixmap photo;
    QModelIndex index;
    for (int i = 0; i < model_d->rowCount(); i++) {
        index = model_d->index(i, 0);
        QString current_name = model_d->data(index).toString();
        if (current_name.compare(ui->nameLabel->text()) == 0) {
            index = model_d->index(i, 2);
            break;
        }
    }
    photo.loadFromData(model_d->data(index).toByteArray(), "JPG");
    ui->photoLabel->setPixmap(photo);
}

void MainWindow::onTimeOut()
{
    QTime time = QTime::currentTime();
    ui->timeEdit->setTime(time);
}

void MainWindow::ctImgRead()
{
    QString ctImgName = QFileDialog::getOpenFileName(this, "载入ct图片", ".", "Image File(*.png *.jpg *.jpeg *.bmp)");
    if (ctImgName.isEmpty()) return;

    cv::Mat ctImg = cv::imread(ctImgName.toStdString());
    myCtImg = ctImg;
    myCtQimg = QImage((const unsigned char*)(myCtImg.data), myCtImg.cols, myCtImg.rows, QImage::Format_BGR888);
    ctImgShow();
}

void MainWindow::ctImgProc()
{
    QTime time;
    time.start();
    ui->progressBar->setValue(19);
    while (time.elapsed() < 2000) {
        QCoreApplication::processEvents();
    }

    ctImgShow();
    while (time.elapsed() < 2000) {
        QCoreApplication::processEvents();
    }
    ui->progressBar->setValue(ui->progressBar->maximum());
    QMessageBox::information(this, tr("完毕"), tr("子宫内壁见椭圆形阴影"));

}

void MainWindow::ctImgSave()
{
    QFile image("f:\\work\\tumor_1.jpg");
    if (!image.open(QIODevice::ReadOnly)) return;
    QByteArray qba;
    QBuffer buf(&qba);
    buf.open(QIODevice::WriteOnly);
    myCtQimg.save(&buf, "JPG");


    image.write(qba);
}

void MainWindow::ctImgShow()
{
    ui->CT_img_Label->setPixmap(QPixmap::fromImage(myCtQimg.scaled(ui->CT_img_Label->size(), Qt::KeepAspectRatio)));
}

void MainWindow::ctImgHoughCircles()
{
    cv::cvtColor(myCtImg, myCtGrayImg, cv::COLOR_RGB2GRAY);
    cv::GaussianBlur(myCtGrayImg, myCtGrayImg, cv::Size(9, 9), 2, 2);
    std::vector<cv::Vec3f> h_circles;
    cv::HoughCircles(myCtGrayImg, h_circles, cv::HOUGH_GRADIENT, 2, myCtGrayImg.rows / 8, 200, 100);

    int processValue = 45;
    ui->progressBar->setValue(processValue);

    QTime time;
    time.start();
    while (time.elapsed() < 2000) {
        QCoreApplication::processEvents();
    }
    for (size_t i = 0; i < h_circles.size(); i++) {
        cv::Point center(cvRound(h_circles[i][0]), cvRound(h_circles[i][1]));
        int h_radius = cvRound(h_circles[i][2]);
        cv::circle(myCtImg, center, h_radius, cv::Scalar(238, 0, 238), 3, 8, 0);
        cv::circle(myCtImg, center, 3, cv::Scalar(238, 0, 0), -1, 8, 0);
        processValue += 1;
        ui->progressBar->setValue(processValue);
    }

}

void MainWindow::on_startPushButton_clicked()
{
    ctImgRead();
    QTime time;
    time.start();
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
    while (time.elapsed() < 5000) {
        QCoreApplication::processEvents(); // 处理事件以保持界面刷新
    }
    ui->progressBar->setMaximum(100);
    ui->progressBar->setMinimum(0);
    ctImgProc();
    ui->progressBar->setValue(0);
    ctImgSave();
}

void MainWindow::on_baseTableView_clicked(const QModelIndex &index)
{
    onTableSelectChange(1);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if (index == 1) {
        QModelIndex index;
        for (int i = 0; i < model_d->rowCount(); i++) {
            index = model_d->index(i, 0);
            QString current_name = model_d->data(index).toString();
            if (current_name.compare(ui->nameLabel->text()) == 0) {
                index = model_d->index(i, 2);
                break;
            }
        }
        ui->caseTextEdit->setText(model_d->data(index).toString());
    }
}

