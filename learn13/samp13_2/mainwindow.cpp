#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDebug>
#include "editdialog.h"
extern int uniqueFactoryId;
extern int uniqueCarId;

MainWindow::MainWindow(const QString &factoryTable, const QString &carTable, QFile *carDetails, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("主从视图"));

    file = carDetails;
    readCarData();
    carModel = new QSqlRelationalTableModel(this);
    carModel->setTable(carTable);
    carModel->setRelation(2, QSqlRelation(factoryTable, "id", "manufactory"));
    carModel->select();
    qDebug() << carModel->rowCount();
    factoryModel = new QSqlTableModel(this);
    factoryModel->setTable(factoryTable);
    factoryModel->select();

    QGroupBox *factory = createFactoryGroupBox();
    QGroupBox *cars = createCarGroupBox();
    QGroupBox *details = createDetailsGroupBox();

    uniqueFactoryId = factoryModel->rowCount();
    uniqueCarId = carModel->rowCount();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(factory, 0, 0);
    layout->addWidget(cars, 1, 0);
    layout->addWidget(details, 0, 1, 2, 1);
    layout->setColumnStretch(1, 1);
    layout->setColumnMinimumWidth(0, 500);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);

    resize(850, 400);


}

MainWindow::~MainWindow()
{
    delete ui;
}

QGroupBox* MainWindow::createFactoryGroupBox()
{
    tviewFactory = new QTableView;
    tviewFactory->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tviewFactory->setSortingEnabled(true);
    tviewFactory->setSelectionBehavior(QAbstractItemView::SelectRows);
    tviewFactory->setSelectionMode(QAbstractItemView::SingleSelection);
    tviewFactory->setShowGrid(false);
    tviewFactory->setAlternatingRowColors(true);

    tviewFactory->setModel(factoryModel);
    connect(tviewFactory, SIGNAL(clicked(QModelIndex)), this, SLOT(changeFactory(QModelIndex)));

    QGroupBox *box = new QGroupBox(tr("汽车制造商"));
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(tviewFactory, 0, 0);
    box->setLayout(layout);
    return box;
}

QGroupBox* MainWindow::createCarGroupBox()
{
    tviewCar = new QTableView;
    tviewCar->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tviewCar->setSortingEnabled(true);
    tviewCar->setSelectionBehavior(QAbstractItemView::SelectRows);
    tviewCar->setSelectionMode(QAbstractItemView::SingleSelection);
    tviewCar->setShowGrid(false);
    //tviewCar->verticalHeader()->hide();
    tviewCar->setAlternatingRowColors(true);

    tviewCar->setModel(carModel);
    connect(tviewCar, SIGNAL(clicked(QModelIndex)), this, SLOT(showCarDetails(QModelIndex)));
    connect(tviewCar, SIGNAL(activated(QModelIndex)), this, SLOT(showCarDetails(QModelIndex)));

    QGroupBox *box = new QGroupBox(tr("汽车"));
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(tviewCar, 0, 0);
    box->setLayout(layout);
    return box;
}

QGroupBox* MainWindow::createDetailsGroupBox()
{
     QGroupBox *box = new QGroupBox(tr("详细信息"));
     labProfile = new QLabel;
     labProfile->setWordWrap(true);
     labProfile->setAlignment(Qt::AlignBottom);

     labTitle = new QLabel;
     labTitle->setWordWrap(true);
     labTitle->setAlignment(Qt::AlignBottom);

     listAttrib = new QListWidget;

     QGridLayout *layout = new QGridLayout;
     layout->addWidget(labProfile, 0, 0, 1, 2);
     layout->addWidget(labTitle, 1, 0, 1, 2);
     layout->addWidget(listAttrib, 2, 0, 1, 2);
     layout->setRowStretch(2, 1);
     box->setLayout(layout);
     return box;
}


void MainWindow::changeFactory(QModelIndex index)
{
    QSqlRecord record = factoryModel->record(index.row());
    //QString factoryId = record.value("id").toString();
    //carModel->setFilter("factoryid='"+factoryId+"'");
    int factoryId = record.value("id").toInt();
    carModel->setFilter(QString("factoryid=%1").arg(factoryId));
    showFactoryProfile(index);
}

