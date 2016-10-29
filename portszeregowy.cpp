#include "portszeregowy.h"

PortSzeregowy::PortSzeregowy()
{
    QList <QSerialPortInfo> lista_portow;
    lista_portow = QSerialPortInfo::availablePorts();
    QSerialPortInfo porcik;
    QSerialPortInfo XplainedMiniInfo;
    // vendorIdentifier = 1027, productIdentifier = 24577;

   foreach (porcik, lista_portow)
    {
      if(porcik.vendorIdentifier()==1027 && porcik.productIdentifier()==24577)
      {
          XplainedMiniInfo=porcik;
      }
    }


XplainedMini= new QSerialPort(XplainedMiniInfo);

XplainedMini->setBaudRate(QSerialPort::Baud9600);
XplainedMini->setDataBits(QSerialPort::Data8);
XplainedMini->setFlowControl(QSerialPort::NoFlowControl);
XplainedMini->setParity(QSerialPort::NoParity);
XplainedMini->setStopBits(QSerialPort::TwoStop);
XplainedMini->open(QIODevice::ReadWrite);

XplainedMini->setReadBufferSize(256);
int s=XplainedMini->readBufferSize();

XplainedMini->write("L");
while(XplainedMini->waitForBytesWritten(1000));

qDebug()<<XplainedMini->portName();
qDebug()<<s;

}

PortSzeregowy::~PortSzeregowy()
{
XplainedMini->close();

}

void PortSzeregowy::show()
{
 XplainedMini->clear(QSerialPort::AllDirections);
    XplainedMini->write("R");
    while(XplainedMini->waitForBytesWritten(100))
    while(XplainedMini->waitForReadyRead(250));

    pomiar_R=XplainedMini->read(250);
XplainedMini->clear(QSerialPort::AllDirections);

    qDebug()<<pomiar_R;
    double wynikR;
    QStringList listaR = pomiar_R.split(" ");
    listaR.removeLast();
    listaR.removeFirst();
    foreach (QString s, listaR) {
       qDebug()<<s;
       wynikR+=s.toDouble();
    }
    wynikR=wynikR/listaR.length();
    qDebug()<<wynikR;
    qDebug()<<listaR.length();
    int wynikIntR=(int)wynikR;



    XplainedMini->clear(QSerialPort::AllDirections);
       XplainedMini->write("G");
       while(XplainedMini->waitForBytesWritten(100))
       while(XplainedMini->waitForReadyRead(250));

       pomiar_G=XplainedMini->read(250);

         XplainedMini->clear(QSerialPort::AllDirections);

       qDebug()<<pomiar_G;

       double wynikG;
       QStringList listaG = pomiar_G.split(" ");
       listaG.removeLast();
       listaG.removeFirst();
       foreach (QString s, listaG) {
          qDebug()<<s;
          wynikG+=s.toDouble();
       }
       wynikG=wynikG/listaG.length();
       qDebug()<<wynikG;

       int wynikIntG=(int)wynikG;


       XplainedMini->clear(QSerialPort::AllDirections);
          XplainedMini->write("B");
          while(XplainedMini->waitForBytesWritten(100))
          while(XplainedMini->waitForReadyRead(250));

         pomiar_B=XplainedMini->read(250);

          XplainedMini->clear(QSerialPort::AllDirections);
          qDebug()<<pomiar_B;

          double wynikB;
          QStringList listaB = pomiar_B.split(" ");
          listaB.removeLast();
         listaB.removeFirst();
          foreach (QString s, listaB) {
             qDebug()<<s;
             wynikB+=s.toDouble();
          }
         wynikB=wynikB/listaB.length();

         int wynikIntB=(int)wynikB;
          emit displayB(wynikIntB);
         emit displayR(wynikIntR);
           emit displayG(wynikIntG);
}






