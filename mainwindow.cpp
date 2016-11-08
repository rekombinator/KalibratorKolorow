#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   portSzeregowy = new PortSzeregowy();


   connect(ui->button_RGB,SIGNAL(clicked(bool)),portSzeregowy,SLOT(show()));

 connect(ui->button_R,SIGNAL(clicked(bool)),portSzeregowy,SLOT(showR()));
  connect(ui->button_G,SIGNAL(clicked(bool)),portSzeregowy,SLOT(showG()));
   connect(ui->button_B,SIGNAL(clicked(bool)),portSzeregowy,SLOT(showB()));

   connect(ui->action10kHz,SIGNAL(triggered(bool)),portSzeregowy,SLOT(skala10()));
   connect(ui->action100kHz,SIGNAL(triggered(bool)),portSzeregowy,SLOT(skala100()));
   connect(ui->action600kHz,SIGNAL(triggered(bool)),portSzeregowy,SLOT(skala600()));


connect(portSzeregowy,SIGNAL(displayR(int)),ui->lcdR,SLOT(display(int)));
connect(portSzeregowy,SIGNAL(displayG(int)),ui->lcdG,SLOT(display(int)));
connect(portSzeregowy,SIGNAL(displayB(int)),ui->lcdB,SLOT(display(int)));

connect(ui->wlacz_led,SIGNAL(triggered(bool)),portSzeregowy,SLOT(wlacz_led()));
connect(ui->wylacz_led,SIGNAL(triggered(bool)),portSzeregowy,SLOT(wylacz_led()));


}

MainWindow::~MainWindow()
{
    delete portSzeregowy;
    delete ui;

}