void MainWindow::showFactoryProfile(QModelIndex index)
{
    QSqlRecord record = factoryModel->record(index.row());
    QString name = record.value("manufactory").toString();
    int count = carModel->rowCount();
    labProfile->setText(tr("汽车制造商：%1\n产品数量：%2").arg(name).arg(count));
    labProfile->show();
    labTitle->hide();
    listAttrib->hide();
}

void MainWindow::showCarDetails(QModelIndex index)
{
    QSqlRecord record = carModel->record(index.row());
    QString factory = record.value("manufactory").toString();
    QString name = record.value("name").toString();
    QString year = record.value("year").toString();
    QString carId = record.value("carid").toString();

    showFactoryProfile(indexOfFactory(factory));

    labTitle->setText(tr("品牌：%1 (%2)").arg(name).arg(year));
    labTitle->show();

    QDomNodeList cars = carData.elementsByTagName("car");
    for (int i = 0; i < cars.count(); i++) {
        QDomNode car = cars.item(i);
        if (car.toElement().attribute("id") == carId) {
            getAttribList(car.toElement());
            break;
        }
    }
    if (listAttrib->count() > 0) {
        listAttrib->show();
    }
}

void MainWindow::getAttribList(QDomNode car)
{
    listAttrib->clear();
    QDomNodeList attribs = car.childNodes();
    QDomNode node;
    QString attribNumber;
    for (int j = 0; j < attribs.count(); j++) {
        node = attribs.item(j);
        attribNumber = node.toElement().attribute("number");
        QListWidgetItem *item = new QListWidgetItem(listAttrib);
        QString showText(attribNumber + ": " + node.toElement().text());
        item->setText(tr("%1").arg(showText));
    }
}

void MainWindow::delCar()
{
    QModelIndexList selection = tviewCar->selectionModel()->selectedRows(0);
    if (!selection.empty()) {
        QModelIndex idIndex = selection.at(0);
        int id = idIndex.data().toInt();
        QString name = idIndex.sibling(idIndex.row(), 1).data().toString();
        QString factory = idIndex.sibling(idIndex.row(), 2).data().toString();
        QMessageBox::StandardButton button;
        button = QMessageBox::question(
                    this,
                    tr("删除汽车记录"),
                    QString(tr("确认删除由%1生产的%2么？").arg(factory).arg(name)),
                    QMessageBox::Yes | QMessageBox::No);
        if (button == QMessageBox::Yes) {
            removeCarFromFile(id);
            removeCarFromDatabase(idIndex);
            decreaseCarCount(indexOfFactory(factory));
        } else {
            QMessageBox::information(this, tr("删除汽车记录"), tr("请选择要删除的记录"));
        }
    }

}

void MainWindow::removeCarFromFile(int id)
{
    QDomNodeList cars = carData.elementsByTagName("car");
    for (int i = 0; i < cars.count(); i++) {
        QDomNode node = cars.item(i);
        if (node.toElement().attribute("id").toInt() == id) {
            carData.elementsByTagName("archive").item(0).removeChild(node);
            break;
        }
    }
}

void MainWindow::removeCarFromDatabase(QModelIndex index)
{
    carModel->removeRow(index.row());
}

void MainWindow::decreaseCarCount(QModelIndex index)
{
    int row = index.row();
    int count = carModel->rowCount();
    if (count == 0) {
        factoryModel->removeRow(row);
    }
}

void MainWindow::addCar()
{
    EditDialog *dialog = new EditDialog(carModel, factoryModel, carData, file, this);
    int accepted = dialog->exec();
    if (accepted == 1) {
        int lastRow = carModel->rowCount() - 1;
        tviewCar->selectRow(lastRow);
        tviewCar->scrollToBottom();
        showCarDetails(carModel->index(lastRow, 0));
    }
}

void MainWindow::readCarData()
{
    if (!file->open(QIODevice::ReadOnly)) {
        return;
    }
    if (!carData.setContent(file)) {
        file->close();
        return;
    }
    file->close();
}

QModelIndex MainWindow::indexOfFactory(const QString &factory)
{
    for (int i = 0; i < factoryModel->rowCount(); i++) {
        QSqlRecord record = factoryModel->record(i);
        if (record.value("manufactory") == factory) {
            return factoryModel->index(i, 1);
        }
    }
    return QModelIndex();
}



void MainWindow::on_actAdd_triggered()
{
    addCar();
}

void MainWindow::on_actDelete_triggered()
{
    delCar();
}

void MainWindow::on_qctQuit_triggered()
{
    close();
}
