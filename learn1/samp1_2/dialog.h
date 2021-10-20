#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void showArea();
private:
    QLabel *labRadius, *labArea, *labResult;
    QLineEdit *leRadius;
    QPushButton *btnCount;
};
#endif // DIALOG_H
