//
//  main.cpp
//  test
//
//  Created by Junjie on 2022/3/1.
//

#include <iostream>
#include <cstring>
//#pragram waning(disabled:4996)    //解决由于安全问题使用不了strcat,strcpy等问题
//#define _CRT_NOT_WANING   //解决由于安全问题使用不了strcat,strcpy等问题
using namespace std;

class Date
{
public:
    void SetDate(int y,int m,int d){
        year=y;
        month=m;
        day=d;
    }
    int IsLeapYear(){
        return (year%4==0&&year%100!=0)||(year%400==0);
    }
    void Print(){
        cout << year << "年" << month << "月" << day << "日" << endl;
    }
private:
    int year,month,day;
};

int main(){
    Date d1;
    d1.SetDate(2012, 11, 11);
    d1.Print();
    cout << d1.IsLeapYear() <<endl;
    return 0;
}
