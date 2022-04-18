//
//  main.c
//  冒泡排序
//
//  Created by Junjie on 2021/10/27.
//

#include <stdio.h>
int sortBubble(int a[],int n);//普通数组冒泡排序
int sortBubble2(int *a,int n);//运用指针版冒泡排序
int Select_sort(int a[],int n);//选择排序
int FindFirst(int a[],int n,int value);//查找指定的值的下标
int findFirst(int a[],int n,int value);//二分法查找符合条件的项下标
int swap(int *a,int *b);//交换两个变量地址指向的值
int Invert(int arr[],int n);//逆向改变数组顺序
int Invert2(int arr[],int n);//用指针方式逆向改变数组顺序
int Average(int a[],int n);//输入一个班的某门课程的成绩，将成绩从高到低输出，并输出平均分

int sortBubble(int a[],int n){
    int i;
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
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
    return 0;
}
//普通数组冒泡排序

int sortBubble2(int *a,int n){
    int i;
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (i=0;i<n-1;i++){
        int j;
        for (j=0;j<n-i-1;j++){
        if (*(a+j)>*(a+j+1)){
            int temp;
            temp=*(a+j);
            *(a+j)=*(a+j+1);
            *(a+j+1)=temp;
        }
    }
}
    return 0;
}
//运用指针版冒泡排序

int Select_sort(int a[],int n){
    int i,j,t;
    for(i=0;i<n;i++){
        for (j=i+1;j<=n-1;j++)
        if (a[i]>a[j])
                {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
                }
    }
    return 0;
}
//选择排序

int FindFirst(int a[],int n,int value){
    int place=-1,i;
    for (i=0;i<n;i++){
        if (a[i]==value){
            place=i;
        }
    }
    return place;
}
//查找指定的值的下标

int findFirst(int a[], int n, int value){
    int min=0,max=n;
    int mid=(min+max)/2;
    if (a[mid] == value){
        return mid-1;
    }
    else{
        while (a[mid] != value){
            if (a[mid] > value){
                 mid=(mid+min)/2;
            }
            else
                 mid=(mid+max)/2;
        }
    }
    return mid-1;
}
//二分法查找符合条件的项下标

int swap(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
    return 0;
}
//交换两个变量地址指向的值

int Invert(int arr[],int n){
    int i;
    for (i=0;i<=n/2;i++){
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    return 0;
    }
//逆向改变数组顺序

int Invert2(int *x,int n){
    int *p,*i,*j,temp;
    int m=(n-1)/2;
    i=x;
    j=x+n-1;
    p=x+m;
    for (;i<=p;i++,j--){
        temp=*i;
        *i=*j;
        *j=temp;
    }
    return 0;
}
//用指针方式逆向改变数组顺序

int Average(int a[],int n){
    int i,sum=0,average=0;
    sortBubble(a, n);
    Invert(a, n);
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
        sum=sum+a[i];
    }
    printf("\n");
    average=sum/n;
    printf("The Average is %d\n",average);
    return 0;
}
//输入一个班的某门课程的成绩，将成绩从高到低输出，并输出平均分
