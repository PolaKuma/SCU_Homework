//
//  main.c
//  C
//
//  Created by Junjie on 2021/10/27.
//

#include <stdio.h>

int main(){
    int n,i,j,x;
    int a[100]={0};
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (x=0;x<n-1;x++){
    for (i=0;i<n-1;i++){
        for (j=0;j<n-1;j++){
            if (a[j]>a[j+1]){
                int min=a[j+1];
                a[j+1]=a[j];
                a[j]=min;
            }
        }
        for (i=0;i<n;i++){
            printf("%d ",a[i]);
        }
            printf("\n");
    }
    }
}
