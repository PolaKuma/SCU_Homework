//
//  main.c
//  D
//
//  Created by Junjie on 2021/11/18.
//

#include <stdio.h>

int Length(char a[5000]){
    int place;
    for (place=4999;a[place]=='!'||a[place]=='\0';place--);
    return place+1;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        char a[5000]={0},b[5000]={0};
        int result[9999]={0};
        int place=9998,count=0,d=0,x=0,ben;
        for (int j=0;j<5000;j++){
            a[j]='!'; b[j]='!';
        }
        scanf("%s %s",&a,&b);
        for (int j=Length(b);j>0;j--,x++){
            place=9998-x; d=0;
            for (int k=Length(a);k>0;k--){
                ben=(a[k-1]-'0')*(b[j-1]-'0')+result[place]+d;
                result[place]=ben%10;
                place--;
                d=ben/10;
            }
            if (d>0)
                result[place]=d;
        }
        for(;result[count]==0;count++);
        for (int i=count;i<9999;i++){
            printf("%c",result[i]+'0');
        }
        printf("\n");
    }
}
