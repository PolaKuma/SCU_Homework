//
//  main.cpp
//  homework2
//
//  Created by Junjie on 2022/3/15.
//

#include <iostream>
using namespace std;

class account{
public:
    account();
    ~account(){};
    void CheckBalance();
    void Withdraw();
    void Deposit();
    void Display();
private:
    int id;
    double balance;
};

account::account(){
    balance=100;
}

void account::CheckBalance(){
    cout << "The balance is " << balance << endl;
}

void account::Withdraw(){
    double m;
    cout << "Enter to withdraw: " << endl;
    cin >> m;
    balance-=m;
}

void account::Deposit(){
    double m;
    cout << "Enter to deposit: " << endl;
    cin >> m;
    balance+=m;
}

void account::Display(){
    cout << "Main menu" << endl << "1:check balance" << endl << "2:withdraw" << endl << "3:deposit" << endl << "4:exit" <<endl;
}

class ATM:public account{
private:
    static account a[10];
};

int main(){
    static account a[10];
    while(1){
        int acc,choice=0;
        cout << "Enter an id: ";
        cin >> acc;
        a[acc].Display();
        while(choice != 4){
            cout << "Enter a choice: ";
            cin >> choice;
            switch(choice){
                case 1:a[acc].CheckBalance(); break;
                case 2:a[acc].Withdraw(); break;
                case 3:a[acc].Deposit(); break;
            }
            }
        }
}
