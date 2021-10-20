#include "widget.h"
#include <QColorDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    paintArea = new PaintArea;

    labShape = new QLabel(tr("形状："));
    cmbShape = new QComboBox;
    cmbShape->addItem(tr("Line"), PaintArea::Line);
    cmbShape->addItem(tr("Rectangle"), PaintArea::Rectangle);
    cmbShape->addItem(tr("RoundRect"), PaintArea::RoundRect);
    cmbShape->addItem(tr("Ellipse"), PaintArea::Ellipse);
    cmbShape->addItem(tr("Polygon"), PaintArea::Polygon);
    cmbShape->addItem(tr("Polyline"), PaintArea::Polyline);
    cmbShape->addItem(tr("Points"), PaintArea::Points);
    cmbShape->addItem(tr("Arc"), PaintArea::Arc);
    cmbShape->addItem(tr("Path"), PaintArea::Path);
    cmbShape->addItem(tr("Text"), PaintArea::Text);
    cmbShape->addItem(tr("Pixmap"), PaintArea::Pixmap);
    connect(cmbShape, SIGNAL(activated(int)), this, SLOT(showShape(int)));

    labPenColor = new QLabel(tr("画笔颜色："));
    framePenColor = new QFrame;
    framePenColor->setFrameStyle(QFrame::Panel |QFrame::Sunken);
    framePenColor->setAutoFillBackground(true);
    framePenColor->setPalette(QPalette(Qt::blue));
    btnPenColor = new QPushButton(tr("更改"));
    connect(btnPenColor, SIGNAL(clicked()), this, SLOT(showPenColor()));

    labPenWidth = new QLabel(tr("画笔线宽："));
    spbPenWidth = new QSpinBox;
    spbPenWidth->setRange(0, 20);
    connect(spbPenWidth, SIGNAL(valueChanged(int)), this, SLOT(showPenWidth(int)));

    labPenStyle = new QLabel(tr("画笔风格："));
    cmbPenStyle = new QComboBox;
    cmbPenStyle->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
    cmbPenStyle->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
    cmbPenStyle->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
    cmbPenStyle->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
    cmbPenStyle->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
    cmbPenStyle->addItem(tr("CustomDashLine"), static_cast<int>(Qt::CustomDashLine));
    connect(cmbPenStyle, SIGNAL(activated(int)), this, SLOT(showPenStyle(int)));


    labPenCap = new QLabel(tr("画笔顶帽："));
    cmbPenCap = new QComboBox;
    cmbPenCap->addItem(tr("SquareCap"), Qt::SquareCap);
    cmbPenCap->addItem(tr("FlatCap"), Qt::FlatCap);
    cmbPenCap->addItem(tr("RoundCap"), Qt::RoundCap);
    connect(cmbPenCap, SIGNAL(activated(int)), this, SLOT(showPenCap(int)));

    labPenJoin = new QLabel(tr("画笔连接点："));
    cmbPenJoin = new QComboBox;
    cmbPenJoin->addItem(tr("BevelJoin"), Qt::BevelJoin);
    cmbPenJoin->addItem(tr("MiterJoin"), Qt::MiterJoin);
    cmbPenJoin->addItem(tr("RoundJoin"), Qt::RoundJoin);
    connect(cmbPenJoin, SIGNAL(activated(int)), this, SLOT(showPenJoin(int)));

    labFillRule = new QLabel(tr("填充模式："));
    cmbFillRule = new QComboBox;
    cmbFillRule->addItem(tr("OddEvenFill"), Qt::OddEvenFill);
    cmbFillRule->addItem(tr("WindingFill"), Qt::WindingFill);
    connect(cmbFillRule, SIGNAL(activated(int)), this, SLOT(showFillRule()));

    labSpread = new QLabel(tr("铺展效果："));
    cmbSpread = new QComboBox;
    cmbSpread->addItem(tr("PadSpread"), QGradient::PadSpread);
    cmbSpread->addItem(tr("RepeatSpread"), QGradient::RepeatSpread);
    cmbSpread->addItem(tr("ReflectSpread"), QGradient::ReflectSpread);
    connect(cmbSpread, SIGNAL(activated(int)), this, SLOT(showSpreadStyle()));

    labBrushColor = new QLabel(tr("画刷颜色："));
    frameBrushColor = new QFrame;
    frameBrushColor->setFrameStyle(QFrame::Panel |QFrame::Sunken);
    frameBrushColor->setAutoFillBackground(true);
    frameBrushColor->setPalette(QPalette(Qt::blue));
    btnBrushColor = new QPushButton(tr("更改"));
    connect(btnBrushColor, SIGNAL(clicked()), this, SLOT(showBrushColor()));

    labBrushStyle = new QLabel(tr("画刷风格："));
    cmbBrushStyle = new QComboBox;
    cmbBrushStyle->addItem(tr("SolidPattern"), static_cast<int>(Qt::SolidPattern));
    cmbBrushStyle->addItem(tr("Dense1Pattern"), static_cast<int>(Qt::Dense1Pattern));
    cmbBrushStyle->addItem(tr("Dense2Pattern"), static_cast<int>(Qt::Dense2Pattern));
    cmbBrushStyle->addItem(tr("Dense3Pattern"), static_cast<int>(Qt::Dense3Pattern));
    cmbBrushStyle->addItem(tr("Dense4Pattern"), static_cast<int>(Qt::Dense4Pattern));
    cmbBrushStyle->addItem(tr("Dense5Pattern"), static_cast<int>(Qt::Dense5Pattern));
    cmbBrushStyle->addItem(tr("Dense6Pattern"), static_cast<int>(Qt::Dense6Pattern));
    cmbBrushStyle->addItem(tr("Dense7Pattern"), static_cast<int>(Qt::Dense7Pattern));
    cmbBrushStyle->addItem(tr("HorPattern"), static_cast<int>(Qt::HorPattern));
    cmbBrushStyle->addItem(tr("CrossPattern"), static_cast<int>(Qt::CrossPattern));
    cmbBrushStyle->addItem(tr("BDiagPattern"), static_cast<int>(Qt::BDiagPattern));
    cmbBrushStyle->addItem(tr("DiagCrossPattern"), static_cast<int>(Qt::DiagCrossPattern));
    cmbBrushStyle->addItem(tr("LinearGradientPattern"), static_cast<int>(Qt::LinearGradientPattern));
    cmbBrushStyle->addItem(tr("ConicalGradientPattern"), static_cast<int>(Qt::ConicalGradientPattern));
    cmbBrushStyle->addItem(tr("RadialGradientPattern"), static_cast<int>(Qt::RadialGradientPattern));
    cmbBrushStyle->addItem(tr("TexturePattern"), static_cast<int>(Qt::TexturePattern));
    connect(cmbBrushStyle, SIGNAL(activated(int)), this, SLOT(showBrush(int)));

    rightLayout = new QGridLayout;
    rightLayout->addWidget(labShape, 0, 0);
    rightLayout->addWidget(cmbShape, 0, 1);
    rightLayout->addWidget(labPenColor, 1, 0);
    rightLayout->addWidget(framePenColor, 1, 1);
    rightLayout->addWidget(btnPenColor, 1, 2);
    rightLayout->addWidget(labPenWidth, 2, 0);
    rightLayout->addWidget(spbPenWidth, 2, 1);
    rightLayout->addWidget(labPenStyle, 3, 0);
    rightLayout->addWidget(cmbPenStyle, 3, 1);
    rightLayout->addWidget(labPenCap, 4, 0);
    rightLayout->addWidget(cmbPenCap, 4, 1);
    rightLayout->addWidget(labPenJoin, 5, 0);
    rightLayout->addWidget(cmbPenJoin, 5, 1);
    rightLayout->addWidget(labFillRule, 6, 0);
    rightLayout->addWidget(cmbFillRule, 6, 1);
    rightLayout->addWidget(labSpread, 7, 0);
    rightLayout->addWidget(cmbSpread, 7, 1);
    rightLayout->addWidget(labBrushColor, 8, 0);
    rightLayout->addWidget(frameBrushColor, 8, 1);
    rightLayout->addWidget(btnBrushColor, 8, 2);
    rightLayout->addWidget(labBrushStyle, 9, 0);
    rightLayout->addWidget(cmbBrushStyle, 9, 1);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(paintArea);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(paintArea, 1);
    mainLayout->setStretchFactor(rightLayout, 0);
    showShape(cmbShape->currentIndex());
}

