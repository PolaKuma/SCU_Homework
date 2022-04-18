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
int Strcmp(char *a, char *b);//strcmp函数，比较字符串ascll码大小
int Bj(char *a,char *b,char*c);
char *substring(const char *const s,int start,int end);

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

/*int main(){
    char a[51]={0};
    char *b="China";
    gets(a);
    Strcat(a,b);
    puts(a);
}*/

/*int main(){
    int i;
    char a[100]={0},b[100]={0};
    scanf("%s",&a);
    scanf("%s",&b);
    i=Strcmp(a, b);
    printf("%d\n",i);
    return 0;
}*/

/*int main(){
    Bj("China","Korea","Japan");
}*/

/*int main(){
    char *s="Chengdu,Sichuan";
    printf("%s\n",substring(s, 0, 7));
    return 0;
}*/

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

int Strcmp(char *a, char *b){
    while(*a==*b&&*a!='\0'){
        a++;
        b++;
    }
    return *a-*b;
}
//strcmp函数，比较字符串ascll码大小

int Bj(char *a,char *b,char*c){
    char Bj[3][100]={{a},{b},{c}};
    int i;
    for (i=0;i<3;i++){
        if (Strcmp(Bj[i],Bj[i+1])>0){
            char temp[100]={0};
            Copy1(Bj[i],temp);
            Copy1(Bj[i],Bj[i+1]);
            Copy1(Bj[i+1],Bj[i]);
        }
    }
    puts(Bj);
    return 0;
}

char *substring(const char *const s,int start,int end){
    char *pNewString=new char[end-start+1+1];
    int j=0;
    for (int i=start;i<end;i++,j++){
        pNewString[j]=s[i];
    }
    pNewString[j]='\0';
    return pNewString;
}
