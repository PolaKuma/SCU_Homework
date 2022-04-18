//
//  main.c
//  D
//
//  Created by Junjie on 2021/11/10.
//

#include <stdio.h>

int main(){
    while (1){
        int a[4]={0};
        char ch;
        if ((ch=getchar())=='E'){
            gets(a);
            if (a[0]==1864393838 && a[1]==1768300646 && a[2]==25964)
                return 0;
            else
                printf("NO\n");
        }
        else{
            char b[100]={0};
            scanf("%2s",&b);
            int count=1,i=99,m=0;
            while (b[i]==0){
                m++;
                i--;
            }
            for (i=0;i<100-m;i++){
                count=count*10;
            }
            int count1=count;
            int j;
            for (j=0;j<i;j++){
                a[0]=a[0]+count*(b[j]-'0')/10;
                count=count/10;
            }
            a[0]=a[0]+((int)ch-'0')*count1;
            scanf(".%d.%d.%d",&a[1],&a[2],&a[3]);
            if ((a[0]>0 && a[0]<256) && (a[1]>0 && a[1]<256) && (a[2]>0 && a[2]<256) && (a[3]>0 && a[3]<256)){
                printf("YES\n");
            }
            else
                printf("NO\n");
            fflush(stdin);
        }
    }
}
