#ifndef PORTSZEREGOWY_H
#define PORTSZEREGOWY_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>
#include <QDebug>
#include <QWidget>


class PortSzeregowy : public QWidget
{

Q_OBJECT

public:
    PortSzeregowy();
    ~PortSzeregowy();
signals:
    displayR(int);
    displayG(int);
    displayB(int);

public slots:
    void show();
    void showR();
    void showG();
    void showB();
    void wlacz_led();
    void wylacz_led();

    void skala10();
    void skala100();
    void skala600();


private:
    QSerialPort *XplainedMini;
    QString pomiar_R;
    QString pomiar_G;
    QString pomiar_B;
};

#endif // PORTSZEREGOWY_H
