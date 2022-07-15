#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class loginDlg;
}

class loginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit loginDlg(QWidget *parent = nullptr);
    ~loginDlg();

private slots:
    void on_loginBtn_clicked();

private:
    Ui::loginDlg *ui;
};

#endif // LOGINDLG_H
