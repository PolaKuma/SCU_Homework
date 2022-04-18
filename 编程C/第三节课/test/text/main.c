//
//  main.c
//  text
//
//  Created by Junjie on 2021/9/29.
//

#include <stdio.h>

int main()
{
    int a=5;
    int b,c;
    int i=10;
    b=a++;
    c=++b;
    
    printf("a=%d b=%d c=%d\n",a,b,c);
    printf("%d\n",++i);
    printf("%d\n",--i);
    printf("%d\n",i++);
    printf("%d\n",i--);
    printf("%d\n",-i++);
    printf("%d\n",-i--);
    getchar();
}
