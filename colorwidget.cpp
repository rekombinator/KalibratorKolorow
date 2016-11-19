#include "colorwidget.h"

ColorWidget::ColorWidget(QWidget *parent) : QWidget(parent)
{
    color=Qt::green;
}

void ColorWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setBrush(color);

   QRectF rectangle2(0,0,rect().width()-1,rect().height()-1);

   painter.drawRect(rectangle2);

}

void ColorWidget::getColor(QColor c)
{
    color=c;
    repaint();

}
