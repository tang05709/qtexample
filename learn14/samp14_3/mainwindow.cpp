#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myWord = new QAxObject("Word.Application");
    myDocs = myWord->querySubObject("Documents");
    myDocs->dynamicCall("Open(const QString&)", "F:/work/qtpro/qt5examples/learn14/samp14_3/gaokao.docx");
    document = myWord->querySubObject("ActiveDocument");
    // 获取第一个表格
    myTable = document->querySubObject("Tables(int)", 1);
    // 获取表格总行数
    int rows = myTable->querySubObject("Rows")->dynamicCall("Count").toInt();
    for (int i = 2; i < rows + 1; i++) {
        QAxObject *headcol = myTable->querySubObject("Cell(int, int)", i , 0);
        if (headcol == NULL) {
            continue;
        }
        QString yearStr = headcol->querySubObject("Range")->property("Text").toString();
        ui->comboBox->addItem(yearStr);
        if (i == rows) {
            ui->comboBox->setCurrentText(yearStr);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    int rows = myTable->querySubObject("Rows")->dynamicCall("Count").toInt();
    for (int i = 2; i < rows + 1; i++) {
        QAxObject *headcol = myTable->querySubObject("Cell(int, int)", i , 0);
        if (headcol == NULL) {
            continue;
        }
        QString yearStr = headcol->querySubObject("Range")->property("Text").toString();
        if (ui->comboBox->currentText() == yearStr) {
            QAxObject *infocol = myTable->querySubObject("Cell(int,int)", i, 2);
            QString totalStr = infocol->querySubObject("Range")->property("Text").toString();
            ui->leAll->setText(totalStr);
            infocol = myTable->querySubObject("Cell(int,int)", i, 3);
            QString admitStr = infocol->querySubObject("Range")->property("Text").toString();
            ui->leAdmit->setText(admitStr);
            infocol = myTable->querySubObject("Cell(int,int)", i, 4);
            QString tateStr = infocol->querySubObject("Range")->property("Text").toString();
            ui->leRate->setText(tateStr);
            break;
        }
    }
}
