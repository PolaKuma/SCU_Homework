//
//  main.c
//  C
//
//  Created by Junjie on 2021/11/24.
//

#include <stdio.h>

int Convert(int a,int b){
    int sum=0;
    while(a!=0){
        sum=10*sum+a%b;
        a=a/b;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",Convert(a,b));
    }
}
