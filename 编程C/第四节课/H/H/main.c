//
//  main.c
//  H
//
//  Created by Junjie on 2021/10/14.
//

#include <stdio.h>

int main()
{
    int a=1,b=1,c;
    int n;
    scanf("%d",&n);
    while (a<=n){
        while (b<=a){
            c=a*b;
            printf("%d*%d=%-3d",a,b,c);
            b=b+1;
        }
        printf("\n");
        a=a+1;
        b=1;
    }
}
