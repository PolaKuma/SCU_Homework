//
//  main.c
//  C3
//
//  Created by Junjie on 2021/11/16.
//

#include <stdlib.h>
#include <stdio.h>

int solve_exp(int q, char *output){
    int numSum = 0, xSum = 0, tempnum = 0, flag=1;
    int isRight = 1, state = 0;
    char ch, unknown='y';
    ch = getchar();
    while(ch!='\n'){
        switch(state){
            case 0:{
                if(ch>='0' && ch<='9'){
                    tempnum = (tempnum*10 + (int)(ch) - 48);
                    state = 1;
                }else if((ch>='a' && ch<='z') || (ch >='A' && ch <= 'Z')){
                    xSum += flag*isRight;
                    unknown = ch;
                    flag=1;
                    state = 0;
                }else if(ch=='-'){
                    flag=-1;
                    state = 0;
                }else if(ch=='+'){
                    flag=1;
                    state=0;
                }
                else if(ch=='='){
                    isRight=-1;
                    state=0;
                }else{
                    printf("error ch:%c", ch);
                    return 0;
                }
            } break;
            case 1:{
                if(ch>='0' && ch<='9'){
                    tempnum = (tempnum*10 + (int)(ch)-48);
                    state = 1;
                } else if((ch>='a' && ch<='z') || (ch >='A' && ch <= 'Z')){
                    xSum += flag*isRight*tempnum;
                    flag=1;
                    tempnum=0;
                    unknown=ch;
                    state=0;
                } else if(ch == '='){
                    numSum += (flag*isRight*tempnum);
                    tempnum=0;
                    isRight=-1;
                    flag=1;
                    state=0;
                } else if(ch == '+'){
                    numSum += (flag*isRight*tempnum);
                    flag=1;
                    tempnum=0;
                    state=0;
                } else if(ch=='-'){
                    numSum += (flag*isRight*tempnum);
                    flag=-1;
                    tempnum=0;
                    state=0;
                }
            }break;}
        ch = getchar();
    }
    numSum += (flag*isRight*tempnum);
    if(xSum == 0){
        xSum = 1;
        //printf("changed");
    }
    sprintf(output, "%c=%f\n",unknown, -1*(float)(numSum)/(float)(xSum));//将格式化输出的数据写入字符串中
    return 0;
}


int main()
{
    int n=1, q=0;
    scanf("%d\n", &n);
    char output[n][1000];
    for (q=0;q<n;q++){
        solve_exp(q, output[q]);
    }
    for(q=0;q<n;q++){
        printf("%s", output[q]);
    }
}
