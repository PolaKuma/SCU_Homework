#include <iostream>
using namespace std;

class  SavingsAccount
{
    int  id;  //帐号
    double  balance;     //余额
    double  rate;      //年利率
    int  lastDate;    //上次变更余额的日期
    double  accumulation;    //余额按日累加之和
    double  accumulate(int date);//获得到指定日期为止的存款金额按日累积值
public:
    SavingsAccount (int date, int id, double rate);  //构造函数
    void  deposit(int date, double amount);  //存入现金，date为日期，amount为金额
    void  withdraw(int date, double amount);  //取出现金
    void  settle(int date);    //结算利息，每年1月1日调用一次该函数
    void  show();      //输出账户信息
    int getId() {return id;}
    double  getBalance () { return balance;}
    double  getRate() {return rate;}
};

double SavingsAccount::accumulate(int date){
    accumulation+=balance*(date-lastDate);
    return accumulation;
}

SavingsAccount::SavingsAccount(int date, int id, double rate){
    this->id=id;
    this->rate=rate;
    balance=0;
    lastDate=date;
    accumulation=0;
}

void SavingsAccount::deposit(int date, double amount){
    accumulate(date);
    lastDate=date;
    balance+=amount;
}

void SavingsAccount::withdraw(int date, double amount){
    accumulate(date);
    lastDate=date;
    if(balance>=amount)
        balance-=amount;
    else
        cout << "余额不足" << endl;
}

void SavingsAccount::settle(int date){
    accumulate(date);
    if(date==91||date%366==0){  //由于开户日初始化date为1，所以得+1
        balance+=accumulation/365*rate;
        cout << "利息：" << accumulation/365*rate << endl;
    }else
        cout << "非计息日！" << endl;
}

void SavingsAccount::show(){
    cout << "账号：" << id << endl << "余额：" << balance << endl;
}

int main(){
    //账户测试
    SavingsAccount s0(1,1001,0.015);
    SavingsAccount s1(1,1002,0.015);
    s0.deposit(6, 5000);
    s0.deposit(46, 5500);
    s1.deposit(26, 10000);
    s1.withdraw(61, 4000);
    s0.settle(91);
    s1.settle(91);
    s0.show();
    s1.show();

    return 0;
}



