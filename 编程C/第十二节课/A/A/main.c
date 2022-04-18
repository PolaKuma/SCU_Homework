//
//  main.c
//  A
//
//  Created by Junjie on 2021/12/8.
//

#include <stdio.h>

struct Student {
       char name[20];
       int id;//学号
       int math;
       int chinese;
       int sum;//总分
}students[11];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&students[i].name);
        scanf("%d",&students[i].id);
        scanf("%d",&students[i].chinese);
        scanf("%d",&students[i].math);
        students[i].sum=students[i].chinese+students[i].math;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n-1;j++){
            if(students[j].sum>students[j+1].sum){
                struct Student temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(students[i].sum==students[i+1].sum){
            for(int j=i;j<n-1;j++){
                struct Student temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        printf("%s %d\n",students[i].name,students[i].sum);
    }
}
