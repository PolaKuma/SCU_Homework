//
//  main.c
//  D
//
//  Created by Junjie on 2021/10/20.
//

#include <stdio.h>

int ysf(int n,int m,int q){
    if (n==q)
        return (q-1)*((m +1)%2);
    else
        return (ysf(n-1,m,q)+m)%n;
}

int main(){
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    int result1=ysf(n,m,1)+k,result2=ysf(n,m,2)+k;
    if (result2<result1)
        printf("%d %d",result2,result1);
    else
        printf("%d %d",result1,result2);
}
