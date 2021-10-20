#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void showDetailInfo();

private:
    void createBaseInfo();
    void createDetailInfo();
    QWidget *wgtBase;
    QWidget *wgtDetail;
};
#endif // DIALOG_H
