//
//  main.c
//  test
//
//  Created by Junjie on 2021/10/30.
//

#include<stdio.h>
#include<math.h>
#include<string.h>

int how,zero[10];          // 变量how表示放置的皇后种数，zero数组存放皇后的位置
int main() {
    void count(int* q, int length, int now);
    while (1) {
        int n, queen[10];   // n表示棋盘大小，queen是存放皇后的数组，最多十个皇后。
        scanf("%d", &n);  // 输入n
        if (n == 0) {       // 如果棋盘边长为0，则无法放置皇后
            break;          // 跳出循环
        }
        memset(zero, -1, sizeof(zero)); // 将zero数组中的值都初始化为-1
        how = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d",&queen[i]);    // 输入每列已有的皇后位置
            if (queen[i] == 0) {        // 如果皇后位置为0，表示这一列还没有皇后
                zero[i] = 0;            // 那么zero数组中对应的列值也为0
            }
        }
        count(queen, n, 0);             // 从第一列开始计算可放置皇后的方法数
        printf("%d\n", how);            // 输出该棋盘可放置皇后的方法种数
    }
    return 0;
}

// 比较两个数大小，输出较大的一个值
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else
    {
        return b;
    }
}

// 计算满足要求的情况数量
void count(int *q,int length,int now) {  // 函数变量：queen数组，棋盘大小，当前列值
    if (now == length) {         // 如果当前位置等于棋盘大小
        int var;                 // 设置整数变量
        for (var = 0; var < length-1&&pow(q[var]-q[var+1],2)<=1; var++) { // 从第一列开始遍历，如果每两个相邻列皇后之间的行距离大于1，则停止遍历
            ;
        }
        if (var == length - 1)how++;  // 如果停止遍历后的var正好等于length-1，即已经遍历完所有列，则说明这种放置皇后的方法是正确的，方法数加1
        return;
    }
    if (zero[now]==0) {          // 如果当前列没有皇后
        if (now==0)              // 如果是第一列
        {
            for (int j = 1; j <= length; j++) {  // 从第一列的每一行开始遍历
                q[now] = j;
                count(q, length, now + 1);       // 计算第一列皇后在第j行时，棋盘可放置皇后种数
            }
        }
        else {                   // 如果不是第一列，那么该列皇后的位置范围应为[前一列皇后位置-1，前一列皇后位置+1]
            for (int j = max(1,q[now-1]-1); j <= length&&j<=q[now-1]+1; j++) {  // max(1,q[now-1]-1) 是为了确保皇后位置最小是1
                q[now] = j;
                count(q, length, now + 1);  // 计算当前列皇后在第j行时，棋盘可放置皇后种数
            }
        }
    }
    else
    {
        count(q, length, now + 1);  // 当前列皇后已确定，计算后续列棋盘可放置皇后种数
    }
}


