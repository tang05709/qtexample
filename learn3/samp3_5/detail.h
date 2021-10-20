#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = nullptr);

signals:

private:
    QLabel *labNational;
    QComboBox *cmbNational;
    QLabel *labProvince;
    QComboBox *cmbProvince;
    QLabel *labCity;
    QLineEdit *leCity;
    QLabel *labIntroduct;
    QTextEdit *teIntroduct;
    QGridLayout *mainLayout;
};

#endif // DETAIL_H
