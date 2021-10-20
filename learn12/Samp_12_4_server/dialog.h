#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class TimeServer;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void on_btnQuit_clicked();

    void slotShow();

private:
    Ui::Dialog *ui;
    TimeServer *timeServer;
    int count;
};
#endif // DIALOG_H
