//
//  main.c
//  D
//
//  Created by Junjie on 2021/12/8.
//

#include <stdio.h>

void DG(int num[],int tag[],int n,int len){//????
    if(len==n){
        printf("--> ");
        for(int i=0;i<len;i++){
            if(tag[i]==1)
                printf("%d ",num[i]);
        }
        printf("\n");
        return;
    }
    tag[n]=1;
    DG(num,tag,n+1,len);
    tag[n]=0;
    DG(num,tag,n+1,len);
}
int main(){
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int n;
        int num[100]={0},tag[100]={0};
        scanf("%d",&n);
        for(int j=0;j<n;j++){//存放之后数字
            scanf("%d",&num[j]);
        }
        DG(num,tag,0,n);
    }
}
