//
//  main.c
//  FIBONaSCCI
//
//  Created by Junjie on 2021/10/27.
//

#include <stdio.h>

int main(){
    int a[20],i;
    a[0]=1; a[1]=1;
    for (i=0;i<20;i++)
        a[i+2]=a[i+1]+a[i];
    for (i=0;i<20;i++)
        printf("%d ",a[i]);
    printf("\n");
}
//打印斐波那契数列前20个数

int Fabonacci(unsigned int n){
    int a[10000]={1,1};
    int i;
    for (i=2;i<=n;i++){
    a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}
//返回第n个斐波那契数列的数

int Fabonacci2(unsigned int n){
    if (n>2)
        return Fabonacci2(n-1)+Fabonacci(n-2);
    else
        return 1;
}
//返回第n个斐波那契数列的数
