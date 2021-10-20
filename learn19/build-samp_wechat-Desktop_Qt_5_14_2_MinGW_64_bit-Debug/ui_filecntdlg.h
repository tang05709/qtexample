/********************************************************************************
** Form generated from reading UI file 'filecntdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILECNTDLG_H
#define UI_FILECNTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileCntDlg
{
public:
    QLabel *labRecvTitle;
    QLabel *labRecv;
    QLineEdit *leRecv;
    QPushButton *btnRecvStop;
    QLabel *labRecvSize;
    QLineEdit *leRecvSize;
    QLabel *labRecvCurrentSize;
    QLineEdit *leRecvCurrentSize;
    QLabel *labRecvProgress;
    QProgressBar *progressRecv;

    void setupUi(QDialog *FileCntDlg)
    {
        if (FileCntDlg->objectName().isEmpty())
            FileCntDlg->setObjectName(QString::fromUtf8("FileCntDlg"));
        FileCntDlg->resize(400, 300);
        labRecvTitle = new QLabel(FileCntDlg);
        labRecvTitle->setObjectName(QString::fromUtf8("labRecvTitle"));
        labRecvTitle->setGeometry(QRect(170, 30, 71, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labRecvTitle->setFont(font);
        labRecv = new QLabel(FileCntDlg);
        labRecv->setObjectName(QString::fromUtf8("labRecv"));
        labRecv->setGeometry(QRect(20, 70, 50, 30));
        leRecv = new QLineEdit(FileCntDlg);
        leRecv->setObjectName(QString::fromUtf8("leRecv"));
        leRecv->setGeometry(QRect(90, 70, 211, 30));
        btnRecvStop = new QPushButton(FileCntDlg);
        btnRecvStop->setObjectName(QString::fromUtf8("btnRecvStop"));
        btnRecvStop->setGeometry(QRect(320, 70, 60, 30));
        labRecvSize = new QLabel(FileCntDlg);
        labRecvSize->setObjectName(QString::fromUtf8("labRecvSize"));
        labRecvSize->setGeometry(QRect(50, 140, 40, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(10);
        labRecvSize->setFont(font1);
        leRecvSize = new QLineEdit(FileCntDlg);
        leRecvSize->setObjectName(QString::fromUtf8("leRecvSize"));
        leRecvSize->setEnabled(false);
        leRecvSize->setGeometry(QRect(100, 140, 70, 30));
        leRecvSize->setFont(font1);
        leRecvSize->setReadOnly(true);
        labRecvCurrentSize = new QLabel(FileCntDlg);
        labRecvCurrentSize->setObjectName(QString::fromUtf8("labRecvCurrentSize"));
        labRecvCurrentSize->setGeometry(QRect(190, 140, 50, 30));
        labRecvCurrentSize->setFont(font1);
        leRecvCurrentSize = new QLineEdit(FileCntDlg);
        leRecvCurrentSize->setObjectName(QString::fromUtf8("leRecvCurrentSize"));
        leRecvCurrentSize->setEnabled(false);
        leRecvCurrentSize->setGeometry(QRect(250, 140, 70, 30));
        leRecvCurrentSize->setFont(font1);
        leRecvCurrentSize->setReadOnly(true);
        labRecvProgress = new QLabel(FileCntDlg);
        labRecvProgress->setObjectName(QString::fromUtf8("labRecvProgress"));
        labRecvProgress->setGeometry(QRect(20, 210, 61, 30));
        progressRecv = new QProgressBar(FileCntDlg);
        progressRecv->setObjectName(QString::fromUtf8("progressRecv"));
        progressRecv->setGeometry(QRect(120, 210, 181, 30));
        progressRecv->setValue(24);

        retranslateUi(FileCntDlg);

        QMetaObject::connectSlotsByName(FileCntDlg);
    } // setupUi

    void retranslateUi(QDialog *FileCntDlg)
    {
        FileCntDlg->setWindowTitle(QCoreApplication::translate("FileCntDlg", "Dialog", nullptr));
        labRecvTitle->setText(QCoreApplication::translate("FileCntDlg", "\346\226\207\344\273\266\346\216\245\346\224\266", nullptr));
        labRecv->setText(QCoreApplication::translate("FileCntDlg", "\346\216\245\346\224\266\346\226\207\344\273\266\357\274\232", nullptr));
        btnRecvStop->setText(QCoreApplication::translate("FileCntDlg", "\345\201\234\346\255\242", nullptr));
        labRecvSize->setText(QCoreApplication::translate("FileCntDlg", "\345\244\247\345\260\217\357\274\232", nullptr));
        labRecvCurrentSize->setText(QCoreApplication::translate("FileCntDlg", "\345\267\262\346\216\245\345\217\227\357\274\232", nullptr));
        labRecvProgress->setText(QCoreApplication::translate("FileCntDlg", "\350\277\233    \345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileCntDlg: public Ui_FileCntDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILECNTDLG_H
