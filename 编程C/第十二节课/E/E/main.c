//
//  main.c
//  E
//
//  Created by Junjie on 2021/12/8.
//

#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char num[1001][128]={0};//注意，如果之后要用原来数组存储转换后01串，需要开大一点
    char N[8001]={0};
    scanf("%d",&n);
    for(int i=0;i<n/8;i++){//将整数化为二进制数保存
        int m;
        scanf("%d",&m);
        for(int j=7;j>=0;j--){
            num[i][j]=(m%2)+'0';
            m=m/2;
        }
    }
    for(int i=0;i<n/8;i++){//将二进制数合并为一个长的
        strcat(N,num[i]);
    }
    int count1=0;
    for(int i=0;N[i]!='\0';i++){//分割字符串
        int count=0;
        char temp[8001]={0};
        while(N[i]==N[i+1]){//检测01分割位置
            temp[count]=N[i];
            count++;
            i++;
        }
        temp[count]=N[i];//还要加上i后一位
        strcpy(num[count1],temp);
        count1++;
    }
    for(int i=0;i<count1;i++){//输出
        if(num[i][0]=='1')
            printf("%lu ",strlen(num[i])+128);
        else
            printf("%lu ",strlen(num[i]));
    }
}
