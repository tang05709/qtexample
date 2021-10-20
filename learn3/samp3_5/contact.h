#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = nullptr);

signals:

private:
    QLabel *labEmail;
    QLineEdit *leEmail;
    QLabel *labAddr;
    QLineEdit *leAddr;
    QLabel *labCode;
    QLineEdit *leCode;
    QLabel *labMoviTel;
    QLineEdit *leMoviTel;
    QCheckBox *chkMoviTel;
    QLabel *labProTel;
    QLineEdit *leProTel;
    QGridLayout *mainLayout;

};

#endif // CONTACT_H
