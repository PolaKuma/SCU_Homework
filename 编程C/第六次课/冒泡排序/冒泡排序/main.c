//
//  main.c
//  冒泡排序
//
//  Created by Junjie on 2021/10/27.
//

#include <stdio.h>
int sortBubble(int a[],int n);
int Select_sort(int a[],int n);
int FindFirst(int a[],int n,int value);


int main(){
    int a[128];
    int value,count=-1,x,i=0;
    do{
        x=getchar();
        if (x!=' '){
        count+=1;
        a[i]=x;
        i=i+1;
        }
    }while(x!='\n');
    scanf("%d",&value);
    printf("%d\n",FindFirst(a, count, value));
}

int sortBubble(int a[],int n){
    int i;
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    //输入10位整数
    for (i=0;i<n-1;i++){
        int j;
        for (j=0;j<n-i-1;j++){
            int test=a[j+1];
            if (a[j]>a[j+1]){
                a[j+1]=a[j];
                a[j]=test;
            }
        }
    }
    //排序
    return 0;
}

int Select_sort(int a[],int n){
    int i,j,max=-1,x=-1,m=-1;
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (i=n-1;i>0;i--){
        for (j=0;j<n-1;j++){
            if (a[i]>a[i+1]){
                max=a[i];
                m=i;
            }
            else
                max=a[i+1];
                m=i+1;
    }
        x=a[i];
        a[i]=max;
        a[m]=x;
    }
    return 0;
    //找到最大值，与最后一项交换
}

int FindFirst(int a[],int n,int value){
    int place=-1,i;
    for (i=0;i<n;i++){
        if (a[i]==value){
            place=i;
        }
    }
    return place;
}
