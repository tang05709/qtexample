#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnOpen_clicked()
{
    QFileDialog fdialog;
    fdialog.setFileMode(QFileDialog::ExistingFile);
    fdialog.setViewMode(QFileDialog::Detail);
    fdialog.setOption(QFileDialog::ReadOnly, true);
    fdialog.setDirectory(QString("F:/work/qtpro/qt5examples/learn14/samp14_2"));
    fdialog.setNameFilter(QString("所有文件(*.*);;Microsoft Excel(*.xlsx);;Microsoft Excel 97-2003(*.xls)"));
    if (fdialog.exec()) {
        QStringList files = fdialog.selectedFiles();
        for (auto fname : files) {
            if (fname.endsWith(".xlsx") || fname.endsWith(".xls")) {
                this->viewExcel(fname);
            } else {
                QMessageBox::information(this, tr("提示"), tr("你选择的不是Excel文件"));
            }
        }
    }

}

void MainWindow::on_btnStatis_clicked()
{
    myExcel = new QAxObject("Excel.Application");
    myWorks = myExcel->querySubObject("WorkBooks");
    myWorks->dynamicCall("Open(const QString&)", "F:/work/qtpro/qt5examples/learn14/samp14_2/gaokao.xlsx");
    workbook = myExcel->querySubObject("ActiveWorkBook");
    mySheets = workbook->querySubObject("Sheets");
    QAxObject *sheet = mySheets->querySubObject("Item(int)", 1);
    QAxObject *cell = sheet->querySubObject("Range(QVariant, QVariant)", "C7");
    // 调用excel内置的公式计算
    cell->dynamicCall("SetValue(const QVariant&)", QVariant("=sum(C2:C6)"));
    cell = sheet->querySubObject("Range(QVariant, QVariant)", "D7");
    cell->dynamicCall("SetValue(const QVariant&)", QVariant("=sum(D2:D6)"));
    workbook->dynamicCall("SaveAs(const QString&)", "F:/work/qtpro/qt5examples/learn14/samp14_2/gaokao.xlsx");
    workbook->dynamicCall("Close()");
    myExcel->dynamicCall("Quit()");
    delete myExcel;
    myExcel = nullptr;
    closeExcel();
    QString fname = "F:/work/qtpro/qt5examples/learn14/samp14_2/gaokao.xlsx";
    viewExcel(fname);
    QMessageBox::information(this, tr("提示"), tr("统计完毕"));

}

void MainWindow::viewExcel(QString &filename)
{
    myWidget = new QAxWidget("Excel.Application", ui->label);
    myWidget->dynamicCall("SetVisible(bool Visible", "false");
    myWidget->setProperty("DisplayAlerts", false);
    myWidget->setGeometry(ui->label->geometry().x() - 130, ui->label->geometry().y() - 50, 450, 200);
    myWidget->setControl(filename);
    myWidget->show();
}

void MainWindow::closeExcel()
{
    if (this->myWidget) {
        myWidget->close();
        myWidget->clear();
        delete myWidget;
        myWidget = nullptr;
    }
}
