//
//  main.c
//  大写转小写
//
//  Created by Junjie on 2021/9/26.
//

#include <stdio.h>

int f(int c1);

int main()
{
    char a,b;
    printf("Input: ");
    scanf("%c",&a);
    b=f(a);
    printf("Result: %c\n",b);
}

int f(int a)
{
    char b;
    b=a-32;
    return b;
}
