#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(tr("按下键盘上的 A 键试试!"));
    ui->pushButton->setText(tr("按下鼠标的一个键，然后移动鼠标试试"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *m){
    QCursor my(QPixmap("/Users/junjie/Downloads/Project C++/QT practice/Stuff/time.png"));
    QApplication::setOverrideCursor(my);
    int x=m->pos().x(); //获取鼠标现在的位置坐标
    int y=m->pos().y();
    ui->pushButton->setText(tr("鼠标现在的坐标是(%1,%2)").arg(x).arg(y));
    ui->pushButton->move(m->pos());
}

void MainWindow::keyPressEvent(QKeyEvent *k){
    if(k->key() == Qt::Key_A){  //判断是否是 A 键按下
        ui->label->setPixmap(QPixmap("/Users/junjie/Downloads/Project C++/QT practice/Stuff/3.png"));   //更改标签图片和大小
        ui->label->resize(1000,1000);
    }
}
