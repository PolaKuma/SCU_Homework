//
//  main.c
//  D
//
//  Created by Junjie on 2021/11/11.
//

#include <stdio.h>

int Number(char a[],int *number,int *count);

int main(){
    while(1){
    char a[31]={0};
    int m=0;
    int *count=&m;
    gets(a);//输入字符串数列
    int number0=-1,number1=-1,number2=-1,number3=-1;//分别定义ip四个获取的数字
    if (a[0]=='E'&&a[1]=='n'&&a[2]=='d'&&a[3]==' '&&a[4]=='o'&&a[5]=='f'&&a[6]==' '&&a[7]=='f'&&a[8]=='i'&&a[9]=='l'&&a[10]=='e'&&a[11]=='\0')//结束条件
        return 0;
    else{//分别得到四个数字
        Number(a,&number0,count);
        Number(a,&number1,count);
        Number(a,&number2,count);
        Number(a,&number3,count);
        if (number0>=0&&number0<=255&&number1>=0&&number1<=255&&number2>=0&&number2<=255&&number3>=0&&number3<=255&&a[*count-1]=='\0'){//判断条件，由于ip为4个数字，所以要a[末尾]='\0'（即第五位后没字符了）
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    }
    
}

int Number(char a[],int *number,int *count){
    int p=1;//中间变量，想分别扫描单个字符转成整型后得到一个数字，如123先得到1，*p得到个位，再获取2，*p*10得到十位，以此类推
    while (a[*count]!='.'&&a[*count]!='\0'&&a[*count]>='0'&&a[*count]<='9'){
        *number=*number+(a[*count]-'0')*p;
        *count=*count+1;
        p=p*10;
    }
    *count=*count+1;//要扫描下一个数字应从count+1位开始
    
    int i,b,c=*number,d=0;
    for (i=1;c/i!=0;i=i*10){
        b=*number%10;
        *number=*number/10;
        d=d*10+b;
    }//把开始获取的数字倒过来，比如123变成321
    *number=d;//赋值给*number
    return 0;
}
