//
//  main.c
//  比较浮点数大小
//
//  Created by Junjie on 2021/9/26.
//

#include <stdio.h>

float main()
{
    float x,y,z;
    printf("Input two numbers ");
    scanf("%f%f",&x,&y);
    z=x>y?x:y;
    printf("MAX of (%f  %f) is %f\n",x,y,z);
    return 0;
}
