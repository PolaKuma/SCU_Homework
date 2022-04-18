//
//  main.c
//  length
//
//  Created by Junjie on 2021/9/22.
//

#include <stdio.h>

int main()
{
    double radius,area,perimtr;
    printf("the radius is ");
    scanf("%lf",&radius);
    
    perimtr=2.0*3.1415926*radius;
    area=radius*radius*3.1415926;
    
    printf("the perimtr is %lf\n",perimtr);
    printf("the area is %lf\n",area);
    
    return 0;
}
