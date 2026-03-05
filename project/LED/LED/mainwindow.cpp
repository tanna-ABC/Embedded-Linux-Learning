#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "led.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static int status = 1;

    if(status)
    {
        qDebug()<<"LED clicked on";
    }
    else
    {
        qDebug()<<"LED clicked off";
    }

    /* 2. control LED*/
    led_control(status);

    status = !status;
}
