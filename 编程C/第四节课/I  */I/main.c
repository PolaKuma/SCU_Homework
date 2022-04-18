//
//  main.c
//  I
//
//  Created by Junjie on 2021/10/15.
//

#include <stdio.h>

int main(){
    int m=-1,q;
    scanf("%d",&m);
    for (q=0;q<m;q++){
    int a[100];
    int n,i;
    int h=-1;
    fflush(stdin);
    scanf("%d",&a[0]);
    n=a[0];
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
        if (n==1){
            printf("ERROR\n");
        }
        else{
    int j=-1,min=a[n];
    for (j=n;j>=1;j--){
        if (min<a[j-1]){
            min=min;
        }
        else
            min=a[j-1];
    }
    int max=a[n];
    for (j=n;j>=1;j--){
        if (max>a[j]){
            max=max;
        }
        else
            max=a[j];
    }
    for (j=n;j>1;j--){
        if (a[j-1]==min){
            a[j-1]=max;
        }
        else
            a[j-1]=a[j-1];
    }
    int min2=a[n-1];
    for (j=n;j>1;j--){
        if (min2<a[j-1]){
            min2=min2;
        }
        else
            min2=a[j-1];
    }
        for (j=n;j>1;j--){
            if (a[j-1]==min2){
                a[j-1]=max;
            }
            else
                a[j-1]=a[j-1];
        }
        for (j=n;j>1;j--){
            if (min2==a[j-1]){
                h=1;
                break;
            }
            }
        if (h==1){
            printf("ERROR\n");
        }
        else
            printf("%d\n",min2);
        }
    }
}


int way2(){
    int c,n;
    int num;
    scanf("%d\n",&c);
    while(c--){ //c组测试数据
    scanf("%d\n",&n);  //每组测试数据有n个数字
    int  min1=101;
    int min2 =102;
    for(int i =0;i<n;i++){
        scanf("%d",&num);    //输入数字
        if(num < min1){
            min2 = min1;
            min1 = num;
        }
        else if(num <min2 && num != min1){
            min2 =num;
        }
                    
    }
   

if(min1==min2 || min2==101 ||min2 ==102)printf("NO\n");
else
     
     
     printf("%d\n",min2);
         
    }
    
    
return 0;
}

int way3(){
    //重新修订
        int n,i;
        scanf("%d",&n);
        for (i=0;i<n;i++){
            int a[100]={0};
            int q;
            scanf("%d",&a[0]);
            for (q=1;q<=a[0];q++){
                scanf("%d",&a[q]);
            }
            int j;
            int min1=101,min2=102;
            for (j=1;j<=a[0];j++){
                if (a[j]<min1){
                    min1=a[j];
                }
                else
                    min1=min1;
            }
            for (j=1;j<=a[0];j++){
                if (min2>a[j] && a[j]!=min1){
                    min2=a[j];
                }
                else
                    min2=min2;
            }
            if ((min2==102) || (min1==101) || (min1==min2)){
                printf("ERROR\n");
            }
            else
                printf("%d\n",min2);
        }
    }
