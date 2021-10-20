#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ChildWord;
class QSignalMapper;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initWindow();
    void docNew(); // 新建文档
    void docOpen(); // 打开文档
    void docSave(); // 保存文档
    void docSaveAs(); // 另存为
    void docUndo(); // 撤销
    void docRedo(); // 重做
    void docCut(); // 剪切
    void docCopy(); // 复制
    void docPaste(); // 粘贴
    void textBold(); // 加粗
    void textItalic(); // 倾斜
    void textUnderline(); // 下划线
    void textFamily(const QString& family); // 设置字体
    void textSize(const QString& ps); // 设置字号
    void textAlign(QAction *act); // 对齐方式
    void textColor();// 设置颜色
    void paraStyle(int sidx); // 设置段落标号
    void docPrint(); // 打印
    void docPrintPreview(); // 打印预览
    void printPreview(QPrinter *); // 打印预览里打印

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_actAbout_triggered();

    void on_actAboutQt_triggered();

    void on_actNew_triggered();

    void refreshMenus(); // 刷新菜单
    void addSubWndListMenu(); // 往“窗口”主菜单下添加子窗口菜单项列表

    void on_actClose_triggered();

    void on_actCloseAll_triggered();

    void on_actTile_triggered();

    void on_actCascade_triggered();

    void on_actNext_triggered();

    void on_actPrevious_triggered();

    void on_actOpen_triggered();

    void on_actSave_triggered();

    void on_actSaveAs_triggered();

    void on_actUndo_triggered();

    void on_actRedo_triggered();

    void on_actCut_triggered();

    void on_actCopy_triggered();

    void on_actPaste_triggered();

    void on_actBold_triggered();

    void on_actItalic_triggered();

    void on_actUnderline_triggered();

    void on_cmbFont_activated(const QString &arg1);

    void on_cmbFontSize_activated(const QString &arg1);

    void on_actLeftAlign_triggered();

    void on_actRightAlign_triggered();

    void on_actCenterAlign_triggered();

    void on_actJustify_triggered();

    void on_actColor_triggered();

    void on_cmbListStyle_activated(int index);

    void on_actPrint_triggered();

    void on_actPrintPreview_triggered();

private:
    Ui::MainWindow *ui;

    void formatEnabled(); // 使“格式”菜单下的各菜单项及其对应的工具按钮变为可用
    ChildWord *activateChildWord(); //  活动文档子窗口
    QSignalMapper *myWndMapper; // 子窗口信号映射器
    QMdiSubWindow *findChildWnd(const QString& docName); // 查找特定的文档子窗口
};
#endif // MAINWINDOW_H
