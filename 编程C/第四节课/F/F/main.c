//
//  main.c
//  F
//
//  Created by Junjie on 2021/10/14.
//

#include <stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    for (i=0;i<n;i++){
    float a,b,c,d,e,f,g,h;
    scanf("%f %f %f %f %f %f",&a,&b,&c,&d,&e,&f);
    g=(a+b+c+d+e+f)/6;
    h=((a-g)*(a-g)+(b-g)*(b-g)+(c-g)*(c-g)+(d-g)*(d-g)+(e-g)*(e-g)+(f-g)*(f-g))/6;
    printf("%.2f %.2f\n",g,h);
    }
}
