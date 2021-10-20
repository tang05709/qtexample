#include "progressdlg.h"
#include <QProgressDialog>

ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Progress"));

    labFileNum = new QLabel(tr("文件数目"));
    leFileNum = new QLineEdit;
    leFileNum->setText(tr("100000"));

    labProgressType = new QLabel(tr("显示类型"));
    comboBox = new QComboBox;
    comboBox->addItem(tr("ProgressBar"));
    comboBox->addItem(tr("ProgressDialog"));
    progressBar = new QProgressBar;

    btnStart = new QPushButton(tr("开始"));

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(labFileNum, 0, 0);
    mainLayout->addWidget(leFileNum, 0, 1);
    mainLayout->addWidget(labProgressType, 1, 0);
    mainLayout->addWidget(comboBox, 1, 1);
    mainLayout->addWidget(progressBar, 2, 0, 1, 2);
    mainLayout->addWidget(btnStart, 3, 1);

    connect(btnStart, SIGNAL(clicked()), this, SLOT(startProgress()));
}

ProgressDlg::~ProgressDlg()
{
}

void ProgressDlg::startProgress()
{
    bool ok = false;
    int num = leFileNum->text().toInt(&ok);
    if (comboBox->currentIndex() == 0) {
        progressBar->setRange(0, num);
        for (int i = 0; i < num + 1; i++) {
            progressBar->setValue(i);
        }
    }else if (comboBox->currentIndex() == 1) {
        QProgressDialog *progressDialog = new QProgressDialog(this);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(5);
        progressDialog->setWindowTitle(tr("Please Wait..."));
        progressDialog->setLabelText(tr("Copying..."));
        progressDialog->setCancelButtonText(tr("Cancel"));
        progressDialog->setRange(0, num);
        for (int i = 0; i < num + 1; i++) {
            progressDialog->setValue(i);
            if (progressDialog->wasCanceled()) {
                return;
            }
        }
    }
}
