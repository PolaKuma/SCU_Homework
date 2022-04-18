//
//  main.c
//  G
//
//  Created by Junjie on 2021/12/21.
//

#include <stdio.h>

// 以左下为(0,0)，从(x,y)处皇后到(x_, y_处皇后，在n*n的棋盘上的解法数量
int way(int x, int y, int x_, int y_, int n){
    if(y_ < 0 || y_ > n - 1 || (x_ == (x + 1) && (y_ > (y + 1) || y_ < (y - 1)))){
        return 0;
    }else if(x_ == (x + 1)){
        return 1;
    }else{
        return way(x, y, x_ - 1, y_ + 1, n) + way(x, y, x_ - 1, y_ - 1, n) + way(x, y, x_ - 1, y_, n);
    }
}

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        else{
            int a[11]={0};
            int x=1;
            int flag=1;
            for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
            }
    
            for(int i=0;i<n;i++){//判断已有皇后摆法
                if(a[i]==0 || a[i+1]==0){
                    for(;a[i+1]==0 && i<n;i++);
                }
                if((a[i-1]-a[i]>1 || a[i-1]-a[i]<-1) && i!=n){
                    printf("%d\n",0);
                    flag=0;
                    break;
                }
            }
            
            for(int i=0;i<n;i++){
                int j=i;
                if(a[i]==0){
                    for(;a[j]==0;j++);
                    x=x*way(i-1,n-a[i-1]-1,j,n-a[j]-1,n);
                }
                i=j;
            }
            if(flag==1)
            printf("%d\n",x);
        }
    }
}
