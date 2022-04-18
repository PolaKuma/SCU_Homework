//
//  main.c
//  C
//
//  Created by Junjie on 2021/11/3.
//

#include <stdio.h>

int main(){
    int i,exit=1;
    char b[5]={'e','x','i','t',0};
    //b数组作为中介与a数组比对判断结束
    
    do{
    char a[100]={0};
    gets(a);
    //输入a数组，包含空格
    for (i=0;i<5;i++){
        if (a[i]!=b[i])
            exit=0;
        else
            exit=1;
    }
        if (exit==1){
            break;
        }
    //填入exit退出程序
    
    int count0=0,count1=0,count2=0,count3=0;
    for (i=0;i<100;i++){
        if (a[i]>96 && a[i]<123){
                   count2+=1;
               }
        //小写字母个数
        
        else if (a[i]>64 && a[i]<91){
                    count1+=1;
                }
        //大写字母个数
        
        else if (a[i]>47 && a[i]<58){
            count0+=1;
        }
        //阿拉伯数字个数
        
        else if (a[i]!=0){
            count3+=1;
        }
        //其他字符个数
    }
    printf("%d,%d,%d,%d,\n",count0,count1,count2,count3);
    }while (exit==0);
    //数数并输出（主要）
    
    printf("End Of Input\n");
    //退出程序时结束语句
}
