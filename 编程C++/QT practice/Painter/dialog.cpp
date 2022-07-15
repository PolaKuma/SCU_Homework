#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPen pen; //画笔
    pen.setColor(QColor(255,0,0));
    QBrush brush(QColor(0,255,0,125)); //画刷
    painter.setPen(pen); //添加画笔
    painter.setBrush(brush); //添加画刷
    painter.drawRect(100,100,200,200); //绘制矩形
}
