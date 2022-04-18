//
//  main.c
//  字符数组
//
//  Created by Junjie on 2021/11/10.
//

#include <stdio.h>
int Copy1(char a[],char b[]);//将b复制给a（数组版）
int Copy2(char *a,char *b);//将b复制给a（指针版）
char* Strcat(char *strDestination,char *strSource);//strcat函数，将strSource接到strDestination后面

/*int main(){
    char a[51]={0};
    int i=0;
    int count[4]={0};
    scanf("%s",a);
    printf("%s\n",a);
    while (a[i]!='\0'){
        if (a[i]>='0' && a[i]<='9')
            count[2]++;
        else if (a[i]>='a' && a[i]<='z')
            count[1]++;
        else if (a[i]>='A' && a[i]<='Z')
            count[0]++;
        else
            count[3]++;
        i++;
    }
        printf("%d,%d,%d,%d,%d,\n",count[0],count[1],count[2],count[3],count[0]+count[1]+count[2]+count[3]);
}
 */

int main(){
    char a[51]={0};
    char *b="China";
    gets(a);
    Strcat(a,b);
    puts(a);
}

int Copy1(char a[],char b[]){
    int i;
    for (i=0;b[i]!='\0';i++){
        a[i]=b[i];
    }
    b[i]='\0';
    return 0;
}
//将b复制给a（数组版）

int Copy2(char *a,char *b){
    int i;
    for (i=0;*(a+i)!='\0';i++){
        *(a+i)=*(b+i);
    }
    *(b+i)='\0';
    return 0;
}
//将b复制给a（指针版）

char* Strcat(char *strDestination,char *strSource){
    int length=0,i;
    for (i=0;*(strDestination+i)!='\0';i++)
        length++;
    for (i=0;*(strSource+i)!='\0';i++,length++){
        *(strDestination+length)=*(strSource+i);
    }
    return 0;
}
//strcat函数，将strSource接到strDestination后面
