//
//  main.c
//  B
//
//  Created by Junjie on 2021/11/17.
//

#include <stdio.h>

int main(){
    int m,n,p,q;
    int c[11][11]={0};
    scanf("%d %d %d %d",&m,&n,&p,&q);
        int a[11][11]={0},b[11][11]={0};
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for (int i=0;i<p;i++){
            for (int j=0;j<q;j++){
                scanf("%d",&b[i][j]);
            }
        }
    if (n==p){
    for (int i=0;i<11;i++){
            for (int j=0;j<11;j++){
                for (int k=0;k<11;k++){
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        for (int i=0;i<m;i++){
            for (int j=0;j<q;j++){
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("error\n");
}
