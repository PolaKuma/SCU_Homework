//
//  main.c
//  D
//
//  Created by Junjie on 2021/10/14.
//

#include <stdio.h>

int main(){
    int number1,i,a;
    scanf("%d",&number1);
    a=number1;
    int b,c=0;
    for (i=1;a/i!=0;i=i*10){
        b=number1%10;
        number1=number1/10;
        c=c*10+b;
    }
    if (a==c){
        printf("Yes\n");
    }
    else
        printf("No\n");
}

//用末位数加到末位组成倒序数字

int ways2(){
    long long number1,i;
    long long number2=0;
    scanf("%lld",&number1);
    long long j=1;
    while (number1/j != 0){
        j=j*10;
    }
    for (i=10;number1>i/10;i=i*10){
        long long a,b;
        b=i/10;
        a=(number1%i)/b;
        number2=number2+a*j;
        j=j/10;
    }
    number2=number2/10;
    if (number1==number2){
        return "Yes\n";
    }
    else
        return "No\n";
}

//先知道最大位，再得到各数位，再用最大位循环/10再乘各数位得到倒序数字

int ways3(){
    
}
//数组的方法
