//
//  main.c
//  猜数字
//
//  Created by Junjie on 2021/9/29.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
    int nplayerinput = -2;
    int ncount=0;
    int times=-1;
    int times1=0;
    double ncount1=0;
    double right=0;
    char cchoice=' ';
    int bstopgame=0;
    //定义相关数据
    
    printf("Choose your times: ");
    scanf("%d",&times);
    //用户输入次数
    
    while (bstopgame==0)
    {
    srand (time(0));
    int nmagicnumber=rand()%11;
    
    printf("猜数游戏：请输入一个0-10范围内的数字 ");
        while(nmagicnumber != nplayerinput && ncount<=times-1)
    {
    int x=scanf("%d",&nplayerinput);
        fflush(stdin);
    
    switch (x)
    {
        case 0:
    {
        printf("Error!\n");
        printf("Please enter again:\n");
        printf("You have %d times left\n",times-ncount);
        continue;
    }
         case 1:
        ncount=ncount+1;
        switch((nplayerinput >= nmagicnumber) << 1 | (nplayerinput == nmagicnumber))
    {
        case 2:printf("Too big\n");
               times1=times1+1;
               break;
        case 3:printf("Right\n");
               right=right+1;
               times1=times1+1;
               break;
        case 0:printf("Too small\n");
               times1=times1+1;
               break;
    }
    }
        
        printf("You have %d times left\n",times-ncount);
        
    }
    //主判断程序
    
    printf("Guesstime is: %d\n",ncount);
    
    printf("Again?\n");
    scanf("%c",&cchoice);
    fflush(stdin);
    if (cchoice=='N' || cchoice=='n')
    {
            bstopgame=1;
            printf("Bye!\n");
    }
    else
            nplayerinput = -2;
            ncount=0;
            ncount1=ncount1+1;
    //玩家再次游玩
}
    printf("You have played %d times\n",ncount);
    printf("Average Right is %lf\n",right/ncount1);
    printf("Average times is %lf\n",times1/times);
}
