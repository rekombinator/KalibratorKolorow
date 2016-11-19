#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
class ColorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColorWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);

signals:

public slots:
    void getColor(QColor c);

private:
    QColor color;
};

#endif // COLORWIDGET_H
