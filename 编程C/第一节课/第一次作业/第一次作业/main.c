//
//  main.c
//  第一次作业
//
//  Created by Junjie on 2021/9/22.
//

#include <stdio.h>

int Money1(int money);
int Money2(int money);
int Money3(int money);
int Money4(int money);

int main()
{
    int money,a,b,c,d;
    printf("Enter a dollar amount: ");
    scanf("%d",&money);
    a=Money1(money);
    b=Money2(money);
    c=Money3(money);
    d=Money4(money);
    printf("$20 bills: %d\n",a);
    printf("$10 bills: %d\n",b);
    printf("$5 bills: %d\n",c);
    printf("$1 bills: %d\n",d);
    return 0;
}

int Money1(int money)
{
    int x;
    x=money/20;
    return (x);
}
int Money2(int money)
{
    int x,y;
    x=Money1(money);
    y=(money-x*20)/10;
    return (y);
}
int Money3(int money)
{
    int x,y,z;
    z=Money1(money);
    x=Money2(money);
    y=(money-x*10-z*20)/5;
    return (y);
}
int Money4(int money)
{
    int x,y,z,m;
    m=Money1(money);
    z=Money2(money);
    x=Money3(money);
    y=(money-x*5-z*10-m*20)/1;
    return (y);
}
