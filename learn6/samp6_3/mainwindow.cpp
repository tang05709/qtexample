#include "mainwindow.h"
#include <QToolBar>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    drawWidget = new DrawWidget;
    setCentralWidget(drawWidget);
    createToolBar();
    setMinimumSize(600, 400);
    showStyle();
    drawWidget->setWidth(spbWidth->value());
    drawWidget->setColor(Qt::black);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar("Tool");
    labStyle = new QLabel(tr("线型风格："));
    cmbStyle = new QComboBox;
    cmbStyle->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
    cmbStyle->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
    cmbStyle->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
    cmbStyle->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
    cmbStyle->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
    connect(cmbStyle, SIGNAL(activated(int)), this, SLOT(showStyle()));

    labWidth = new QLabel(tr("线宽："));
    spbWidth = new QSpinBox;
    connect(spbWidth, SIGNAL(valueChanged(int)), drawWidget, SLOT(setWidth(int)));

    toolBtnColor = new QToolButton;
    QPixmap pixmap(20, 20);
    pixmap.fill(Qt::black);
    toolBtnColor->setIcon(QIcon(pixmap));
    connect(toolBtnColor, SIGNAL(clicked()), this, SLOT(showColor()));

    toolBtnClear = new QToolButton;
    toolBtnClear->setText(tr("清除"));
    connect(toolBtnClear, SIGNAL(clicked()), drawWidget, SLOT(clear()));

    toolBar->addWidget(labStyle);
    toolBar->addWidget(cmbStyle);
    toolBar->addWidget(labWidth);
    toolBar->addWidget(spbWidth);
    toolBar->addWidget(toolBtnColor);
    toolBar->addWidget(toolBtnClear);

}

void MainWindow::showStyle()
{
    drawWidget->setStyle(cmbStyle->itemData(cmbStyle->currentIndex(), Qt::UserRole).toInt());
}

void MainWindow::showColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::black), this);
    if (color.isValid()) {
        drawWidget->setColor(color);
        QPixmap p(20, 20);
        p.fill(color);
        toolBtnColor->setIcon(QIcon(p));
    }
}
