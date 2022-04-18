//
//  main.c
//  C1
//
//  Created by Junjie on 2021/11/14.
//

#include <stdio.h>
int left_count1(char a[],char x);
int right_count1(char a[],char x);

int main(){
    int n,q;
    scanf("%d",&n);
    for (q=0;q<n;q++){
        fflush(stdin);
        char a[50]={0};
        gets(a);
        double count1=0;
        double count2=0;
        int i,p;
        char m='!';
        int temp_count1=0;
        int temp_count2=0;
        int temp_count1_1=0;
        int temp_count2_1=0;
        for (i=0;a[i]!='=';i++){
            if (a[i]>='a'&&a[i]<='z'){
                int x=i,s=i;
                m=a[i];
                for (p=1;a[x-1]>='0'&&a[x-1]<='9';p=p*10,x--){
                    temp_count1=temp_count1+(a[x-1]-'0')*p;
                }
                if (s==0)
                    temp_count1++;
                else{
                if (a[s-1]=='+'||a[s-1]=='='){
                    temp_count1++;
                }
                else if (a[s-1]=='-'){
                    temp_count1=-temp_count1;
                }
                }
            }
            temp_count1_1=temp_count1_1+temp_count1;
            temp_count1=0;
        }
        count1=right_count1(a,m)-left_count1(a,m);
        for (i=i+1;a[i]!='\0';i++){
            if(a[i]>='a'&&a[i]<='z'){
                int j,x=i,s=i;
                m=a[i];
                for (p=1;a[x-1]>='0'&&a[x-1]<='9';p=p*10,x--){
                    temp_count2=temp_count2+(a[x-1]-'0')*p;
                }
                if (a[s-1]=='+'||a[s-1]=='='){
                    temp_count2++;
                }
                else if (a[s-1]=='-'){
                    temp_count2--;
                }
                j=x-1;
                if (a[j]=='-'){
                    temp_count2=-temp_count2;
                }
            }
            temp_count2_1=temp_count2_1+temp_count2;
            temp_count2=0;
        }
        count2=temp_count1_1-temp_count2_1;
        double count=(double)count1/(double)count2;
        printf("%c=%lf\n",m,count);
    }
}

int left_count1(char a[],char x){
    int i,p,j=-1;
    int left_count=0;
    for (i=0;a[i]!='=';i++){
        int temp_left_count=0;
        if ((a[i]>='0'&&a[i]<='9')&&a[i+1]!=x){
            j=i;
            temp_left_count=a[i]-'0';
            for (p=10;a[i+1]>='0' && a[i+1]<='9';i++,p=p*10){
                temp_left_count=temp_left_count*p+(a[i+1]-'0');
            }
            if (j>0){
            if (a[j-1]=='-'){
                left_count=left_count-temp_left_count;
            }
            else
                left_count=left_count+temp_left_count;
        }
            else if (j==0){
                left_count=left_count+temp_left_count;
            }
        }
    }
    return left_count;
}

int right_count1(char a[],char x){
    int i=0,m,p,j=-1;
    int temp_right_count=0,right_count=0;
    while (a[i]!='='){
        i++;
    }
    for (m=i+1;a[m]!='\0';m++){
        if ((a[m]>='0'&&a[m]<='9')&&a[m+1]!=x){
            j=m;
            temp_right_count=a[m]-'0';
            for (p=10;a[m+1]>='0' && a[m+1]<='9';p=p*10,m++){
                temp_right_count=temp_right_count*p+(a[m+1]-'0');
            }
            if (a[j-1]=='-'){
                right_count=right_count-temp_right_count;
            }
            else
                right_count=right_count+temp_right_count;
        }
    }
    return right_count;
}
