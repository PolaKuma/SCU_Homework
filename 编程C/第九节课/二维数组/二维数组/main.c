//
//  main.c
//  二维数组
//
//  Created by Junjie on 2021/11/24.
//

#include <stdio.h>

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

int Average(int *score){
    int sum=0;
    for (int i=0;i<12;i++){
        sum+=*(score+i);
    }
    return sum/12;
}

int printScore(int score[][4],int n){
    for (int i=0;i<4;i++){
        printf("%d ",*(*(score+n-1)+i));
    }
    return 0;
}

int main(){
    int score[3][4]={0};
    int n;
    scanf("%d",&n);
    for (int i=0;i<12;i++){
        scanf("%d",*score+i);
    }
    Average(*score);
    printScore(score, n);
    return 0;
}
