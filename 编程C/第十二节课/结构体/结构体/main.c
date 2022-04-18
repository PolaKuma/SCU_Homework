//
//  main.c
//  结构体
//
//  Created by Junjie on 2021/12/1.
//
#include <stdio.h>
#include <string.h>

struct Student{
    int num;
    char *name;
    float score;
}student[50];


void createFile(FILE *fp)
{
    fp=fopen("test.txt","w");
    fprintf(fp,"%s %s %s\n","编号","姓名","成绩");
    fclose(fp);
    printf("File created successfully!\n");
}

void SaveData(char *filename,struct Student *student,int n){
    FILE *fp=fopen("test.txt","w");
    for(int i=0;i<n;i++){
        fprintf(fp,"%d %s %f\n",student[i].num,student[i].name,student[i].score);
    }
    fclose(fp);
}

void ReadFile(){
    FILE *fp=fopen("test.txt","r");
    char test[100]={0};
    fseek(fp,0L,SEEK_END);
    long len=ftell(fp);
    fread(test,sizeof(student[0]),len/sizeof(student[0]),fp);
    printf("%s\n",test);
    fclose(fp);
}

void Del(struct Student *student,int *m){//n为需要删除的学生编号，m为学生人数
    int n;
    printf("请输入需要删除的学生编号：");
    scanf("%d",&n);
    for(int i=n;i<*m;i++){
        student[i-1]=student[i];
    }
    printf("删除成功！\n");
    m--;
}

void Add(struct Student *student,int *m){//n为需要添加的学生编号，m为学生人数
    printf("输入学生人数： ");
    scanf("%d",m);
    int i=*m,n;
    printf("请输入需要添加的学生编号：");
    scanf("%d",&n);
    for(;i>n;i--){
        student[i]=student[i-1];
    }
    student[n-1].num=n;
    printf("请输入学生名字：");
    scanf("%s",&student[n-1].name);
    printf("请输入学生成绩：");
    scanf("%f",&student[n-1].score);
    printf("添加成功！\n");
    m++;
}

void sort(struct Student *student,int *m){//对学生分数进行排序
    int n=*m;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(student[j].score>student[j+1].score){
                struct Student temp=student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
            }
        }
    }
    SaveData("test.txt",student,n);
}

void sort1(struct Student *student,int *m){//对学生姓名进行排序
    int n=*m;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(student[j].name,student[j+1].name)>0){
                struct Student temp=student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
            }
        }
    }
}

void display(){
    printf("********************\n* 欢迎进入学生成绩管理 *\n*       系统        *\n********************\n");
    printf("(N)新建 (A)增加 (D)删除 (S)按姓名排序 (C)按分数排序 (E)退出\n");
}
int main(){
    display();
    char ch = '\0';
    int count=0;
    while(ch!='E'){
        scanf("%c",&ch);
        switch(ch){
            case 'A':Add(student,&count); break;
            case 'D':Del(student,&count); break;
            case 'C':sort(student,&count); break;
            case 'S':sort1(student,&count); break;
            case 'E':break;
        }
        SaveData("test.txt",student,1);
        ReadFile();
        fflush(stdin);
    }
    printf("退出成功！\n");
}
