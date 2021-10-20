#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

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
    void onTableSelectChange(int row); // 商品信息数据网格与表单联动
    void showCommodityPhoto(); // 显示商品图片
    void loadPreCommodity(); // 加载预售订单页商品名称列表
    void onPreNameComboBoxChange(); // 预售订单页面商品名称与表单联动

private slots:
    void on_tableView_clicked(const QModelIndex &index); // 商品信息网格单击事件

    void on_cmbCategory_2_currentIndexChanged(int index); // 类别与生怕名称联动

    void on_cmbName_currentIndexChanged(int index); // 商品下拉改变

    void on_spbNumber_valueChanged(int arg1); // 数量改变

    void on_btnSell_clicked(); // 预售出售

    void on_btnOrder_clicked(); // 预售下单

    void on_btnUpload_clicked(); // 上传

    void on_btnAdd_clicked(); // 入库

    void on_btnClear_clicked(); // 清仓

private:
    Ui::MainWindow *ui;

    QImage myPicImg;
    QSqlTableModel *commodityModel;
    int myMemberId;
    bool myOrdered;
    int myOrderId;
    float myPaySum;
};

static bool createMySqlConn()
{
    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QMYSQL");
    sqldb.setHostName("127.0.0.1");
    sqldb.setDatabaseName("qtshop");
    sqldb.setUserName("root");
    sqldb.setPassword("123456");
    sqldb.setPort(3306);
    if (!sqldb.open()) {
        QSqlError err = sqldb.lastError();
        QString errStr = err.text();
        QMessageBox::critical(0, QObject::tr("数据库连接失败"), errStr, QMessageBox::Cancel);
        return false;
    }
    return true;

}
#endif // MAINWINDOW_H
