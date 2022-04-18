//
//  main.c
//  E
//
//  Created by Junjie on 2021/11/24.
//

#include <stdio.h>

int sortBubble(int *a,int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n-i;j++){
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

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int even[500]={0},odd[500]={0},num,j1=0,j2=0;
        char ch;
        do{
            scanf("%d",&num);
            if (num%2==0){
                *(even+j1)=num;
                j1++;
            }
            else{
                *(odd+j2)=num;
                j2++;
            }
        }while ((ch=getchar())!='\n');
        sortBubble(even,j1-1);
        sortBubble(odd,j2-1);
        for (int j=0;j<j2;j++){
            printf("%d ",*(odd+j));
        }
        for (int j=0;j<j1;j++){
            printf("%d ",*(even+j));
        }
        printf("\n");
    }
}
