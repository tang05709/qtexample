#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myExcel = new QAxObject("Excel.Application");
    // 获取工作簿集
    myWorks = myExcel->querySubObject("WorkBooks");
    // 添加工作簿
    myWorks->dynamicCall("Add");
    // 获取当前活动工作簿
    workbook = myExcel->querySubObject("ActiveWorkBook");
    // 获取电子表格集
    mySheets = workbook->querySubObject("Sheets");

    myWord = new QAxObject("Word.Application");
    // 获取一个文档
    myDocs = myWord->querySubObject("Documents");
    // 添加一个文档
    myDocs->dynamicCall("Add(void)");
    // 指向当前活动文档
    document = myWord->querySubObject("ActiveDocument");
    // 指向当前选中文本
    paragraph = myWord->querySubObject("Selection");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnExcelWrite_clicked()
{
    // 添加一个表
    mySheets->dynamicCall("Add");
    // 获取当前活动表格
    QAxObject *sheet = workbook->querySubObject("ActiveSheet");
    // 给表格命名
    sheet->setProperty("Name", tr("我爱QT"));
    // 指向c3单元格
    QAxObject *cell = sheet->querySubObject("Range(QVariant, QVariant)", "C3");
    QString inStr = ui->leExcel->text();
    // 向单元格写入内容
    cell->dynamicCall("SetValue(const QVariant&)", QVariant(inStr));

    // 指向第二个表格
    sheet = mySheets->querySubObject("Item(int)", 2);
    sheet->setProperty("Name", "HelloQt");
    cell = sheet->querySubObject("Range(QVariant, QVariant)", "B5");
    cell->dynamicCall("SetValue(const QVariant&)", QVariant("Hello! Qt"));
    workbook->dynamicCall("SaveAd(const QString&)", "f:\\work\\qtexceltest.xls");
    // 关闭工作簿
    workbook->dynamicCall("Close()");
    // 退出进程
    myExcel->dynamicCall("Quit()");
}

void MainWindow::on_btnExcelRead_clicked()
{
    myExcel = new QAxObject("Excel.Application");
    myWorks = myExcel->querySubObject("WorkBooks");
    myWorks->dynamicCall("Open(const QString&)", "f:\\work\\qtexceltest.xls");
    workbook = myExcel->querySubObject("ActiveWorkBook");
    mySheets = workbook->querySubObject("WorkSheets");
    QAxObject *sheet = workbook->querySubObject("Sheets(int)", 1);
    QAxObject *cell = sheet->querySubObject("Range(Qvariant, QVariant)", "C3");
    QString outStr = cell->dynamicCall("Value2()").toString();
    ui->labExcel->setText(outStr);

    sheet = workbook->querySubObject("Sheets(int)", 2);
    cell = sheet->querySubObject("Range(QVariant, QVariant)", "B5");
    outStr = cell->dynamicCall("Value2()").toString();
    workbook->dynamicCall("Close()");
    myExcel->dynamicCall("Quit()");
    ui->btnExcelWrite->setEnabled(true);
    ui->btnExcelRead->setEnabled(false);

}

void MainWindow::on_btnWordWrite_clicked()
{
    QString inStr = ui->leWord->text();
    // 写入文本
    paragraph->dynamicCall("TypeText(const QString&)", "inStr");
    // 写入指定文本
    paragraph->dynamicCall("TypeText(const QVariant&)", QVariant("\nHello QT"));
    document->dynamicCall("SaveAs(const QString&)", "f:\\work\\qtwordtest.doc");

    delete paragraph;
    paragraph = nullptr;
    document->dynamicCall("Close()");
    myWord->dynamicCall("Quit()");
    ui->btnWordWrite->setEnabled(false);
    ui->btnWordRead->setEnabled(true);
}

void MainWindow::on_btnWordRead_clicked()
{
    myWord = new QAxObject("Word.Application");
    myDocs = myWord->querySubObject("Documents");
    myDocs->dynamicCall("Open(const QString&)", "f:\\work\\qtwordtest.doc");
    document = myWord->querySubObject("ActiveDocument");
    paragraph = document->querySubObject("Range()");
    // 读取文本
    QString outStr = paragraph->property("Text").toString();
    ui->labWord->setText(outStr);
    paragraph = document->querySubObject("Range(QVariant, QVariant)", 14, 30);

    outStr = paragraph->property("Text").toString();
    delete paragraph;
    paragraph = nullptr;
    document->dynamicCall("Close()");
    document->dynamicCall("Quit()");
    ui->btnWordWrite->setEnabled(true);
    ui->btnWordRead->setEnabled(false);
}
