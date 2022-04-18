//
//  main.c
//  B
//
//  Created by Junjie on 2021/11/3.
//

#include <stdio.h>

int main(){
    int i;
    char a[100]={0};
    gets(a);
    for (i=0;i<100;i++){
        if (a[i]>96 && a[i]<123){
            printf("%c",a[i]-32);
        }
        else if (a[i]>64 && a[i]<91){
            printf("%c",a[i]+32);
        }
        else if (a[i]!=0)
            printf("^_^");
    }
}
