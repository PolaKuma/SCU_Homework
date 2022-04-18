//
//  main.c
//  A
//
//  Created by Junjie on 2021/10/13.
//

#include <stdio.h>

int main(){
    int x=0;
    int T;
    scanf("%d",&T);
    while(x<T)
    {
    int a,c,d,e,f;
    int count=0;
    scanf("%d %d",&a,&c);
    int b=a;
    while (a<=b && b<=c){
    d=b/100;
    e=(b-100*d)/10;
    f=b-100*d-10*e;
        if (d*d*d+e*e*e+f*f*f==b){
            printf("%d ",b);
            count=count+1;
        }
    b=b+1;
    }
    if (count==0)
        printf("%d\n",-1);
    x=x+1;
    }
}
