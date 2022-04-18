//
//  main.c
//  A
//
//  Created by Junjie on 2021/11/3.
//

#include <stdio.h>

long long m(long long a){
    if (a<0)
        return -a;
    else
        return a;
}

int main(){
    long long a[10001]={0};
    long long n,i,j,d,sum=0;
    scanf("%lld",&n);
    for (i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for (i=0;i<n;i++){
        for (j=i;j<n;j++){
            d=m(a[j]-a[i]);
            sum+=d;
        }
    }
    printf("%lld",sum);
}
