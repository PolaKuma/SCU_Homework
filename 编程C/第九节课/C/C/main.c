//
//  main.c
//  C
//
//  Created by Junjie on 2021/11/18.
//

#include <stdio.h>

int main(){
    int n,m;
    int students[1001]={0};
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        students[i]=i+1;
    }
    for (int i=0;i<m;i++){
        int p,q,j,place=-1;
        scanf("%d %d",&p,&q);
        for (j=0;j<n;j++){
            if (students[j]==p){
                place=j;
            }
        }
                if (q>=0){
                    for (int k=0;k<q && students[place]!=0;k++,place++){
                        int temp=students[place];
                        students[place]=students[place+1];
                        students[place+1]=temp;
                    }
                }
                else if (q<0){
                    for (int k=q;k<0 && place!=0;k++,place--){
                        int temp=students[place];
                        students[place]=students[place-1];
                        students[place-1]=temp;
                    }
                }
    }
    for (int i=0;i<n;i++){
        printf("%d ",students[i]);
    }
}
