//
//  main.c
//  A
//
//  Created by Junjie on 2021/12/1.
//

#include <stdio.h>
#include <string.h>

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
    struct{
        char a[51];
        int x;
    }num[101];
    
    for(int i=0;i<m;i++){
        scanf("%s",&num[i].a);
        num[i].x=0;
        }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                if(num[i].a[j]>num[i].a[k]){
                    num[i].x++;
                }
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m-i-1;j++){
            char temp[100]={0};
            if(num[j].x>num[j+1].x){
                strcpy(temp,num[j+1].a);
                strcpy(num[j+1].a,num[j].a);
                strcpy(num[j].a,temp);
                int ch=num[j+1].x;
                num[j+1].x=num[j].x;
                num[j].x=ch;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        printf("%s",num[i].a);
        printf("\n");
    }
    printf("********************\n");
    }
}
