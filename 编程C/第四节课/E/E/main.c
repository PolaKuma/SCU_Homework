//
//  main.c
//  E
//
//  Created by Junjie on 2021/10/14.
//

#include <stdio.h>

int main(){
    int n=-1;
    while (n!=0){
    scanf("%d",&n);
    if (n>0 && n<=20){
    int a[20];
    int i,j;
    
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
        //读入数字
    
    for (j=n-1;j>=0;j--){
        printf("%d ",a[j]);
        }
        printf("\n");
    }
        //读出数字
        
    else if (!n)
    {
        printf("End Of Input\n");
        break;
    }
        //程序结束
        
    else
        printf("Input Error\n");
    }
    //错误输入
}

