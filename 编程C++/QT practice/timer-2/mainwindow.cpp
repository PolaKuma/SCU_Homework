#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTimer(1000); //其返回值为 1，即其 timerId 为 1
    startTimer(5000);//其返回值为 2，即其 timerId 为 2
    startTimer(10000); //其返回值为 3，即其 timerId 为 3
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *t) //定时器事件
{
    switch(t->timerId()) //判断定时器的句柄
    {
        case 2 : ui->label->setText(tr("每秒产生一个随机数：%1").arg(qrand()%10));break;
        case 3 : ui->label_2->setText(tr("5 秒后软件将关闭"));break;
        case 4 : qApp->quit();break; //退出系统
    }
}
