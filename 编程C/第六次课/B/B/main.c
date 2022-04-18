//
//  main.c
//  B
//
//  Created by Junjie on 2021/10/27.
//

#include <stdio.h>
#include <string.h>

int findString(char stringArray[][100], char targetString[1][100], int n) ;

int main(){
   char stringArray[10][100];
   char targetString[1][100];
    int n;
    scanf("%d",&n);
    int count=findString(stringArray, targetString, n);
    printf("%d",count);
}

int findString(char stringArray[][100], char targetString[1][100], int n) {
    int i,count=0;
    for (i=0;i<n;i++){
        scanf("%s",stringArray[i]);
    }
    scanf("%s",targetString[1]);
    for (i=0;i<n;i++){
        int m=strcmp(stringArray[i], targetString[1]);
        if (m==0){
            count+=1;
        }
    }
    return count;
}
