/********************************************************************************
** Form generated from reading UI file 'filesrvdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESRVDLG_H
#define UI_FILESRVDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileSrvDlg
{
public:
    QLabel *labTitle;
    QLabel *labSend;
    QLineEdit *leSend;
    QPushButton *btnChooseFile;
    QPushButton *btnSend;
    QLabel *labSendSize;
    QLineEdit *leSendSize;
    QLabel *labSendCurrentSize;
    QLineEdit *leSendCurrentSize;
    QLabel *labSendProgress;
    QProgressBar *progressSend;
    QPushButton *btnStopSend;

    void setupUi(QDialog *FileSrvDlg)
    {
        if (FileSrvDlg->objectName().isEmpty())
            FileSrvDlg->setObjectName(QString::fromUtf8("FileSrvDlg"));
        FileSrvDlg->resize(400, 300);
        labTitle = new QLabel(FileSrvDlg);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        labTitle->setGeometry(QRect(170, 30, 71, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labTitle->setFont(font);
        labTitle->setAlignment(Qt::AlignCenter);
        labSend = new QLabel(FileSrvDlg);
        labSend->setObjectName(QString::fromUtf8("labSend"));
        labSend->setGeometry(QRect(20, 70, 51, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(10);
        labSend->setFont(font1);
        leSend = new QLineEdit(FileSrvDlg);
        leSend->setObjectName(QString::fromUtf8("leSend"));
        leSend->setEnabled(false);
        leSend->setGeometry(QRect(80, 70, 200, 30));
        leSend->setFont(font1);
        leSend->setAlignment(Qt::AlignCenter);
        leSend->setReadOnly(true);
        btnChooseFile = new QPushButton(FileSrvDlg);
        btnChooseFile->setObjectName(QString::fromUtf8("btnChooseFile"));
        btnChooseFile->setGeometry(QRect(280, 70, 31, 30));
        btnChooseFile->setFont(font1);
        btnSend = new QPushButton(FileSrvDlg);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(320, 70, 60, 30));
        btnSend->setFont(font1);
        labSendSize = new QLabel(FileSrvDlg);
        labSendSize->setObjectName(QString::fromUtf8("labSendSize"));
        labSendSize->setGeometry(QRect(50, 140, 41, 30));
        labSendSize->setFont(font1);
        leSendSize = new QLineEdit(FileSrvDlg);
        leSendSize->setObjectName(QString::fromUtf8("leSendSize"));
        leSendSize->setEnabled(false);
        leSendSize->setGeometry(QRect(100, 140, 70, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(109);
        leSendSize->setFont(font2);
        leSendSize->setAlignment(Qt::AlignCenter);
        leSendSize->setReadOnly(true);
        labSendCurrentSize = new QLabel(FileSrvDlg);
        labSendCurrentSize->setObjectName(QString::fromUtf8("labSendCurrentSize"));
        labSendCurrentSize->setGeometry(QRect(190, 140, 41, 30));
        labSendCurrentSize->setFont(font1);
        leSendCurrentSize = new QLineEdit(FileSrvDlg);
        leSendCurrentSize->setObjectName(QString::fromUtf8("leSendCurrentSize"));
        leSendCurrentSize->setEnabled(false);
        leSendCurrentSize->setGeometry(QRect(240, 140, 70, 30));
        leSendCurrentSize->setFont(font1);
        leSendCurrentSize->setAlignment(Qt::AlignCenter);
        leSendCurrentSize->setReadOnly(true);
        labSendProgress = new QLabel(FileSrvDlg);
        labSendProgress->setObjectName(QString::fromUtf8("labSendProgress"));
        labSendProgress->setGeometry(QRect(20, 220, 51, 30));
        labSendProgress->setFont(font1);
        progressSend = new QProgressBar(FileSrvDlg);
        progressSend->setObjectName(QString::fromUtf8("progressSend"));
        progressSend->setGeometry(QRect(80, 220, 231, 30));
        progressSend->setValue(24);
        btnStopSend = new QPushButton(FileSrvDlg);
        btnStopSend->setObjectName(QString::fromUtf8("btnStopSend"));
        btnStopSend->setGeometry(QRect(320, 220, 60, 30));
        btnStopSend->setFont(font1);

        retranslateUi(FileSrvDlg);

        QMetaObject::connectSlotsByName(FileSrvDlg);
    } // setupUi

    void retranslateUi(QDialog *FileSrvDlg)
    {
        FileSrvDlg->setWindowTitle(QCoreApplication::translate("FileSrvDlg", "Dialog", nullptr));
        labTitle->setText(QCoreApplication::translate("FileSrvDlg", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        labSend->setText(QCoreApplication::translate("FileSrvDlg", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        btnChooseFile->setText(QCoreApplication::translate("FileSrvDlg", "...", nullptr));
        btnSend->setText(QCoreApplication::translate("FileSrvDlg", "\345\217\221\351\200\201", nullptr));
        labSendSize->setText(QCoreApplication::translate("FileSrvDlg", "\345\244\247\345\260\217\357\274\232", nullptr));
        labSendCurrentSize->setText(QCoreApplication::translate("FileSrvDlg", "\345\267\262\345\217\221\351\200\201\357\274\232", nullptr));
        labSendProgress->setText(QCoreApplication::translate("FileSrvDlg", "\350\277\233   \345\272\246\357\274\232", nullptr));
        btnStopSend->setText(QCoreApplication::translate("FileSrvDlg", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileSrvDlg: public Ui_FileSrvDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESRVDLG_H
