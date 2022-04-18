//
//  main.c
//  C
//
//  Created by Junjie on 2021/10/20.
//

#include <stdio.h>

int main(){
    int n,i;
    int result=0;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        int a,b,c,r1,d,e,f,r2,x,y,z;
        scanf("%d %d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&r1,&d,&e,&f,&r2,&x,&y,&z);
        if ((x-a)*(x-a)+(y-b)*(y-b)+(z-c)*(z-c)-(x-d)*(x-d)-(y-e)*(y-e)-(z-f)*(z-f)==r1*r1-r2*r2){
            result=1;
        }
        if (result==1){
                printf("No\n");
            }
            else
                printf("Yes\n");
            result=0;
        }
}

float l(float x){
    return x*x;
}

int m(){
    int n, x_, y_, z_, r1, x, y, z, r2, a, b, c;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        // 获取参数，修正坐标系
        scanf("%d %d %d %d %d %d %d %d %d %d %d", &x_, &y_, &z_, &r1, &x, &y, &z, &r2, &a, &b, &c);
        x -= x_;
        y -= y_;
        z -= z_;
        a -= x_;
        b -= y_;
        c -= z_;
        // 交平面系数
        double k;
        k = (l(r1) + l(x) + l(y) + l(z) - l(r2)) / (2*l(x) + 2*l(y) + 2*l(z));
        // 判断式
        if((l(a) + l(b) + l(c) > l(r1) && l(a) +l(b) + l(c) > l(r2)) || a*x + b*y + c*z == k*(l(x) + l(y) + l(z))){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
    return 0;
}
