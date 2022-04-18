//
//  main.c
//  A
//
//  Created by Junjie on 2021/11/17.
//

#include <stdio.h>

int main(){
    int m,n,x,place=-1;
    int a[401]={0};
    scanf("%d %d %d",&m,&n,&x);
    if (m>=1 && n>=1){
    for (int i=0;i<m*n;i++){
        scanf("%d",&a[i]);
    }
        for (int i=0;i<m*n;i++){
            for (int j=i+1;j<m*n;j++){
                if (a[i]==a[j]){
                    printf("Input Error\n");
                    return 0;
                }
            }
    }
        //判断重复
        for (int i=0;i<m*n;i++){
            if (x==a[i]){
                place=i+1;
            }
        }
        if (place==-1){
            printf("Input Error\n");
            return 0;
        }
        else{
            for (int i=0;i<m;i++){
                for (int j=0;j<n;j++){
                    printf("%d ",a[i*n+j]);
                }
                printf("\n");
            }
            if (place%n!=0)
                printf("%d %d\n",place/n+1,place%n);
            else
                printf("%d %d\n",place/n,n);
        }
}
    else
        printf("Input Error\n");
}

/*int main(){
    int m,n,x,q=0;
    scanf("%d %d %d",&n,&m,&x);
    if (m>=1 && n>=1){
        int a[21][21]={0},place=0,j=0;
        for (int i=0;i<m*n;i++){
            scanf("%d",&a[j][q]);
            if ((q+1)%m==0){
                j++;
                q=-1;
            }
            q++;
        }
        int b[10]={0};
        q=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                    b[q]=a[i][j];
                q++;
            }
        }
        for (int i=0;i<m*n;i++){
            for (int j=i+1;j<m*n;j++){
                if (b[i]==b[j]){
                    printf("Input Error\n");
                    return 0;
                }
            }
        }
        j=0,q=0;
        for (int i=0;i<m*n;i++,q++){
            if ((q+1)%4==0){
                j++;
                q=0;
            }
            if (a[j][q]==x){
                place=q+(j+1)*m;
            }
        }
        if (place==0)
            printf("Input Error\n");
        else{
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    printf("%d ",a[i][j]);
                }
                printf("\n");
            }
 if (place%m!=0)
     printf("%d %d\n",place/m+1,place%m);
 else
     printf("%d %d\n",place/m,m);
        }
    }
    else
        printf("Input Error\n");
}*/
