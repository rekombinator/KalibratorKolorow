#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "portszeregowy.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
signals:
    void sendColor(QColor);




private slots:
    void on_radioRed_clicked();

    void on_radioBlue_clicked();

    void on_radioGreen_clicked();

    void on_radioMagenta_clicked();

    void on_radioYellow_clicked();

    void on_radioCyan_clicked();

private:
    Ui::MainWindow *ui;
   PortSzeregowy *portSzeregowy;



};

#endif // MAINWINDOW_H
