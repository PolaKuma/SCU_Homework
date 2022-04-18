//
//  main.c
//  D
//
//  Created by Junjie on 2021/11/24.
//

#include <stdio.h>
#include <string.h>

int mystrstr(char a[],char b[]){
    int lengthb=0,lengtha=0,flag=-1;
    for (lengtha=0;a[lengtha]!='\0';lengtha++);
    for (lengthb=0;b[lengthb]!='\0';lengthb++);
    for (int i=0;i<lengtha+1;i++){
        if (a[i]==b[0]){
            char c[501]={0};
            int place=i;
            for (int j=0;j<lengthb;j++){
                c[j]=a[place];
                place++;
            }
            if (strcmp(b,c)==0)
                flag=1;
        }
        if (flag==1){
            return i;
            break;
        }
    }
    return -1;
}

int main(){
    char a[501]={0},b[501]={0};
    gets(a);
    gets(b);
    printf("%d\n",mystrstr(a, b));
}
