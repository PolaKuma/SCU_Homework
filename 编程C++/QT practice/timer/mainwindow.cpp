#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    //关联定时器计满信号和相应的槽函数
    timer->start(1000);
    //定时器开始计时，其中 1000 表示 1000ms 即 1 秒
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerUpDate()
{
    QDateTime time = QDateTime::currentDateTime();
//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
//设置系统时间显示格式
    ui->label->setText(str);
//在标签上显示时间
}
