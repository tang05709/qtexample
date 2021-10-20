#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "childword.h"
#include <QMessageBox>
#include <QFontDatabase>
#include <QMdiSubWindow>
#include <QSignalMapper>
#include <QCloseEvent>
#include <QFileDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();
    refreshMenus();
    // 当有活动文档子窗口时刷新菜单
    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(refreshMenus()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow()
{
    // 初始化字体和字号下拉列表
    QFontDatabase fontdb;
    foreach (QString font, fontdb.families()) {
        ui->cmbFont->addItem(font);
    }
    foreach (int fontsize, fontdb.standardSizes()) {
        ui->cmbFontSize->addItem(QString::number(fontsize));
    }
    ui->cmbFont->setCurrentText(QApplication::font().family());
    ui->cmbFontSize->setCurrentIndex(ui->cmbFontSize->findText(QString::number(QApplication::font().pointSize())));

    // 设置MDIArea的滚动条在需要的时候才出现
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // 添加子窗口菜单项列表
    myWndMapper = new QSignalMapper(this);

    addSubWndListMenu();
    connect(ui->menu_W, SIGNAL(aboutToShow()), this, SLOT(addSubWndListMenu()));

    // 将”格式-段落“下各对齐子菜单加入同一个菜单组，使用户在选择时只能选择其中一项
    QActionGroup *alignGroup = new QActionGroup(this);
    alignGroup->addAction(ui->actLeftAlign);
    alignGroup->addAction(ui->actCenterAlign);
    alignGroup->addAction(ui->actRightAlign);
    alignGroup->addAction(ui->actJustify);
    ui->actLeftAlign->setChecked(true);
}

void MainWindow::on_actAbout_triggered()
{
    QMessageBox::about(this, tr("关于"), tr("这是一个基于Qt5实现的文字处理软件\r\n具备类似微软Office Word的功能"));
}

void MainWindow::on_actAboutQt_triggered()
{
    QMessageBox::aboutQt(NULL, tr("关于Qt5"));
}

void MainWindow::docNew()
{
    ChildWord *childWnd = new ChildWord;
    // 向多文档区域添加子窗体
    ui->mdiArea->addSubWindow(childWnd);
    // 根据QTextEdit类是否可以复制信号，设置剪切、复制动作是否可用
    connect(childWnd, SIGNAL(copyAvailable(bool)), ui->actCut, SLOT(setEnabled(bool)));
    connect(childWnd, SIGNAL(copyAvailable(bool)), ui->actCopy, SLOT(setEnabled(bool)));

    childWnd->newDoc();
    childWnd->show();
    formatEnabled();
}

void MainWindow::docOpen()
{
    QString docName = QFileDialog::getOpenFileName(this, tr("打开"), QString(), tr("HTML 文档(*.htm *.html);;所有文件(*.*)"));
    if (!docName.isEmpty()) {
        QMdiSubWindow *exist = findChildWnd(docName);
        if (exist) {
            ui->mdiArea->setActiveSubWindow(exist);
            return;
        }
        ChildWord *childwnd = new ChildWord;
        ui->mdiArea->addSubWindow(childwnd);
        connect(childwnd, SIGNAL(copyAvailable(bool)), ui->actCut, SLOT(setEnabled(bool)));
        connect(childwnd, SIGNAL(copyAvailable(bool)), ui->actCopy, SLOT(setEnabled(bool)));
        if (childwnd->loadDoc(docName)) {
            statusBar()->showMessage(tr("文档已打开"), 2000);
            childwnd->show();
            formatEnabled();
        } else {
            childwnd->close();
        }
    }
}

void MainWindow::docSave()
{
    if (activateChildWord() && activateChildWord()->saveDoc()) {
        statusBar()->showMessage(tr("保存成功"), 2000);
    }
}

void MainWindow::docSaveAs()
{
    if (activateChildWord() && activateChildWord()->saveAsDoc()) {
        statusBar()->showMessage(tr("保存成功"), 2000);
    }
}


QMdiSubWindow* MainWindow::findChildWnd(const QString &docName)
{
    QString canonicalFilePath = QFileInfo(docName).canonicalFilePath();
    foreach (QMdiSubWindow *wnd, ui->mdiArea->subWindowList()) {
        ChildWord *childwnd = qobject_cast<ChildWord*>(wnd->widget());
        if (childwnd->myCurDocPath == canonicalFilePath) {
            return wnd;
        }
    }
    return 0;
}

void MainWindow::formatEnabled()
{
    ui->actBold->setEnabled(true);
    ui->actItalic->setEnabled(true);
    ui->actUnderline->setEnabled(true);
    ui->actLeftAlign->setEnabled(true);
    ui->actCenterAlign->setEnabled(true);
    ui->actRightAlign->setEnabled(true);
    ui->actJustify->setEnabled(true);
    ui->actColor->setEnabled(true);
}

void MainWindow::on_actNew_triggered()
{
    docNew();
}

void MainWindow::refreshMenus()
{
    // 至少有一个文档子窗口打开的情况
    bool hasChild = (activateChildWord() != 0);
    ui->actSave->setEnabled(hasChild);
    ui->actSaveAs->setEnabled(hasChild);
    ui->actPrint->setEnabled(hasChild);
    ui->actPrintPreview->setEnabled(hasChild);
    ui->actPaste->setEnabled(hasChild);
    ui->actClose->setEnabled(hasChild);
    ui->actCloseAll->setEnabled(hasChild);
    ui->actTile->setEnabled(hasChild);
    ui->actCascade->setEnabled(hasChild);
    ui->actNext->setEnabled(hasChild);
    ui->actPrevious->setEnabled(hasChild);

    // 文档已打开并且其中有内容被选中的情况
    bool hasSelect = (activateChildWord() && activateChildWord()->textCursor().hasSelection());
    ui->actCut->setEnabled(hasSelect);
    ui->actCopy->setEnabled(hasSelect);
    ui->actBold->setEnabled(hasSelect);
    ui->actItalic->setEnabled(hasSelect);
    ui->actUnderline->setEnabled(hasSelect);
    ui->actLeftAlign->setEnabled(hasSelect);
    ui->actCenterAlign->setEnabled(hasSelect);
    ui->actRightAlign->setEnabled(hasSelect);
    ui->actJustify->setEnabled(hasSelect);
    ui->actColor->setEnabled(hasSelect);
}

ChildWord* MainWindow::activateChildWord()
{
    // 若有活动文档窗口则将其内的中心部件转换为ChildWord类型，若没有则直接返回0
    if (QMdiSubWindow *actSubWnd = ui->mdiArea->activeSubWindow()) {
        return qobject_cast<ChildWord*>(actSubWnd->widget());
    }
    return 0;
}

void MainWindow::addSubWndListMenu()
{
    // 先清空原主菜单，然后再添加各菜单项
    ui->menu_W->clear();
    ui->menu_W->addAction(ui->actClose);
    ui->menu_W->addAction(ui->actCloseAll);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->actTile);
    ui->menu_W->addAction(ui->actCascade);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->actNext);
    ui->menu_W->addAction(ui->actPrevious);

    QList<QMdiSubWindow*> wnds = ui->mdiArea->subWindowList();
    // 如果有活动子窗口，则添加分割条并追加当前已打开的文档子窗口项
    if (!wnds.isEmpty()) ui->menu_W->addSeparator();
    for (int i = 0; i < wnds.size(); i++) {
        ChildWord *childwnd = qobject_cast<ChildWord*>(wnds.at(i)->widget());
        QString menuitemText;
        if (i < 9) {
            menuitemText = tr("&%1 %2").arg(i + 1).arg(childwnd->getCurDocName());
        } else {
            menuitemText = tr("%1 %2").arg(i + 1).arg(childwnd->getCurDocName());
        }
        // 添加子窗口菜单项， 设置其可选
        QAction *menuitemAct = ui->menu_W->addAction(menuitemText);
        menuitemAct->setCheckable(true);
        // 将当前活动的子窗口设为勾选状态
        menuitemAct->setChecked(childwnd == activateChildWord());
        // 关联菜单项的触发信号到信号映射器map()槽，该槽会发送mapped()信号
        connect(menuitemAct, SIGNAL(triggered()), myWndMapper, SLOT(map()));
        // 将菜单项与对应的窗口部件进行映射，在发送mapped()信号时就会以这个窗口部件为参数
        myWndMapper->setMapping(menuitemAct, wnds.at(i));
    }
    formatEnabled();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows();
    if (ui->mdiArea->currentSubWindow()) {
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::docUndo()
{
    if (activateChildWord()) activateChildWord()->undo();
}

void MainWindow::docRedo()
{
    if (activateChildWord()) activateChildWord()->redo();
}

void MainWindow::docCut()
{
    if (activateChildWord()) activateChildWord()->cut();
}

void MainWindow::docCopy()
{
    if (activateChildWord()) activateChildWord()->copy();
}

void MainWindow::docPaste()
{
    if (activateChildWord()) activateChildWord()->paste();
}

void MainWindow::textBold()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->actBold->isChecked() ? QFont::Bold : QFont::Normal);
    if (activateChildWord()) activateChildWord()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textItalic()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->actItalic->isChecked());
    if (activateChildWord()) activateChildWord()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textUnderline()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->actUnderline->isChecked());
    if (activateChildWord()) activateChildWord()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textFamily(const QString &family)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(family);
    if (activateChildWord()) activateChildWord()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textSize(const QString &ps)
{
    qreal pointSize = ps.toFloat();
    if (pointSize > 0) {
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointSize);
        if (activateChildWord()) activateChildWord()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textAlign(QAction *act)
{
    if (activateChildWord()) {
        if (act == ui->actLeftAlign) {
            activateChildWord()->setAlignOfDocumentText(1);
        } else if (act == ui->actCenterAlign) {
            activateChildWord()->setAlignOfDocumentText(2);
        } else if (act == ui->actRightAlign) {
            activateChildWord()->setAlignOfDocumentText(3);
        } else if (act == ui->actJustify) {
            activateChildWord()->setAlignOfDocumentText(4);
        }
    }
}

void MainWindow::textColor()
{
    if (activateChildWord()) {
        QColor color = QColorDialog::getColor(activateChildWord()->textColor(), this);
        if (!color.isValid()) return;
        QTextCharFormat fmt;
        fmt.setForeground(color);
        activateChildWord()->setFormatOnSelectedWord(fmt);
        QPixmap pix(16, 16);
        pix.fill(color);
        ui->actColor->setIcon(pix);
    }
}

void MainWindow::paraStyle(int sidx)
{
    if (activateChildWord()) activateChildWord()->setParaStyle(sidx);
}

void MainWindow::docPrint()
{
    QPrinter pter(QPrinter::HighResolution);
    QPrintDialog *plog = new QPrintDialog(&pter, this);
    if (activateChildWord()->textCursor().hasSelection()) {
        plog->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    }
    plog->setWindowTitle(tr("打印文档"));
    if (plog->exec() == QDialog::Accepted) {
        activateChildWord()->print(&pter);
    }
    delete plog;
}

void MainWindow::docPrintPreview()
{
    QPrinter pter(QPrinter::HighResolution);
    QPrintPreviewDialog pview(&pter, this);
    connect(&pview, SIGNAL(paintRequested(QPrinter*)), SLOT(printPreview(QPrinter*)));
    pview.exec();
}

void MainWindow::printPreview(QPrinter *ptr)
{
    activateChildWord()->print(ptr);
}

void MainWindow::on_actClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_actCloseAll_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_actTile_triggered()
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_actNext_triggered()
{
    ui->mdiArea->activateNextSubWindow();
}

void MainWindow::on_actPrevious_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();
}


