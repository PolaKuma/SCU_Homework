//由题分析，从两个数最小最大值分别累加累减进行枚举，直到找到符合条件的最大公约数和最小公倍数
#include <iostream>
using namespace std;

int GCM(int m,int n,int max,int min){   //最大公约数
    while(m%min!=0 || n%min!=0)
        min--;
    return min;
}

int LCM(int m,int n,int max,int min){   //最小公倍数
    while(max%m!=0 || max%n!=0)
        max++;
    return max;
}

int main(){
    int m,n,max,min;
    cin >> m >> n;
    if(m>n){    //找两个数最大最小作为枚举起始点
        max=m;
        min=n;
    }else{
        max=n;
        min=m;
    }
    cout << GCM(m,n,max,min) << " " << LCM(m,n,max,min) << endl;
    return 0;
}



