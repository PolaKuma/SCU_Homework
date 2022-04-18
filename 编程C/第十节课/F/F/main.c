//
//  main.c
//  F
//
//  Created by Junjie on 2021/11/24.
//

#include <stdio.h>

long long DG(int n){
    if (n==0)
        return 1;
    else
        return n*DG(n-1);
}

int Fabonacci(unsigned int n){
    int a[10000]={1,1};
    int i;
    for (i=2;i<=n;i++){
    a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int i,m,n;
        long long sum=0;
        scanf("%d",&i);
        if (i<0)
            printf("%d\n",1);
        else{
        for (m=0;(i-m*2)/2!=0;m++){
            n=i-m*2;
            sum+=DG(m+n)/(DG(m)*DG(n));
        }
        sum+=DG(i-m)/(DG(m)*DG(i-m*2));
        printf("%lld\n",sum);
    }
    }
    return 0;
}
