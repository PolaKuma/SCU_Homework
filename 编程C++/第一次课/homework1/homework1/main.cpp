//
//  main.cpp
//  homework1
//
//  Created by Junjie on 2022/3/15.
//

#include <iostream>
using namespace std;

int gcd(int x,int y){
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}


int main(){
    int m,n;
    cin >> m >> n;
    cout << gcd(m,n) << endl;
}
