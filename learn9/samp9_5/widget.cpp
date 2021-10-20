#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString root = "/";
    QDir rootDir(root);
    QStringList str;
    str << "*";
    QFileInfoList flist = rootDir.entryInfoList(str);
    showFileInfoList(flist);

    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(slotShow(QDir)));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slotDirShow(QListWidgetItem*)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showFileInfoList(QFileInfoList list)
{
    ui->listWidget->clear();
    for (int i = 0; i < list.count(); i++) {
        QFileInfo tmpFileInfo = list.at(i);
        if (tmpFileInfo.isDir()) {
            QIcon icon(":/images/dir.png");
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon, fileName);
            ui->listWidget->addItem(tmp);
        } else if (tmpFileInfo.isFile()) {
            QIcon icon(":/images/file.png");
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon, fileName);
            ui->listWidget->addItem(tmp);
        }
    }
}


void Widget::slotShow(QDir dir)
{
    QStringList str;
    str << "*";
    QFileInfoList flist = dir.entryInfoList(str, QDir::AllEntries, QDir::DirsFirst);
    showFileInfoList(flist);
}

void Widget::slotDirShow(QListWidgetItem *item)
{
    QString str = item->text();
    QDir dir;
    dir.setPath(ui->lineEdit->text());
    dir.cd(str);
    ui->lineEdit->setText(dir.absolutePath());
    slotShow(dir);
}
