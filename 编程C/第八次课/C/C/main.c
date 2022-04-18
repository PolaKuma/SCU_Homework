//
//  main.c
//  C
//
//  Created by Junjie on 2021/11/10.
//

#include <stdio.h>

int main(){
    char a[100]={0};
    int left_count1=0;
    int right_count1=0;
    int temp_left_count1=0;
    int temp_right_count1=0;
    int count1=0;
    int count2=0;
    int left_count2=0;
    int right_count2=0;
    int i;
    char m;
    gets(a);
    for (i=0;a[i]!='=';i++){
        sscanf(a,"%*[^'1'-'9']%d",&temp_left_count1);
        left_count1=left_count1+temp_left_count1;
        int j,flag=0;
        for (j=0;a[j]!='=';j++){
            if (a[j]==temp_left_count1+'0'){
                a[j]='!';
            }
        }
        for (j=0;a[j]!='=';j++){
            if (a[j]>='0' && a[j]<='9'){
                flag=1;
            }
        }
        temp_left_count1=0;
        if (flag==0){
            break;
        }
    }
    i++;
    while (a[i]!='\0'){
        sscanf(a,"%d",&temp_right_count1);
        right_count1=right_count1+temp_right_count1;
        i++;
        int j;
        for (j=0;a[j]!='=';j++){
            if (a[j]==temp_right_count1+'0'){
                a[j]='!';
            }
        }
        temp_right_count1=0;
    }
    count1=left_count1-right_count1;
    for (i=0;a[i]!='=';i++){
        if ((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
            left_count2++;
            m=a[i];
        }
    }
    while (a[i]!='\0'){
        if (a[i]>='a'&&a[i]<='z'){
            right_count2++;
    }
        i++;
}
    count2=left_count2-right_count2;
    count1=count1/count2;
    printf("%c=%d",m,count1);
}
