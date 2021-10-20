#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnFileName_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开"), "/", "files(*)");
    ui->leFileName->setText(fileName);
}

void Widget::on_btnGetInfo_clicked()
{
    QString file = ui->leFileName->text();
    QFileInfo info(file);
    qint64 size = info.size();
    QDateTime created = info.birthTime();
    QDateTime lastModified = info.lastModified();
    QDateTime lastVisited = info.lastRead();

    bool isDir = info.isDir();
    bool isFile = info.isFile();
    bool isSymLink = info.isSymLink();
    bool isHidden = info.isHidden();
    bool isReadable = info.isReadable();
    bool isWriteable = info.isWritable();
    bool isExecutable = info.isExecutable();

    ui->leSize->setText(QString::number(size));
    ui->leCreateTime->setText(created.toString());
    ui->leModifyTime->setText(lastModified.toString());
    ui->leVisitTime->setText(lastVisited.toString());
    ui->chkDir->setChecked(isDir);
    ui->chkFile->setChecked(isFile);
    ui->chkLink->setChecked(isSymLink);
    ui->chkHide->setChecked(isHidden);
    ui->chkRead->setChecked(isReadable);
    ui->chkWrite->setChecked(isWriteable);
    ui->chkExec->setChecked(isExecutable);
}
