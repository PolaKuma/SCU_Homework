//
//  main.c
//  B
//
//  Created by Junjie on 2021/12/22.
//

#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char a1[503]={0},b1[503]={0};
        char a[503]={0},b[503]={0};
        int c[503]={0},place=0;
        for(int j=0;j<503;j++){//重置数组
            a[j]='0';
            b[j]='0';
        }
        scanf("%s %s",a1,b1);
        if(a1[0]=='0'&&b1[0]=='0'){
            printf("0\n");
        }else{
        for(int j=0;j<strlen(a1);j++){//存数字入数组中（字符串形式）
            a[502-j]=a1[strlen(a1)-1-j];
        }
        for(int j=0;j<strlen(b1);j++){
            b[502-j]=b1[strlen(b1)-1-j];
        }
        for(int j=502;j>0;j--){//得到相加数组
            c[j]=(a[j]-'0')+(b[j]-'0');
        }
        for(int j=502;j>1;j--){//进位计算
            int cout=0;
            cout=c[j]/10;
            c[j]=c[j]%10;
            c[j-1]+=cout;
        }
        for(place=0;c[place]==0;place++);
        for(int j=place;j<503;j++){
            printf("%c",c[j]+'0');
        }
        printf("\n");
        }
    }
}
