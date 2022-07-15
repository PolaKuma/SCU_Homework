//将两个一样的圆盘看为一个圆盘，假设汉诺塔的三根柱子，从左到右叫做ABC，最开始A柱上有n个圆盘。那么要做的就是把顶上的n-1个盘子挪到B柱，把A柱的第n个盘子挪到C柱，再把B柱的n-1个盘子挪到C柱。
//所以如果把n个圆盘从一个柱子移到另一个柱子的步数为f(n)，那就得到了f(n) = f(n-1) + 1 + f(n-1)
//同理将该圆盘拆分为两份后则f(n) = 2*f(n-1) + 2，终止条件为2

#include <iostream>
using namespace std;

int Hanota(int n){
    if(n==1)
        return 2;
    else
        return 2*Hanota(n-1)+2;
}

int main(){
    int n;
    cin >> n;
    cout << Hanota(n) << endl;
    return 0;
}


