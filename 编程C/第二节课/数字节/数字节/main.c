//
//  main.c
//  数字节
//
//  Created by Junjie on 2021/9/26.
//

#include <stdio.h>

int main()
{
    printf("The bytes of variables are:\n");
    printf("int:%lu bytes\n",sizeof(int));
    printf("char:%lu bytes\n",sizeof(char));
    printf("short:%lu bytes\n",sizeof(short));
    printf("long:%lu bytes\n",sizeof(long));
    printf("float:%lu bytes\n",sizeof(float));
    printf("double:%lu bytes\n",sizeof(double));
    printf("long double:%lu bytes\n",sizeof(long double));
}
