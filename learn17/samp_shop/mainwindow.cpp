#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QFileDialog>
#include <QTime>

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
    ui->stackedWidget->setCurrentIndex(1); // 置商品管理于主页
    ui->toolBox->setCurrentIndex(0); // 新品入库显示在前面
    QSqlQueryModel *categoryModel = new QSqlQueryModel(this);
    categoryModel->setQuery("select name from category");
    ui->cmbNewCategory->setModel(categoryModel);
    ui->cmbPreCategory->setModel(categoryModel);

    commodityModel = new QSqlTableModel(this);
    commodityModel->setTable("commodify_inf");
    commodityModel->select();
    ui->tableView->setModel(commodityModel);

    loadPreCommodity();
    myMemberId = 0;
    myOrderId = 0;
    myOrdered = false;
    myPaySum = 0;
    QListWidgetItem *title = new QListWidgetItem;
    title->setText(QString("当前订单[编号：%1]").arg(myOrderId));
    title->setTextAlignment(Qt::AlignCenter);

}

void MainWindow::onTableSelectChange(int row)
{
    int r = 1;
    if (row != 0) r = ui->tableView->currentIndex().row();
    QModelIndex index;
    index = commodityModel->index(r, 0);
    ui->leNewName->setText(commodityModel->data(index).toString());
    index = commodityModel->index(r, 1);
    ui->leNewInPrice->setText(commodityModel->data(index).toString());
    index = commodityModel->index(r, 2);
    ui->leNewOutPrice->setText(commodityModel->data(index).toString());

    showCommodityPhoto();
    QSqlQuery query;
    query.exec(QString("select Name from category where CategoryId=(select CategoryId from commodity where Name='%1')").arg(ui->leNewName->text()));
    query.next();
    ui->cmbNewCategory->setCurrentText(query.value(0).toString());
}

void MainWindow::showCommodityPhoto()
{
    QPixmap photo;
    QModelIndex index;
    QSqlQueryModel *pictureModel = new QSqlQueryModel(this);
    QString name = ui->leNewName->text();
    pictureModel->setQuery("select Picture from commodity where Name='"+name+"'");
    index = pictureModel->index(0, 0);
    photo.load(pictureModel->data(index).toString());
    ui->labNewPixmap->setPixmap(photo);
}

void MainWindow::loadPreCommodity()
{
    QSqlQueryModel *commodityNameModel = new QSqlQueryModel(this);
    commodityNameModel->setQuery(QString("select Name from commodity where CategoryId = (select CategoryId from category where Name='%1')")
                                 .arg(ui->cmbPreCategory->currentText()));
    ui->cmbPreName->setModel(commodityNameModel);
    onPreNameComboBoxChange();
}

void MainWindow::onPreNameComboBoxChange()
{
    QSqlQueryModel *preCommodityModel = new QSqlQueryModel(this);
    QString name = ui->cmbPreName->currentText();
    preCommodityModel->setQuery("select OutputPrice, Amount, Picture from commodity where name ='"+name+"'");
    QModelIndex index;
    index = preCommodityModel->index(0, 0);
    ui->labPreSinglePriceNum->setText(preCommodityModel->data(index).toString());
    ui->spbPreNumber->setMaximum(ui->labPreAmount->text().toInt());


    index = preCommodityModel->index(0, 2);
    //QPixmap photo;
    //photo.load(preCommodityModel->data(index).toString());
    // ui->labPrePixmap->setPixmap(photo);
    QImage photo;
    photo.load(preCommodityModel->data(index).toString());
    ui->labPrePixmap->setPixmap(QPixmap::fromImage(photo));

    ui->labPreTotalPriceNum->setText(QString::number(ui->labPreSinglePrice->text().toFloat() * ui->spbPreNumber->value()));
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    onTableSelectChange(1);
}

void MainWindow::on_cmbCategory_2_currentIndexChanged(int index)
{

}

void MainWindow::on_cmbName_currentIndexChanged(int index)
{

}

void MainWindow::on_spbNumber_valueChanged(int arg1)
{

}

