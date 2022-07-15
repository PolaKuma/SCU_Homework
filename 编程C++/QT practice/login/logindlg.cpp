#include "logindlg.h"
#include "ui_logindlg.h"
#include <QMessageBox>  //记得要加头文件

loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDlg)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);  //初始化输入密码为黑点
}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::on_loginBtn_clicked()
{
    if(ui->userLineEdit->text().trimmed()==tr("qt")&&ui->pwdLineEdit->text()==tr("123456")) //判断用户输入密码正确
        accept();
    else {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);   //弹出警告
        ui->userLineEdit->clear();  //清空输入框
        ui->pwdLineEdit->clear();
        ui->userLineEdit->setFocus();   //鼠标光标移动
    }
}
