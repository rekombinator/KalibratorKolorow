#include "obrazytestowe.h"
#include "ui_obrazytestowe.h"

ObrazyTestowe::ObrazyTestowe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObrazyTestowe)
{
    ui->setupUi(this);

   connect(this,SIGNAL(sendColor(QColor)),ui->widget,SLOT(getColor(QColor)));


}

ObrazyTestowe::~ObrazyTestowe()
{
    delete ui;
}

void ObrazyTestowe::on_button_czerwony_released()
{
    emit sendColor(Qt::red);
}

void ObrazyTestowe::on_button_zielony_released()
{
    emit sendColor(Qt::green);
}

void ObrazyTestowe::on_button_niebieski_released()
{
     emit sendColor(Qt::blue);
}

void ObrazyTestowe::on_button_zolty_released()
{
    emit sendColor(Qt::yellow);
}

void ObrazyTestowe::on_button_cyan_released()
{
    emit sendColor(Qt::cyan);
}

void ObrazyTestowe::on_button_magenta_released()
{
    emit sendColor(Qt::magenta);
}
