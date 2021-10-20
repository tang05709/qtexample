#include "mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QFontDatabase>
#include <QColor>
#include <QColorDialog>
#include <QTextList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy word"));
    showWidget = new ShowWidget(this);
    setCentralWidget(showWidget);

    labFont = new QLabel(tr("字体"));
    fontComboBox = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);

    labFont2 = new QLabel(tr("字号"));
    cmbSize = new QComboBox;
    QFontDatabase db;
    foreach (int size, db.standardSizes()) {
        cmbSize->addItem(QString::number(size));
    }

    toolBtnBold = new QToolButton;
    toolBtnBold->setIcon(QIcon(":/icons/images/bold.png"));
    toolBtnBold->setCheckable(true);

    toolBtnItalic = new QToolButton;
    toolBtnItalic->setIcon(QIcon(":/icons/images/italic.png"));
    toolBtnItalic->setCheckable(true);

    toolBtnUnderline = new QToolButton;
    toolBtnUnderline->setIcon(QIcon(":/icons/images/underline.png"));
    toolBtnUnderline->setCheckable(true);

    toolBtnColor = new QToolButton;
    toolBtnColor->setIcon(QIcon(":/icons/images/color.png"));
    toolBtnColor->setCheckable(true);

    labList = new QLabel(tr("排序"));
    cmbList = new QComboBox;
    cmbList->addItem("Standard");
    cmbList->addItem("QTextListFormat::ListDisc");
    cmbList->addItem("QTextListFormat::ListCircle");
    cmbList->addItem("QTextListFormat::ListSquare");
    cmbList->addItem("QTextListFormat::ListDecimal");
    cmbList->addItem("QTextListFormat::ListLowerAlpha");
    cmbList->addItem("QTextListFormat::ListUpperAlpha");
    cmbList->addItem("QTextListFormat::ListLowerRoman");
    cmbList->addItem("QTextListFormat::ListUpperRoman");

    createActions();
    createMenus();
    createToolBars();

    if (img.load(":/icons/images/image.png")) {
        showWidget->labImage->setPixmap(QPixmap::fromImage(img));
    }

    connect(fontComboBox, SIGNAL(activated(QString)), this, SLOT(showFontComboBox(QString)));
    connect(cmbSize, SIGNAL(activated(QString)), this, SLOT(showSizeSpinBox(QString)));
    connect(toolBtnBold, SIGNAL(clicked()), this, SLOT(showBoldBtn()));
    connect(toolBtnItalic, SIGNAL(clicked()), this, SLOT(showItalicBtn()));
    connect(toolBtnUnderline, SIGNAL(clicked()), this, SLOT(showUnderlineBtn()));
    connect(toolBtnColor, SIGNAL(clicked()), this, SLOT(showColorBtn()));
    connect(showWidget->text, SIGNAL(currentCharFormatChanged(QTextCharFormat&)), this, SLOT(showCurrentFormatChanged(QTextCharFormat&)));
    connect(cmbList, SIGNAL(activated(int)), this, SLOT(showList(int)));
    connect(showWidget->text->document(), SIGNAL(undoAvailable(bool)), actUndo, SLOT(setEnabled(bool)));
    connect(showWidget->text->document(), SIGNAL(redoAvailable(bool)), actRedo, SLOT(setEnabled(bool)));
    connect(showWidget->text, SIGNAL(cursorPositionChanged()), this, SLOT(showCursorPositionChanged(int)));
}

MainWindow::~MainWindow()
{
}


