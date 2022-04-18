//
//  main.c
//  A
//
//  Created by Junjie on 2021/11/10.
//

#include <stdio.h>

int Select(int n){
    if (n%2==1 && n!=1)
        n=n*3+1;
    return n;
}

int Count(int n){
    int count=0;
    if (n==1)
        count=0;
    else
        while (n!=1){
            n=n/2;
            n=Select(n);
            count++;
        }
    return count;
}
int main(){
    while (1){
        int n,count=0;
        scanf("%d",&n);
        if (n==0)
            return 0;
        else{
            if (n%2==1 && n!=1){
                n=n*3+1;
                count=Count(n);
            }
            else
                count=Count(n);
        }
        printf("%d\n",count);
    }
}
