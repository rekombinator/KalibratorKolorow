#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   portSzeregowy = new PortSzeregowy();
   connect(ui->button_sprawdz,SIGNAL(clicked(bool)),portSzeregowy,SLOT(show()));


connect(portSzeregowy,SIGNAL(displayR(int)),ui->lcdR,SLOT(display(int)));
connect(portSzeregowy,SIGNAL(displayG(int)),ui->lcdG,SLOT(display(int)));
connect(portSzeregowy,SIGNAL(displayB(int)),ui->lcdB,SLOT(display(int)));


}

MainWindow::~MainWindow()
{
    delete portSzeregowy;
    delete ui;

}