void MainWindow::on_btnSell_clicked()
{
    QSqlQuery query;
    if (!myOrdered) {
        query.exec(QString("insert into orders(MemberId, PaySum, PayWay, CreateTime) values(%1, NULL, NULL, NULL)").arg(myMemberId));
        myOrdered = true;
        query.exec(QString("select OrderId from orders where CreateTime is NULL"));
        query.next();
        myOrderId = query.value(0).toInt();
    }
    query.exec(QString("select CommodityId from commodity where Name='%1'").arg(ui->cmbPreName->currentText()));
    query.next();
    int commodityId = query.value(0).toInt();
    int count = ui->spbPreNumber->value();
    int amount = ui->spbPreNumber->maximum() - count;
    QSqlDatabase::database().transaction();// 开启事务
    bool insOk = query.exec(QString("insert into orderitems(OrderId, CommodityId, Count) values(%1, %2, %3)")
                            .arg(myOrderId).arg(myMemberId).arg(count));
    bool uptOk = query.exec(QString("update commodity setAmount=%1 wjere CommodityId = %2").arg(count).arg(commodityId));
    if (insOk && uptOk) {
        QSqlDatabase::database().commit();
        onPreNameComboBoxChange();

        QString curtime = QTime::currentTime().toString("hh:mm:ss");
        QString curname = ui->cmbPreName->currentText();
        QString curcount = QString::number(count, 10);
        QString curoutprice = ui->labPreTotalPrice->text();
        QString curtotal = ui->labPreTotalPriceNum->text();
        myPaySum += curtotal.toFloat();
        QString sellRecord = curtime + " 售出：" + curname + "\r\n 数量：" + curcount + "; 总价：" + curoutprice;
        QListWidgetItem *split = new QListWidgetItem;
        split->setText("-.-.-.-.-.-.-.-.-.-");
        split->setTextAlignment(Qt::AlignCenter);
        ui->listWidget->addItem(split);
        ui->listWidget->addItem(sellRecord);
        ui->btnOrder->setEnabled(true);
    } else {
        QSqlDatabase::database().rollback();
    }

}

void MainWindow::on_btnOrder_clicked()
{
    QSqlQuery query;
    QString createtime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QSqlDatabase::database().transaction();
    bool ordOk = query.exec(QString("update orders set PaySum=%2, CreateTime='%2' where OrderId=%3")
                            .arg(myPaySum).arg(createtime).arg(myOrderId));
    bool uptOk = query.exec(QString("update orderitems set Affirm = 1, SendGoods = 1 where OrderId=%1").arg(myOrderId));
    if (ordOk && uptOk) {
        QSqlDatabase::database().commit();
         ui->btnOrder->setEnabled(false);
         commodityModel->setTable("commodity_inf");
         commodityModel->select();
         ui->tableView->setModel(commodityModel);
    } else {
        QSqlDatabase::database().rollback();
    }

}

void MainWindow::on_btnUpload_clicked()
{
    QString picturename = QFileDialog::getOpenFileName(this, tr("选择图片"), ".", "Image File(*.png *.jpg *.jpeg *.bmp)");
    if (picturename.isEmpty()) {
        return;
    }
    myPicImg.load(picturename);
    ui->labNewPixmap->setPixmap(QPixmap::fromImage(myPicImg));
}

void MainWindow::on_btnAdd_clicked()
{
    QSqlQuery query;
    query.exec(QString("select CategoryId from category where Name='%1'").arg(ui->cmbNewCategory->currentText()));
    query.next();
    int categoryId = query.value(0).toInt();
    QString name = ui->leNewName->text();
    float inputPrice = ui->leNewInPrice->text().toFloat();
    float outputPrice = ui->leNewOutPrice->text().toFloat();
    int count = ui->spbNewAmount->value();
    query.exec(QString("insert into commodity(CategoryId, Name, Picture, InputPrice, OutputPrice, Amount) values(%1, '%2', NULL, %3, %4, %5)")
               .arg(categoryId).arg(name).arg(inputPrice).arg(outputPrice).arg(count));

    commodityModel->setTable("commodity_inf");
    commodityModel->select();
    ui->tableView->setModel(commodityModel);
}

void MainWindow::on_btnClear_clicked()
{
    /*QSqlQuery query;
    query.exec(QString("delete from commodity where Name='%1'").arg(ui->leNewName->text()));
    ui->leNewName->setText("");
    ui->leNewInPrice->setText("");
    ui->leNewOutPrice->setText("");
    ui->spbNewAmount->setValue(0);
    ui->labNewPixmap->clear();
    commodityModel->setTable("commodity_inf");
    commodityModel->select();
    ui->tableView->setModel(commodityModel);*/
}
