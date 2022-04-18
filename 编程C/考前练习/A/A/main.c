//
//  main.c
//  A
//
//  Created by Junjie on 2021/12/30.
//

#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m;
        int a[1001]={0};
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            int count=0;
            scanf("%d",&count);
            a[count]++;
        }
        for(int j=0;j<1001;j++){
            if(a[j]>0)
                printf("%d ",j);
        }
        printf("\n");
    }
}
