//
//  main.c
//  D
//
//  Created by Junjie on 2022/1/3.
//

#include <stdio.h>

int main(){
    int x,h;
    int X[101][101]={0},H[101][101]={0},result[101][101]={0};
    scanf("%d %d",&x,&h);
    for(int i=0;i<x*x;i++)  //输入卷积数组
        scanf("%d",&X[i/x+(h-1)/2][i%x+(h-1)/2]);   //预先扩大卷积数组
    for(int i=0;i<h;i++){   //输入并翻转卷积核
        for(int j=0;j<h;j++)
            scanf("%d",&H[h-1-i][h-1-j]);
    }
    for(int i=0;i<x;i++){   //计算（映射法）（i为结果排数，j为结果纵数，q为映射排数，p为映射纵数）
        for(int j=0;j<x;j++){
            int temp[101][101]={0};
            for(int q=0;q<h;q++){
                for(int p=0;p<h;p++){   //取相应映射区域的卷积数组并与卷积核相乘（可以直接相乘，不需要temp数组）
                    temp[q][p]=X[q+i][p+j];
                    result[i][j]+=temp[q][p]*H[q][p];
                }
            }
        }
    }
    for(int i=0;i<x;i++){   //输出
        for(int j=0;j<x;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}
