//
//  main.c
//  D
//
//  Created by Junjie on 2021/10/27.
//

#include <stdio.h>

int main(){
    int a[100000]={0};
    int m,i=0,x=0,j=0,n,q=0,k;
    scanf("%d",&n);
    for (q=0;q<n;q++){
    scanf("%d%d",&m,&k);
        if (k>m){
            printf("error\n");
        }
        else{
    for (i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
            int count=0;
            int b[100000]={0};
            for (i=0;i<m;i++){
                b[a[i]]+=1;
            }
            for (i=0;i<m+1;i++){
                if (b[i]!=0){
                    count+=1;
                }
            }
            if (count<k){
                printf("error\n");
            }
            else{
    for (x=0;x<m-1;x++){
    for (i=0;i<m-1;i++){
        for (j=0;j<m-1;j++){
            if (a[j]>a[j+1]){
                int min=a[j+1];
                a[j+1]=a[j];
                a[j]=min;
            }
        }
    }
    }
            printf("%d\n",a[m-k]);
            }
}
}
}
