//
//  main.c
//  A
//
//  Created by Junjie on 2021/10/20.
//

#include <stdio.h>

int main(){
    int m=0,n=-1,q;
    int a[100]={0};
    scanf("%d",&n);
    for (q=0;q<n;q++){
        scanf("%d",&a[q]);
    }
    scanf("%d",&m);
    int i,j=0;
    for (i=0;i<n;i++){
        if (a[i]==m){
            printf("%d ",i);
            j=1;
        }
    }
    if (j==0){
        printf("%d",-1);
    }
}
