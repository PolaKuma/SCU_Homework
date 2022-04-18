//
//  main.c
//  A
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

int main(){
    int n=-1;
    while(scanf("%d",&n) != EOF){
        printf("%lld\n",DG(n));
}
}