Widget::~Widget()
{
}

void Widget::showShape(int v)
{
    PaintArea::Shape sp = PaintArea::Shape(cmbShape->itemData(v, Qt::UserRole).toInt());
    paintArea->setShape(sp);
}

void Widget::showPenColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    framePenColor->setPalette(QPalette(color));
    int value = spbPenWidth->value();
    Qt::PenStyle style = Qt::PenStyle(cmbPenStyle->itemData(cmbPenStyle->currentIndex(), Qt::UserRole).toUInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(cmbPenCap->itemData(cmbPenCap->currentIndex(), Qt::UserRole).toUInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(cmbPenJoin->itemData(cmbPenJoin->currentIndex(), Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void Widget::showPenWidth(int v)
{
    QColor color = framePenColor->palette().color(QPalette::Window);
    Qt::PenStyle style = Qt::PenStyle(cmbPenStyle->itemData(cmbPenStyle->currentIndex(), Qt::UserRole).toUInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(cmbPenCap->itemData(cmbPenCap->currentIndex(), Qt::UserRole).toUInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(cmbPenJoin->itemData(cmbPenJoin->currentIndex(), Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, v, style, cap, join));
}

void Widget::showPenStyle(int v)
{
    QColor color = framePenColor->palette().color(QPalette::Window);
    int value = spbPenWidth->value();
    Qt::PenStyle style = Qt::PenStyle(cmbPenStyle->itemData(v, Qt::UserRole).toUInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(cmbPenCap->itemData(cmbPenCap->currentIndex(), Qt::UserRole).toUInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(cmbPenJoin->itemData(cmbPenJoin->currentIndex(), Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void Widget::showPenCap(int v)
{
    QColor color = framePenColor->palette().color(QPalette::Window);
    int value = spbPenWidth->value();
    Qt::PenStyle style = Qt::PenStyle(cmbPenStyle->itemData(cmbPenStyle->currentIndex(), Qt::UserRole).toUInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(cmbPenCap->itemData(v, Qt::UserRole).toUInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(cmbPenJoin->itemData(cmbPenJoin->currentIndex(), Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void Widget::showPenJoin(int v)
{
    QColor color = framePenColor->palette().color(QPalette::Window);
    int value = spbPenWidth->value();
    Qt::PenStyle style = Qt::PenStyle(cmbPenStyle->itemData(cmbPenStyle->currentIndex(), Qt::UserRole).toUInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(cmbPenCap->itemData(cmbPenCap->currentIndex(), Qt::UserRole).toUInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(cmbPenJoin->itemData(v, Qt::UserRole).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void Widget::showFillRule()
{
    Qt::FillRule rule = Qt::FillRule(cmbFillRule->itemData(cmbFillRule->currentIndex(), Qt::UserRole).toInt());
    paintArea->setFillRule(rule);
}

void Widget::showSpreadStyle()
{
    spread = QGradient::Spread(cmbSpread->itemData(cmbSpread->currentIndex(), Qt::UserRole).toInt());
}

void Widget::showBrushColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    frameBrushColor->setPalette(QPalette(color));
    showBrush(cmbBrushStyle->currentIndex());
}

void Widget::showBrush(int v)
{
     QColor color = frameBrushColor->palette().color(QPalette::Window);
     Qt::BrushStyle style = Qt::BrushStyle(cmbBrushStyle->itemData(v, Qt::UserRole).toInt());
     if (style == Qt::LinearGradientPattern) {
         QLinearGradient linearGradient(0, 0, 400, 400);
         linearGradient.setColorAt(0.0, Qt::white);
         linearGradient.setColorAt(0.2, color);
         linearGradient.setColorAt(1.0, Qt::black);
         linearGradient.setSpread(spread);
         paintArea->setBrush(linearGradient);
     } else if (style == Qt::RadialGradientPattern) {
         QRadialGradient radialGradient(200, 200, 150, 150, 100);
         radialGradient.setColorAt(0.0, Qt::white);
         radialGradient.setColorAt(0.2, color);
         radialGradient.setColorAt(1.0, Qt::black);
         radialGradient.setSpread(spread);
         paintArea->setBrush(radialGradient);
     } else if (style == Qt::TexturePattern) {
         paintArea->setBrush(QBrush(QPixmap(":/images/avatar8.jpg")));
     } else {
         paintArea->setBrush(QBrush(color, style));
     }
}
