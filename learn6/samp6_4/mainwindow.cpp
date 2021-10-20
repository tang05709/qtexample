#include "mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("SVG viewer"));
    createMenu();
    svgWindow = new SvgWindow;
    setCentralWidget(svgWindow);
}

MainWindow::~MainWindow()
{
}


void MainWindow::createMenu()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("文件"));
    QAction *actOpen = new QAction(tr("打开"), this);
    connect(actOpen, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
    fileMenu->addAction(actOpen);
}

void MainWindow::slotOpenFile()
{
    QString name = QFileDialog::getOpenFileName(this, tr("打开"), "/", "svg files(*.svg)");
    svgWindow->setFile(name);
}
