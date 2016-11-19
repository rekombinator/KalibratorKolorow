#ifndef OBRAZYTESTOWE_H
#define OBRAZYTESTOWE_H

#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include "colorwidget.h"

namespace Ui {
class ObrazyTestowe;
}

class ObrazyTestowe : public QDialog
{
    Q_OBJECT

public:
    explicit ObrazyTestowe(QWidget *parent = 0);
    ~ObrazyTestowe();
    void paintEvent();


private slots:
    void on_button_czerwony_released();

    void on_button_zielony_released();

    void on_button_niebieski_released();

    void on_button_zolty_released();

    void on_button_cyan_released();

    void on_button_magenta_released();

signals:
    void sendColor(QColor);


private:
    Ui::ObrazyTestowe *ui;




};

#endif // OBRAZYTESTOWE_H
