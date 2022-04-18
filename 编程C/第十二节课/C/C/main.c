//
//  main.c
//  C
//
//  Created by Junjie on 2021/12/8.
//

#include <stdio.h>
#include <string.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char words1[101][20]={0},words2[101][20]={0};
    for(int i=0;i<n;i++){
        scanf("%s",&words1[i]);
    }
    for(int i=m,j=0;i<n;i++,j++){
        strcpy(words2[i],words1[j]);
    }
    for(int i=n-m,j=0;i<n;i++,j++){
        strcpy(words2[j],words1[i]);
    }
    for(int i=0;i<n;i++){
        printf("%s ",words2[i]);
    }
}
