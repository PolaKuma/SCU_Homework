//
//  main.c
//  C
//
//  Created by Junjie on 2021/10/14.
//

#include <stdio.h>

int main(){
    int n,i;
    scanf("%d",&n);
    for (i=0;i<n;i++){
    int year;
    scanf("%d",&year);
    if (year%4==0 && year%100 != 0 && year>0)
        printf("yes\n");
    else if (year%400==0 && year>0)
        printf("yes\n");
    else
        printf("no\n");
    }
}
