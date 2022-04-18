//
//  main.c
//  B
//
//  Created by Junjie on 2021/10/20.
//

#include <stdio.h>

int main(){
    int n,i,j;
    int a=1,b=2,q=1,x=1;
    scanf("%d",&n);
        for (i=0;i<=n;i++){
            for (j=n;j>i;j--){
        printf("%d ",q);
        q=q+b;
        b=b+1;
            }
            if (n==i){
                break;
            }
            printf("\n");
            a=a+x;
            x=x+1;
            q=a;
            b=3+i;
        }
}
