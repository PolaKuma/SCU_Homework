//
//  main.c
//  作业2
//
//  Created by Junjie on 2021/9/29.
//

#include <stdio.h>

int main()
{
    double input;
    double output;
    printf("Fahrenheit is: ");
    scanf("%lf",&input);
    output=5.0/9*(input-32);
    printf("Celsius is %lf\n",output);
    return 0;
}
