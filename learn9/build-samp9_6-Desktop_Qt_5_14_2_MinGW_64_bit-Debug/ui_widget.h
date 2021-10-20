/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QCheckBox *chkWrite;
    QCheckBox *chkFile;
    QCheckBox *chkRead;
    QCheckBox *checkBox;
    QCheckBox *chkDir;
    QCheckBox *chkHide;
    QCheckBox *chkLink;
    QCheckBox *chkExec;
    QPushButton *btnGetInfo;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *labFileName;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leFileName;
    QPushButton *btnFileName;
    QLabel *labSize;
    QLineEdit *leSize;
    QLabel *labCreateTime;
    QLineEdit *leCreateTime;
    QLabel *labModifyTime;
    QLineEdit *leModifyTime;
    QLabel *labVisitTime;
    QLineEdit *leVisitTime;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(70, 260, 451, 80));
        chkWrite = new QCheckBox(groupBox);
        chkWrite->setObjectName(QString::fromUtf8("chkWrite"));
        chkWrite->setGeometry(QRect(340, 40, 41, 18));
        chkFile = new QCheckBox(groupBox);
        chkFile->setObjectName(QString::fromUtf8("chkFile"));
        chkFile->setGeometry(QRect(80, 40, 51, 18));
        chkRead = new QCheckBox(groupBox);
        chkRead->setObjectName(QString::fromUtf8("chkRead"));
        chkRead->setGeometry(QRect(290, 40, 41, 18));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(-70, 40, 73, 18));
        chkDir = new QCheckBox(groupBox);
        chkDir->setObjectName(QString::fromUtf8("chkDir"));
        chkDir->setGeometry(QRect(20, 40, 51, 18));
        chkHide = new QCheckBox(groupBox);
        chkHide->setObjectName(QString::fromUtf8("chkHide"));
        chkHide->setGeometry(QRect(230, 40, 51, 18));
        chkLink = new QCheckBox(groupBox);
        chkLink->setObjectName(QString::fromUtf8("chkLink"));
        chkLink->setGeometry(QRect(140, 40, 81, 18));
        chkExec = new QCheckBox(groupBox);
        chkExec->setObjectName(QString::fromUtf8("chkExec"));
        chkExec->setGeometry(QRect(400, 40, 51, 18));
        btnGetInfo = new QPushButton(Widget);
        btnGetInfo->setObjectName(QString::fromUtf8("btnGetInfo"));
        btnGetInfo->setGeometry(QRect(70, 360, 451, 20));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 40, 451, 194));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labFileName = new QLabel(layoutWidget);
        labFileName->setObjectName(QString::fromUtf8("labFileName"));

        gridLayout->addWidget(labFileName, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leFileName = new QLineEdit(layoutWidget);
        leFileName->setObjectName(QString::fromUtf8("leFileName"));

        horizontalLayout->addWidget(leFileName);

        btnFileName = new QPushButton(layoutWidget);
        btnFileName->setObjectName(QString::fromUtf8("btnFileName"));

        horizontalLayout->addWidget(btnFileName);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        labSize = new QLabel(layoutWidget);
        labSize->setObjectName(QString::fromUtf8("labSize"));

        gridLayout->addWidget(labSize, 1, 0, 1, 1);

        leSize = new QLineEdit(layoutWidget);
        leSize->setObjectName(QString::fromUtf8("leSize"));

        gridLayout->addWidget(leSize, 1, 1, 1, 1);

        labCreateTime = new QLabel(layoutWidget);
        labCreateTime->setObjectName(QString::fromUtf8("labCreateTime"));

        gridLayout->addWidget(labCreateTime, 2, 0, 1, 1);

        leCreateTime = new QLineEdit(layoutWidget);
        leCreateTime->setObjectName(QString::fromUtf8("leCreateTime"));

        gridLayout->addWidget(leCreateTime, 2, 1, 1, 1);

        labModifyTime = new QLabel(layoutWidget);
        labModifyTime->setObjectName(QString::fromUtf8("labModifyTime"));

        gridLayout->addWidget(labModifyTime, 3, 0, 1, 1);

        leModifyTime = new QLineEdit(layoutWidget);
        leModifyTime->setObjectName(QString::fromUtf8("leModifyTime"));

        gridLayout->addWidget(leModifyTime, 3, 1, 1, 1);

        labVisitTime = new QLabel(layoutWidget);
        labVisitTime->setObjectName(QString::fromUtf8("labVisitTime"));

        gridLayout->addWidget(labVisitTime, 4, 0, 1, 1);

        leVisitTime = new QLineEdit(layoutWidget);
        leVisitTime->setObjectName(QString::fromUtf8("leVisitTime"));

        gridLayout->addWidget(leVisitTime, 4, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\345\261\236\346\200\247\357\274\232", nullptr));
        chkWrite->setText(QCoreApplication::translate("Widget", "\345\206\231", nullptr));
        chkFile->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266", nullptr));
        chkRead->setText(QCoreApplication::translate("Widget", "\350\257\273", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "CheckBox", nullptr));
        chkDir->setText(QCoreApplication::translate("Widget", "\347\233\256\345\275\225", nullptr));
        chkHide->setText(QCoreApplication::translate("Widget", "\351\232\220\350\227\217", nullptr));
        chkLink->setText(QCoreApplication::translate("Widget", "\347\254\246\345\220\210\350\277\236\346\216\245", nullptr));
        chkExec->setText(QCoreApplication::translate("Widget", "\346\211\247\350\241\214", nullptr));
        btnGetInfo->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\346\226\207\344\273\266\344\277\241\346\201\257", nullptr));
        labFileName->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        btnFileName->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266", nullptr));
        labSize->setText(QCoreApplication::translate("Widget", "\345\244\247\345\260\217\357\274\232", nullptr));
        labCreateTime->setText(QCoreApplication::translate("Widget", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        labModifyTime->setText(QCoreApplication::translate("Widget", "\346\234\200\345\220\216\344\277\256\346\224\271\346\227\266\351\227\264\357\274\232", nullptr));
        labVisitTime->setText(QCoreApplication::translate("Widget", "\346\234\200\345\220\216\350\256\277\351\227\256\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
