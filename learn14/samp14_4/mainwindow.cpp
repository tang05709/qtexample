#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myWord = new QAxObject("Word.Application");
    myDocs = myWord->querySubObject("Documents");
    myDocs->dynamicCall("Open(const QString&)", "F:/work/qtpro/qt5examples/learn14/samp14_4/gaokao.docx");
    document = myWord->querySubObject("ActiveDocument");
    myTable = document->querySubObject("Tables(int)", 1);
    int rows = myTable->querySubObject("Rows")->dynamicCall("Count").toInt();

    for (int i = rows - 4; i < rows + 1; i++) {
        Record oneRec;
        QAxObject *infocol = myTable->querySubObject("Cell(int,int)", i, 1);
        QString yearStr = infocol->querySubObject("Range")->property("Text").toString();
        oneRec.year = yearStr;
        infocol = myTable->querySubObject("Cell(int,int)", i, 2);
        QString totalStr = infocol->querySubObject("Range")->property("Text").toString();
        oneRec.total = totalStr;
        infocol = myTable->querySubObject("Cell(int,int)", i, 3);
        QString admitStr = infocol->querySubObject("Range")->property("Text").toString();
        oneRec.admit = admitStr;
        infocol = myTable->querySubObject("Cell(int,int)", i, 4);
        QString rateStr = infocol->querySubObject("Range")->property("Text").toString();
        oneRec.rate = rateStr;
        myRecord.append(oneRec);
    }
    delete myTable;
    myTable = nullptr;
    document->dynamicCall("Close()");
    myWord->dynamicCall("Quit()");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    myWord = new QAxObject("Word.Application");
    myDocs = myWord->querySubObject("Documents");
    myDocs->dynamicCall("Add(void)");
    document = myWord->querySubObject("ActiveDocument");
    QAxObject *tables = document->querySubObject("Tables");
    // 文本段指针
    QAxObject *paragraph = myWord->querySubObject("Selection");
    paragraph->dynamicCall("TypeText(const QString&)", "历年高考录取人数及录取率");
    QAxObject *range = paragraph->querySubObject("Range");
    QVariantList paras;
    paras.append(range->asVariant());
    paras.append(6); // 创建表格为6行
    paras.append(4); // 创建表格为4列
    tables->querySubObject("Add(QAxObject*,int,int,QVariant&,QVariant&)", paras);
    myTable = paragraph->querySubObject("Tables(int)", 1);
    myTable->setProperty("Style", "网格型");
    QAxObject *borders = myTable->querySubObject("Borders");
    borders->setProperty("InsideLineStyle", 1);
    borders->setProperty("OutSideLineStyle", 1);
    QAxObject *cell;
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            for (int j = 0; j < 4; j++) {
                cell = myTable->querySubObject("Cell(int,int)", (i+1), (j+1))->querySubObject("Range");
                switch (j) {
                case 0:cell->setProperty("Text", "年份");break;
                case 1: cell->setProperty("Text", "高考人数(万)");break;
                case 2: cell->setProperty("Text", "录取人数(万)");break;
                case 3: cell->setProperty("Text", "录取率");break;
                default: break;
                }
            }
            continue;
        }
        for (int j = 0; j < 4; j++) {
            cell = myTable->querySubObject("Cell(int,int)", (i+1), (j+1))->querySubObject("Range");
            switch (j) {
            case 0:cell->setProperty("Text", myRecord[i-1].year);break;
            case 1: cell->setProperty("Text", myRecord[i-1].total);break;
            case 2: cell->setProperty("Text", myRecord[i-1].admit);break;
            case 3: cell->setProperty("Text", myRecord[i-1].rate);break;
            default: break;
            }
        }
    }
    document->dynamicCall("SaveAs(const QString&)", "F:/work/qtpro/qt5examples/learn14/samp14_4/gaokao2.doc");
    delete myTable;
    myTable = nullptr;
    delete paragraph;
    paragraph = nullptr;
    document->dynamicCall("Close()");
    myWord->dynamicCall("Quit()");
    QString fname ="F:/work/qtpro/qt5examples/learn14/samp14_4/gaokao2.doc";
    viewWord(fname);
}

void MainWindow::viewWord(QString &filename)
{
    myWidget = new QAxWidget("Word.Application", ui->label);
    myWidget->dynamicCall("SetVisible(bool Visible)", "false");
    myWidget->setProperty("DisplayAlerts", false);
    myWidget->setGeometry(ui->label->geometry().x() - 10, ui->label->geometry().y() - 70, 600, 380);
    myWidget->setControl(filename);
    myWidget->show();
}
