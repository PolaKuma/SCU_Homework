//
//  main.c
//  hello
//
//  Created by Junjie on 2021/9/22.
//

#include <stdio.h>

int Min(int x,int y);
int Max(int x,int y);

int main()
{
    int a,b,c,d;
    scanf("%d,%d",&a,&b);
    c=Max(a,b);
    d=Min(a,b);
    printf("max=%d\n",c);
    printf("min=%d\n",d);
}

int Min(int x,int y)
{
    int z;
    if(x>y)
        z=y;
    else
        z=x;
    return(z);
}

int Max(int x,int y)
{
    int z;
    if (x>y)
        z=x;
    else
        z=y;
    return (z);
}
