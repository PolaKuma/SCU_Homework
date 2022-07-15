//
//  main.cpp
//  c++test
//
//  Created by Junjie on 2022/3/10.
//

#include <iostream>
using namespace std;

class Pay{
private:
    int small_count;
    int big_count;
public:
    Pay();
    ~Pay();
    void Count(int);
    void Display(){
        cout << "THE CHARGE IS:" << Price(small_count,big_count) <<endl;
    }
    int Price(int small_count,int big_count);
public:
    static int price;
};

Pay::Pay(){
    price=0;
    small_count=0;
    big_count=0;
}

void Pay::Count(int n){
    if (n==0)
        small_count++;
    else
        big_count++;
}

int Pay::Price(int,int){
    return price=small_count*5+big_count*10;
}
