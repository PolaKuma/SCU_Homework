//
//  main.c
//  二维数组
//
//  Created by Junjie on 2021/11/24.
//

#include <stdio.h>
#include <string.h>

/*int main(){
    int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
    printf("%d,%d\n",a,*a);
    printf("%d,%d\n",a[0],*(a+0));
    printf("%d,%d\n",&a[0],&a[0][0]);
    printf("%d,%d\n",a[1],a+1);
    printf("%d,%d\n",&a[1][0],*(a+1)+0);
    printf("%d,%d\n",a[2],*(a+2));
    printf("%d,%d\n",&a[2],a+2);
    printf("%d,%d\n",a[1][0],*(*(a+1)+0));
    getchar();
}*/

/*int main(){
    int score[3][4]={{65,57,70,60},{58,87,90,81},{90,99,100,98}};
    searchPrint(score, 3);
}*/

/*int main(){
    char *name[]={"Follow me","BASIC","Great Wall","FORTRAN","Computer design"};
    int n=5;
    sort(name,n);
    print(name,n);
}*/

int Average(int *score){
    int sum=0;
    for (int i=0;i<12;i++){
        sum+=*(score+i);
    }
    return sum/12;
}

int Average2(int **score,int m,int n){
    int sum=0,i;
    for (i=0;i<m*n;i++){
        sum+=*(*score+i);
    }
    return sum/i;
}

int printScore(int score[][4],int n){
    for (int i=0;i<4;i++){
        printf("%d ",*(*(score+n-1)+i));
    }
    return 0;
}

void searchPrint(int(*p)[4],int n){
    for (int i=0;i<n*4;i++){
        if (*(*p+i)<60){
            for (int j=0;j<4;j++){
                printf("%d ",*(*(p+i/4)+j));
            }
            i=(i/4+1)*4-1;
            printf("\n");
        }
    }
}

void sort(char *name[],int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
        if (strcmp(name[j],name[j+1])>0){
            char *temp;
            temp=*(name+j+1);
            *(name+j+1)=*(name+j);
            *(name+j)=temp;
        }
        }
    }
}

void sort_teacher(char *name[],int n){
    char *temp;
    int i,j,k;
    for (i=0;i<n-1;i++){
        k=i;
        for (j=i+1;j<n;j++){
            if (strcmp(name[k], name[j])>0)
                k=j;
        }
        if (k!=j){
            temp=name[i]; name[i]=name[k]; name[k]=temp;
        }
    }
}

void print(char *name[],int n){
    for (int i=0;i<n;i++){
        printf("%s\n",name[i]);
    }
}
