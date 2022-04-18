//
//  main.c
//  A
//
//  Created by Junjie on 2021/10/27.
//

#include <stdio.h>

int main(){
    int n,i=-1,num;
    int count[128]={0};
    scanf("%d",&n);
    do{
        scanf("%d",&num);
        count[num]+=1;
        i+=1;
    }while (i<n-1);
    for (i=0;i<128;i++){
        if (count[i]==1){
            printf("%d",i);
        }
    }
}
