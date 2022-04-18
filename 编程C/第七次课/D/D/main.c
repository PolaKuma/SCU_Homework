//
//  main.c
//  D
//
//  Created by Junjie on 2021/11/3.
//

#include <stdio.h>

int Output(float a[]){
    int i;
    for (i=5;i<10;i++){
        printf("%d ",(int)a[i]);
    }
    printf("\n");
    return 0;
}
//输出数列的值

int Select(float a[]){
    int s=0,i;
    for (i=0;i<5;i++){
        if (a[i]!=0)
            s=1;
    }
    return s;
}
//判断0 0 0 0 0情况

int main(){
    int s=1;
    while (s==1){
    float a[10]={0};
    int i;
    for (i=0;i<5;i++){
        scanf("%f",&a[i]);
    }
    //输入数列
    s=Select(a);
        if (s==0)
            return 0;
        else{
            int m=a[1]-a[0];
    if (a[2]-a[1]==m && a[3]-a[2]==m && a[4]-a[3]==m){
        printf("case one\n");
        for (i=5;i<10;i++){
            a[i]=a[i-1]+a[3]-a[2];
        }
        Output(a);
    }
            int x=0;
            for (i=1;i<4;i++){
                float q=a[i+1]/a[i],p=a[i]/a[i-1];
                x=p-q <0.000000001;
            }
            //不能用==比较大小故用浮点数相减小于一定值解决
        if (x==1){
        printf("case two\n");
        for (i=5;i<10;i++){
            a[i]=a[i-1]*(a[3]/a[2]);
        }
        Output(a);
    }
    if (a[3]==a[2]+a[1]){
        printf("case three\n");
        for (i=5;i<10;i++){
            a[i]=a[i-1]+a[i-2];
        }
        Output(a);
    }
        }
    }
}