void MainWindow::createActions()
{
    // 打开
    actOpenFile = new QAction(QIcon(":/icons/images/open.png"), tr("打开"), this);
    actOpenFile->setShortcut(tr("Ctrl+O"));
    actOpenFile->setStatusTip(tr("打开一个文件"));
    connect(actOpenFile, SIGNAL(triggered()), this, SLOT(showOpenFile()));
    // 新建
    actNewFile = new QAction(QIcon(":/icons/images/new.png"), tr("新建"), this);
    actNewFile->setShortcut(tr("Ctrl+N"));
    actNewFile->setStatusTip(tr("新建一个文件"));
    connect(actNewFile, SIGNAL(triggered()), this, SLOT(showNewFile()));
    // 退出
    actExit = new QAction(tr("退出"), this);
    actExit->setShortcut(tr("Ctrl+Q"));
    actExit->setStatusTip(tr("退出程序"));
    connect(actExit, SIGNAL(triggered()), this, SLOT(close()));
    // 复制
    actCopy = new QAction(QIcon(":/icons/images/copy.png"), tr("复制"), this);
    actCopy->setShortcut(tr("Ctrl+C"));
    actCopy->setStatusTip(tr("复制文件"));
    connect(actCopy, SIGNAL(triggered()), showWidget->text, SLOT(copy()));
    // 剪切
    actCut = new QAction(QIcon(":/icons/images/cut.png"), tr("剪切"), this);
    actCut->setShortcut(tr("Ctrl+X"));
    actCut->setStatusTip(tr("剪切文件"));
    connect(actCut, SIGNAL(triggered()), showWidget->text, SLOT(cut()));
    // 粘贴
    actPaste = new QAction(QIcon(":/icons/images/paste.png"), tr("粘贴"), this);
    actPaste->setShortcut(tr("Ctrl+V"));
    actPaste->setStatusTip(tr("粘贴文件"));
    connect(actPaste, SIGNAL(triggered()), showWidget->text, SLOT(paste()));
    // 关于
    actAbout = new QAction(tr("关于"), this);

    // 打印文本
    actPrintText = new QAction(QIcon(":/icons/images/printText.png"), tr("打印文本"), this);
    actPrintText->setStatusTip(tr("打印文本"));
    connect(actPrintText, SIGNAL(triggered()), this, SLOT(showPrintText()));
    // 打印图片
    actPrintImage = new QAction(QIcon(":/icons/images/printImage.png"), tr("打印图片"), this);
    actPrintImage->setStatusTip(tr("打印图片"));
    connect(actPrintImage, SIGNAL(triggered()), this, SLOT(showPrintImage()));
    // 放大
    actZoomIn = new QAction(QIcon(":/icons/images/zoomin.png"), tr("放大"), this);
    actZoomIn->setStatusTip(tr("放大图片"));
    connect(actZoomIn, SIGNAL(triggered()), this, SLOT(showZoomIn()));
    // 缩小
    actZoomOut = new QAction(QIcon(":/icons/images/zoomout.png"), tr("缩小"), this);
    actZoomOut->setStatusTip(tr("缩小图片"));
    connect(actZoomOut, SIGNAL(triggered()), this, SLOT(showZoomOut()));
    // 旋转90°
    actRotate90 = new QAction(QIcon(":/icons/images/rotate90.png"), tr("旋转90°"), this);
    actRotate90->setStatusTip(tr("图片旋转90°"));
    connect(actRotate90, SIGNAL(triggered()), this, SLOT(showRatate90()));
    // 旋转180°
    actRotate180 = new QAction(QIcon(":/icons/images/rotate180.png"), tr("旋转180°"), this);
    actRotate180->setStatusTip(tr("图片旋转180°"));
    connect(actRotate180, SIGNAL(triggered()), this, SLOT(showRatate180()));
    // 旋转270°
    actRotate270 = new QAction(QIcon(":/icons/images/rotate270.png"), tr("旋转270°"), this);
    actRotate270->setStatusTip(tr("图片旋转270°"));
    connect(actRotate270, SIGNAL(triggered()), this, SLOT(showRatate270()));
    // 纵向镜像
    actMirrorVertical = new QAction(QIcon(":/icons/images/mirrorVertical.png"), tr("纵向镜像"), this);
    actMirrorVertical->setStatusTip(tr("缩小纵向镜像"));
    connect(actMirrorVertical, SIGNAL(triggered()), this, SLOT(showMirrorVertical()));
    // 横向镜像
    actMirrorHorizontal = new QAction(QIcon(":/icons/images/mirrorHorizontal.png"), tr("横向镜像"), this);
    actMirrorHorizontal->setStatusTip(tr("缩小横向镜像"));
    connect(actMirrorHorizontal, SIGNAL(triggered()), this, SLOT(showMirrorHorizontal()));
    // 撤销
    actUndo = new QAction(QIcon(":/icons/images/undo.png"), tr("撤销"), this);
    connect(actUndo, SIGNAL(triggered()), showWidget->text, SLOT(undo()));
    // 重做
    actRedo = new QAction(QIcon(":/icons/images/undo.png"), tr("重做"), this);
    connect(actRedo, SIGNAL(triggered()), showWidget->text, SLOT(redo()));

    actGroup = new QActionGroup(this);
    actLeft = new QAction(QIcon(":/icons/images/left.png"), tr("左对齐"), actGroup);
    actRight = new QAction(QIcon(":/icons/images/right.png"), tr("右对齐"), actGroup);
    actCenter = new QAction(QIcon(":/icons/images/center.png"), tr("居中"), actGroup);
    actJustify = new QAction(QIcon(":/icons/images/justify.png"), tr("两端对齐"), actGroup);
    actLeft->setCheckable(true);
    actRight->setCheckable(true);
    actCenter->setCheckable(true);
    actJustify->setCheckable(true);
    connect(actGroup, SIGNAL(triggered(QAction*)), this, SLOT(showAlignment(QAction*)));
}