void MainWindow::on_actOpen_triggered()
{
    docOpen();
}

void MainWindow::on_actSave_triggered()
{
    docSave();
}

void MainWindow::on_actSaveAs_triggered()
{
    docSaveAs();
}

void MainWindow::on_actUndo_triggered()
{
    docUndo();
}

void MainWindow::on_actRedo_triggered()
{
    docRedo();
}

void MainWindow::on_actCut_triggered()
{
    docCut();
}

void MainWindow::on_actCopy_triggered()
{
    docCopy();
}

void MainWindow::on_actPaste_triggered()
{
    docPaste();
}

void MainWindow::on_actBold_triggered()
{
    textBold();
}

void MainWindow::on_actItalic_triggered()
{
    textItalic();
}

void MainWindow::on_actUnderline_triggered()
{
    textUnderline();
}

void MainWindow::on_cmbFont_activated(const QString &family)
{
    textFamily(family);
}

void MainWindow::on_cmbFontSize_activated(const QString &ps)
{
    textSize(ps);
}

void MainWindow::on_actLeftAlign_triggered()
{
    textAlign(ui->actLeftAlign);
}

void MainWindow::on_actRightAlign_triggered()
{
    textAlign(ui->actRightAlign);
}

void MainWindow::on_actCenterAlign_triggered()
{
    textAlign(ui->actCenterAlign);
}

void MainWindow::on_actJustify_triggered()
{
    textAlign(ui->actJustify);
}

void MainWindow::on_actColor_triggered()
{
    textColor();
}

void MainWindow::on_cmbListStyle_activated(int index)
{
    paraStyle(index);
}

void MainWindow::on_actPrint_triggered()
{
    docPrint();
}

void MainWindow::on_actPrintPreview_triggered()
{
    docPrintPreview();
}
