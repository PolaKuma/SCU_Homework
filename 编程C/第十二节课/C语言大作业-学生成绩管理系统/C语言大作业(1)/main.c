//
//  main.c
//  C语言大作业
//
//  Created by Junjie on 2021/12/31.
//

#include <stdio.h>
#include <string.h>

struct Student{     //定义学生结构体
    char name[20];
    char sex[5];
    float score;
}*pstu;

void Printmenu(){   //菜单打印
    printf("********************\n* 欢迎进入学生成绩管理 *\n*       系统        *\n********************\n");
    printf("(N)新建 (A)增加 (D)删除 (S)按姓名排序 (C)按分数排序（X）保存数据（Y）读取数据 (E)退出\n");
}

void SaveData(char *Filename,struct Student *pstu,int n){   //保存数据（退出前必须）
    FILE *fp=fopen(Filename,"w");
    if(fp==NULL){
        printf("打开文件失败\n");
        return;
    }else{
        for(int i=0;i<n;i++)
            fprintf(fp,"%d\t%s\t%s\t%f",i+1,(pstu+i)->name,(pstu+i)->sex,(pstu+i)->score);
        fclose(fp);
    }
}

void ReadData(char *Filename,struct Student *pstu,int n){   //读取数据
    FILE *fp=fopen(Filename,"r");
    if(fp==NULL){
        printf("读取失败\n");
        return;
    }else{
        fread(pstu,sizeof(struct Student),n,fp);
        fclose(fp);
        printf("读取%s成功\n",Filename);
    }
}

void Newfile(char *filename,struct Student *pstu,int n){    //新建文本
    FILE *fp=fopen(filename,"w");
    if(fp==NULL){
        printf("创建失败\n");
        return;
    }else{
        for(int i=0;i<n;i++)
            fprintf(fp,"%d %s %s %f ",i+1,pstu->name,pstu->sex,pstu->score);
        fclose(fp);
    }
}

void Display(struct Student *pstu,int n){   //显示已有学生
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%d\t%s\t%s\t%.2f\n",i+1,pstu[i].name,pstu[i].sex,pstu[i].score);
    printf("\n");
}

void Add(struct Student *pstu,int n){   //添加学生
    printf("请输入名字：");
    scanf("%s",(pstu+n)->name);
    printf("请输入性别：");
    scanf("%s",(pstu+n)->sex);
    printf("请输入成绩：");
    scanf("%f",&(pstu+n)->score);
}

void Delete(struct Student *pstu,int n){    //删除学生
    int i;
    printf("请输入删除学生的编号：");
    scanf("%d",&i);
    for(;i<n;i++){
        strcpy((pstu+i-1)->name,(pstu+i)->name);
        strcpy((pstu+i-1)->sex,(pstu+i)->sex);
        (pstu+i-1)->score=(pstu+i)->score;
    }
}

void Scoresort(struct Student *pstu,int n){     //按成绩排序
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1;j++) {
            if ((pstu+j)->score<(pstu+j+1)->score){
                struct Student temp;
                temp=*(pstu+j);
                *(pstu+j)=*(pstu+j+1);
                *(pstu+j+1)=temp;
            }
        }
    }
}

void Namesort(struct Student *pstu,int n){      //按姓名排序
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1;j++) {
            if (strcmp((pstu+j)->name,(pstu+j+1)->name)>0){
                struct Student temp;
                temp=*(pstu+j);
                *(pstu+j)=*(pstu+j+1);
                *(pstu+j+1)=temp;
            }
        }
    }
}

float Average(struct Student *pstu,int n){      //计算平均分
    float average=0;
    for(int i=0;i<n;i++)
        average+=pstu[i].score/n;
    return average;
}



int main(){
    Printmenu();
    char command='\0';
    char filename[100]="NewFile.txt";
    int n=0;
    struct Student stu[100];
    pstu = stu;
    while(command!='E'){
        scanf("%c",&command);
        switch(command){
            case 'N':
                printf("请输入文件名： ");
                scanf("%s",filename);
                strcat(filename,".txt");
                Newfile(filename,pstu,n);
                printf("新建文件%s成功！\n",filename);
                break;
            
            case 'A':
                Add(pstu,n);
                n++;
                printf("添加学生成功！\n");
                Display(pstu,n);
                break;
                
            case 'D':
                Delete(pstu,n);
                n--;
                printf("删除学生成功！\n");
                Display(pstu,n);
                break;
                
            case 'X':
                SaveData(filename,pstu,n);
                printf("已保存至文件：%s\n",filename);
                break;
                
            case 'Y':
                printf("请输入文件名：");
                scanf("%s",filename);
                ReadData(filename,pstu,n);
                Display(pstu,n);
                break;
                
            case 'C':
                Scoresort(pstu,n);
                Display(pstu,n);
                break;
                
            case 'S':
                Namesort(pstu,n);
                Display(pstu,n);
                break;
        }
    }
}
