//
//  main.c
//  A
//
//  Created by Junjie on 2021/12/26.
//

#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char a[100]={0};
        scanf("%s",a);
        for(int j=0;j<strlen(a);j+=2){
            int x=0;
            if(a[j]>='0'&&a[j]<='9'){
                x+=(a[j]-'0')*16;
            }
            else{
                x+=(a[j]-'A'+10)*16;
            }
            if(a[j+1]>='0'&&a[j+1]<='9'){
                x+=(a[j+1]-'0');
            }
            else{
                x+=a[j+1]-'A'+10;
            }
            printf("%c",x);
        }
        printf("\n");
    }
}
