//
//  main.c
//  B
//
//  Created by Junjie on 2021/11/10.
//

#include <stdio.h>

int Rn(int x,int a[]){
    if (a[0]%400==0 || (a[0]%4==0 && a[0]%100!=0))
        return x+a[2]+1;
    else
        return x+a[2];
}

int main(){
    int n,i,sum=0;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        int a[3]={0};
        int j;
        for (j=0;j<3;j++){
            scanf("%d",&a[j]);
        }
        switch (a[1]){
            case 1:sum=a[2]; break;
            case 2:sum=31+a[2]; break;
            case 3:sum=Rn(59,a); break;
            case 4:sum=Rn(90,a); break;
            case 5:sum=Rn(120,a); break;
            case 6:sum=Rn(151,a); break;
            case 7:sum=Rn(181,a); break;
            case 8:sum=Rn(212,a); break;
            case 9:sum=Rn(243,a); break;
            case 10:sum=Rn(273,a); break;
            case 11:sum=Rn(304,a); break;
            case 12:sum=Rn(334,a); break;
        }
        printf("%d\n",sum);
}
}
