#include "portszeregowy.h"

PortSzeregowy::PortSzeregowy()
{
    isDevicePlug=false;
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

          isDevicePlug=true;


    }
}
}

PortSzeregowy::~PortSzeregowy()
{
XplainedMini->close();

}

void PortSzeregowy::show()
{
    if(isDevicePlug)
    {
    showR();
    showB();
    showG();
    showC();
    }
    else
    {
      QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
    }
}

void PortSzeregowy::showR()
{
    if(isDevicePlug)
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

       wynikR/=10;
       wynikR=round(wynikR);
       wynikR*=10;

       int wynikIntR=static_cast<int>(wynikR);

         emit displayR(wynikIntR);
}
    else
    {
      QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
    }

}

void PortSzeregowy::showG()
{
if(isDevicePlug)
{
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

       wynikG/=10;
       wynikG=round(wynikG);
       wynikG*=10;

       int wynikIntG= static_cast<int>(wynikG);
       emit displayG(wynikIntG);
}
else
{
  QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
}
}

void PortSzeregowy::showB()
{
if(isDevicePlug)
{
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

      wynikB/=10;
      wynikB=round(wynikB);
      wynikB*=10;

      int wynikIntB=static_cast<int>(wynikB);

       emit displayB(wynikIntB);
}
else
{
  QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
}
}

void PortSzeregowy::showC()
{
    if(isDevicePlug)
    {
    XplainedMini->clear(QSerialPort::AllDirections);
       XplainedMini->write("E");
       while(XplainedMini->waitForBytesWritten(100))
       while(XplainedMini->waitForReadyRead(250));

      pomiar_C=XplainedMini->read(250);

       XplainedMini->clear(QSerialPort::AllDirections);
       qDebug()<<pomiar_C;

       double wynikC;
       QStringList listaC = pomiar_C.split(" ");
       listaC.removeLast();
      listaC.removeFirst();
       foreach (QString s, listaC) {
          qDebug()<<s;
          wynikC+=s.toDouble();
       }
      wynikC=wynikC/listaC.length();

      wynikC/=10;
      wynikC=round(wynikC);
      wynikC*=10;

      int wynikIntC=static_cast<int>(wynikC);

       emit displayC(wynikIntC);
    }
    else
    {
      QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
    }
}

void PortSzeregowy::wlacz_led()
{
    if(isDevicePlug)
    {
    XplainedMini->clear(QSerialPort::AllDirections);
       XplainedMini->write("L");
       while(XplainedMini->waitForBytesWritten(100))
     XplainedMini->clear(QSerialPort::AllDirections);
}
    else
    {
      QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
    }

}

void PortSzeregowy::wylacz_led()
{
    if(isDevicePlug)
    {
    XplainedMini->clear(QSerialPort::AllDirections);
       XplainedMini->write("X");
       while(XplainedMini->waitForBytesWritten(100))
     XplainedMini->clear(QSerialPort::AllDirections);
}
    else
    {
      QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
    }
}

void PortSzeregowy::skala10()
{
    if(isDevicePlug)
    {
    XplainedMini->clear(QSerialPort::AllDirections);
       XplainedMini->write("1");
       while(XplainedMini->waitForBytesWritten(100))
     XplainedMini->clear(QSerialPort::AllDirections);
    }
    else
    {
      QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
    }
}

void PortSzeregowy::skala100()
{
    if(isDevicePlug)
    {
    XplainedMini->clear(QSerialPort::AllDirections);
       XplainedMini->write("2");
       while(XplainedMini->waitForBytesWritten(100))
     XplainedMini->clear(QSerialPort::AllDirections);
    }
    else
    {
      QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
    }
}

void PortSzeregowy::skala600()
{
    if(isDevicePlug)
    {
    XplainedMini->clear(QSerialPort::AllDirections);
       XplainedMini->write("3");
       while(XplainedMini->waitForBytesWritten(100))
     XplainedMini->clear(QSerialPort::AllDirections);
    }
    else
    {
      QMessageBox::warning(this,"Error","Urządzenie nie zostało podłączone");
    }
}






