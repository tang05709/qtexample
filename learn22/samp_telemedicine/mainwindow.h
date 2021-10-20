#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QFile>
#include <QVariant>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDebug>
#include <QTimer>
#include <QImage>
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
    void ctImgRead(); // 读取ct图片
    void ctImgProc(); // ct图片处理
    void ctImgSave(); // ct处理结果保存
    void ctImgShow(); // ct图片显示
    void ctImgHoughCircles(); // 用霍夫圆算法处理ct图片
    void onTableSelectChange(int row); // 改变数据网格选项联动表单
    void showUserPhoto(); // 加载患者照片

private slots:
    void onTimeOut(); // 定时器

    void on_startPushButton_clicked();

    void on_baseTableView_clicked(const QModelIndex &index);

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;

    cv::Mat myCtImg;  // 缓存ct图片
    cv::Mat myCtGrayImg; // 缓存ct图片灰度图
    QImage myCtQimg; // 保存ct图片
    QSqlTableModel *model; // 访问数据库视图信息的模型
    QSqlTableModel *model_d; // 访问数据库附加信息
    QTimer *myTimer; // 获取当前系统时间

};

static bool createMySqlConn()
{
    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QMYSQL");
    sqldb.setHostName("localhost");
    sqldb.setDatabaseName("patient");
    sqldb.setUserName("root");
    sqldb.setPassword("123456");

    if (!sqldb.open()) {
        QMessageBox::critical(0, QObject::tr("数据库连接失败"), QObject::tr("无法创建数据库连接"), QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query(sqldb);
    QString photoPath = "F:/work/qtpro/qt5examples/learn22/samp_telemedicine/pic640_7.jpg";
    QFile photoFile(photoPath);
    if (photoFile.exists()) {
        QByteArray picdata;
        photoFile.open(QIODevice::ReadOnly);
        picdata = photoFile.readAll();
        photoFile.close();
        QVariant varpic(picdata);
        QString sqlstr = "update user_profile set picture = ?";
        query.prepare(sqlstr);
        query.addBindValue(varpic);
        if (!query.exec()) {
            qDebug() << query.lastError();
            QMessageBox::information(0, QObject::tr("提示"), QObject::tr("照片写入失败"));
        } else {
            QMessageBox::information(0, QObject::tr("提示"), QObject::tr("照片写入成功"));
        }
    }
    sqldb.close();
    return true;

}
#endif // MAINWINDOW_H
