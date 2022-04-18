//
//  main.c
//  B
//
//  Created by Junjie on 2021/10/14.
//

#include <stdio.h>

int main(){
    int a,b,c;
    int n,i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
    scanf("%d %d",&a,&b);
    if (a>=b){
        c=b;
        while (a%c!=0 || b%c!=0)
            c=c-1;
            }
    else
        c=a;
        while (a%c!=0 || b%c!=0)
            c=c-1;
    printf("%d\n",c);
    }
}
