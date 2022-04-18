//
//  main.c
//  B
//
//  Created by Junjie on 2021/11/24.
//

#include <stdio.h>

int DG(int n){
    if (n==0)
        return 1;
    else
        return n*DG(n-1);
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        printf("%d\n%d %d\n",1,1,1);
        for (int j=2;j<num;j++){
            for (int k=0;k<j+1;k++){
                printf("%d ",(DG(j)/DG(j-k))/DG(k));
            }
            printf("\n");
        }
    }
}