void MainWindow::createMenus()
{
    // 文件菜单
    menuFile = menuBar()->addMenu(tr("文件"));
    menuFile->addAction(actOpenFile);
    menuFile->addAction(actNewFile);
    menuFile->addAction(actPrintText);
    menuFile->addAction(actPrintImage);
    menuFile->addSeparator();
    menuFile->addAction(actExit);
    // 缩放菜单
    menuZoom = menuBar()->addMenu(tr("编辑"));
    menuZoom->addAction(actCopy);
    menuZoom->addAction(actCut);
    menuZoom->addAction(actPaste);
    menuZoom->addAction(actAbout);
    menuZoom->addSeparator();
    menuZoom->addAction(actUndo);
    menuZoom->addAction(actRedo);
    menuZoom->addSeparator();
    menuZoom->addAction(actZoomIn);
    menuZoom->addAction(actZoomOut);
    // 旋转菜单
    menuRotate = menuBar()->addMenu(tr("旋转"));
    menuRotate->addAction(actRotate90);
    menuRotate->addAction(actRotate180);
    menuRotate->addAction(actRotate270);
    // 镜像菜单
    menuMirror = menuBar()->addMenu(tr("镜像"));
    menuMirror->addAction(actMirrorVertical);
    menuMirror->addAction(actMirrorHorizontal);
}

void MainWindow::createToolBars()
{
    // 文件工具条
    toolFile = addToolBar("File");
    toolFile->addAction(actOpenFile);
    toolFile->addAction(actNewFile);
    toolFile->addAction(actPrintText);
    toolFile->addAction(actPrintImage);
    // 编辑工具条
    toolZoom = addToolBar("Edit");
    toolZoom->addAction(actCopy);
    toolZoom->addAction(actCut);
    toolZoom->addAction(actPaste);
    toolZoom->addSeparator();
    toolZoom->addAction(actZoomIn);
    toolZoom->addAction(actZoomOut);
    // 旋转工具条
    toolRotate = addToolBar("Rotate");
    toolRotate->addAction(actRotate90);
    toolRotate->addAction(actRotate180);
    toolRotate->addAction(actRotate270);
    // 撤销、重做
    toolDoBar = addToolBar("DoEdit");
    toolDoBar->addAction(actUndo);
    toolDoBar->addAction(actRedo);

    toolFont = addToolBar("Font");
    toolFont->addWidget(labFont);
    toolFont->addWidget(fontComboBox);
    toolFont->addWidget(labFont2);
    toolFont->addWidget(cmbSize);
    toolFont->addSeparator();
    toolFont->addWidget(toolBtnBold);
    toolFont->addWidget(toolBtnItalic);
    toolFont->addWidget(toolBtnUnderline);
    toolFont->addSeparator();
    toolFont->addWidget(toolBtnColor);

    toolList = addToolBar("List");
    toolList->addWidget(labList);
    toolList->addWidget(cmbList);
    toolList->addSeparator();
    toolList->addActions(actGroup->actions());
}

void MainWindow::showNewFile()
{
    MainWindow *main = new MainWindow;
    main->show();
}

void MainWindow::showOpenFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        if (showWidget->text->document()->isEmpty()) {
            loadFile(fileName);
        }
        else {
            MainWindow *main = new MainWindow;
            main->show();
            main->loadFile(fileName);
        }
    }
}

void MainWindow::loadFile(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream textStream(&file);
        while (!textStream.atEnd()) {
            showWidget->text->append(textStream.readLine());
        }
    }
}

void MainWindow::showPrintText()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec()) {
        QTextDocument *doc = showWidget->text->document();
        doc->print(&printer);
    }
}

void MainWindow::showPrintImage()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec()) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = img.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0, 0, img);
    }
}

