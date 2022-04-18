//
//  main.c
//  B
//
//  Created by Junjie on 2021/12/30.
//

#include <stdio.h>

long long DG(long long n){
    if(n==0)
        return 1;
    else
        return n*(DG(n-1)%100000000);
}

int main(){
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        long long n,result=0;
        scanf("%lld",&n);
        if(n>24)
            n=24;
        for(long long j=0;j<n;j++){
            result+=DG(j+1);
            result=result%1000000;
        }
        printf("%lld\n",result);
    }
}
