//
//  main.c
//  结构体
//
//  Created by Junjie on 2021/12/1.
//
//定义方式
/*
struct name
{
 类型 变量名
 };

struct 结构变量类型
{
 变量名
 };
 
 struct
 {
 类型 变量名
 }成员名;
 
 struct name 变量名
 {
 分别赋值
 };
 */

#include <stdio.h>
#include <string.h>

struct DateType{
    int year;
    int month;
    int day;
};

struct Student{
    int num;
    char *name;
    char sex[5];
    struct DateType birthday;
    float score;
}boy,girl={12,"Jane","Girl",{2000,01,01},100};

struct average{
    float score;
    int persons;
};

/*int main(){
    boy.num=10;
    boy.name="Zhemin";
    strcpy(boy.sex,"Boy");
    boy.birthday.year=2002;
    boy.birthday.month=12;
    boy.birthday.day=01;
    boy.score=100;
    printf("boy's num=%d\nboy's name=%s\nboy's sex=%s\n%boy's birthday=%d.%d.%d\nboy's score=%f\n",boy.num,boy.name,boy.sex,boy.birthday.year,boy.birthday.month,boy.birthday.day,boy.score);
   
    printf("\ngirl's num=");
    scanf("%d",&girl.num);
    printf("girl's name=");
    scanf("%s",&girl.name);
    printf("girl's sex=");
    scanf("%s",&girl.sex);
    printf("girl's birthday=");
    scanf("%d.%d.%d",&girl.birthday.year,&girl.birthday.month,&girl.birthday.day);
    printf("girl's score=");
    scanf("%f",&girl.score);
    printf("girl's num=%d\ngirl's name=%s\ngirl's sex=%s\n%girl's birthday=%d.%d.%d\ngirl's score=%f\n",girl.num,girl.name,girl.sex,girl.birthday.year,girl.birthday.month,girl.birthday.day,girl.score);
}*/

/*int main(){
    struct Student *pStudent= NULL;
    struct Student student[4]={
        {10101,"John","Boy",{2001,1,1},98.1},
        {10102,"Jane","Girl",{2002,12,1},99.8},
        {10103,"Bob","Boy",{2003,3,31},96.5}
    };
 //结构数组
    for (pStudent=student;pStudent<student+3;pStudent++){
        printf("%d ",pStudent->num);
        printf("%s ",pStudent->name);
        printf("%s ",pStudent->sex);
        printf("%f ",pStudent->score);
        printf("\n");
    }
    //printf("%d",student[1].num);
}*/

/*int main(){
        struct Student student1; //定义结构体变量student1
        struct Student *point  = &student1;  //定义一个指向Student结构体类型的指针变量point
        (*point).name="Jane"; //(*point).name等价于student1.name
        (*point).birthday.year = 1989;
        (*point).birthday.month = 4;
        (*point).birthday.day = 29;
        printf("Name：%s\n", (*point ).name); //(*point).name不能写成point
        printf("Birthday：%d.%d.%d\n", (*point).birthday.year, (*point).birthday.month, (*point).birthday.day);
        
        //printf("Name：%s\n", point->name);
        //printf("Birthday：%d.%d.%d\n", point->birthday.year, point->birthday.month, point->birthday.day);
        //也可以用->写，指针指向
}*/

void Ave(struct Student *student,struct average students,int n){//求学生平均成绩和及格人数
    for(int i=0;i<n;i++){
        students.score=student[i].score/n;
        if(student[i].score>=60){
            students.persons++;
        }
    }
}

void Del(struct Student *student,int n,int m){//n为需要删除的学生编号，m为学生人数
    scanf("%d",&n);
    for(int i=n;i<m;i++){
        student[i]=student[i+1];
    }
}

void display(){
    printf("********************\n");
    printf("* 欢迎进入学生成绩管理 *\n");
    printf("*       系统        *\n");
    printf("********************\n");
    printf("(N)新建 ");
    printf("(A)增加 ");
    printf("(D)删除 ");
    printf("(SN)按姓名排序 ");
    printf("(SS)按分数排序 ");
    printf("(E)退出\n");
}
int main(){
    display();
    char ch
}