void MainWindow::showZoomIn()
{
    if (img.isNull()) {
       return;
    }
    QMatrix matrix;
    matrix.scale(2, 2);
    img = img.transformed(matrix);
    showWidget->labImage->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showZoomOut()
{
    if (img.isNull()) {
       return;
    }
    QMatrix matrix;
    matrix.scale(0.5, 0.5);
    img = img.transformed(matrix);
    showWidget->labImage->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showRatate90()
{
    if (img.isNull()) {
        return;
    }
    QMatrix matrix;
    matrix.rotate(90);
    img = img.transformed(matrix);
    showWidget->labImage->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showRatate180()
{
    if (img.isNull()) {
        return;
    }
    QMatrix matrix;
    matrix.rotate(180);
    img = img.transformed(matrix);
    showWidget->labImage->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showRatate270()
{
    if (img.isNull()) {
        return;
    }
    QMatrix matrix;
    matrix.rotate(270);
    img = img.transformed(matrix);
    showWidget->labImage->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showMirrorVertical()
{
    if (img.isNull()) {
        return;
    }
    img = img.mirrored(false, true);
    showWidget->labImage->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showMirrorHorizontal()
{
    if (img.isNull()) {
        return;
    }
    img = img.mirrored(true, false);
    showWidget->labImage->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showFontComboBox(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);
    mergeFormat(fmt);
}

void MainWindow::mergeFormat(QTextCharFormat fmt)
{
    QTextCursor cursor = showWidget->text->textCursor();
    if (!cursor.hasSelection()) {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(fmt);
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void MainWindow::showSizeSpinBox(QString spinValue)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void MainWindow::showBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(toolBtnBold->isChecked() ? QFont::Bold : QFont::Normal);
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void MainWindow::showItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(toolBtnItalic->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void MainWindow::showUnderlineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(toolBtnUnderline->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void MainWindow::showColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red, this);
    if (color.isValid()) {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->text->mergeCurrentCharFormat(fmt);
    }

}

void MainWindow::showCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    cmbSize->setCurrentIndex(cmbSize->findText(QString::number(fmt.fontPointSize())));
    toolBtnBold->setChecked(fmt.font().bold());
    toolBtnItalic->setChecked(fmt.fontItalic());
    toolBtnUnderline->setChecked(fmt.fontUnderline());
}

void MainWindow::showAlignment(QAction *act)
{
    if (act == actLeft) {
        showWidget->text->setAlignment(Qt::AlignLeft);
    }
    if (act == actRight) {
        showWidget->text->setAlignment(Qt::AlignRight);
    }
    if (act == actCenter) {
        showWidget->text->setAlignment(Qt::AlignCenter);
    }
    if (act == actJustify) {
        showWidget->text->setAlignment(Qt::AlignJustify);
    }
}

void MainWindow::showCursorPositionChanged()
{
    if (showWidget->text->alignment() == Qt::AlignLeft) {
        actLeft ->setChecked(true);
    }
    if (showWidget->text->alignment() == Qt::AlignRight) {
        actRight ->setChecked(true);
    }
    if (showWidget->text->alignment() == Qt::AlignCenter) {
        actCenter ->setChecked(true);
    }
    if (showWidget->text->alignment() == Qt::AlignJustify) {
        actJustify ->setChecked(true);
    }
}

void MainWindow::showList(int index)
{
    QTextCursor cursor = showWidget->text->textCursor();
    if (index != 0) {
        QTextListFormat::Style style = QTextListFormat::ListDisc;
        switch (index) {
        default:
        case 1:
            style = QTextListFormat::ListDisc;
            break;
        case 2:
            style = QTextListFormat::ListCircle;
            break;
        case 3:
            style = QTextListFormat::ListSquare;
            break;
        case 4:
            style = QTextListFormat::ListDecimal;
            break;
        case 5:
            style = QTextListFormat::ListLowerAlpha;
            break;
        case 6:
            style = QTextListFormat::ListUpperAlpha;
            break;
        case 7:
            style = QTextListFormat::ListLowerRoman;
            break;
        case 8:
            style = QTextListFormat::ListUpperRoman;
            break;
        }
        // 缩进值
        cursor.beginEditBlock();
        QTextBlockFormat blockFmt = cursor.blockFormat();
        QTextListFormat listFmt;
        if (cursor.currentList()) {
            listFmt = cursor.currentList()->format();
        } else {
            listFmt.setIndent(blockFmt.indent() + 1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);
        cursor.endEditBlock();
    } else {
        QTextBlockFormat fmt;
        fmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(fmt);
    }
}
