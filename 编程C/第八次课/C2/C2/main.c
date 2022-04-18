//
//  main.c
//  C2
//
//  Created by Junjie on 2021/11/16.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int numSum = 0, xSum = 0;
int isRight = 0;
 
void eval(char numBuff[], int isX)
{
 int num = atoi(numBuff);
 
 if (isX)
 {
  if (num == 0)
       num = 1;
 
  if (isRight > 0)
   xSum -= num;
  else
   xSum += num;
 }
 else
 {
  if (isRight > 0)
   numSum += num;
  else
   numSum -= num;
 }
 memset(numBuff, 0, 80);        //清空数组
}
 
 
 
int main()
{
    int n,q;
    scanf("%d",&n);
    for (q=0;q<n;q++){
    char exp[80] = {0};
        scanf("%s",&exp);
 
 char xVarName;
 
 char numBuff[80] = { 0 };
 
 for (unsigned int i = 0; i < strlen(exp); i++)
 {
  if ((exp[i] >= '0' && exp[i] <= '9') || (exp[i] == '+') || (exp[i] == '-'))
  {
   if ((exp[i] == '+') || (exp[i] == '-'))
        eval(numBuff, 0);                //缓存中的数输出
   strncat(numBuff, &exp[i], 1);
  }
  else if (exp[i] == '=')
  {
   eval(numBuff, 0);
   isRight = 1;
  }
  else
  {
   xVarName = exp[i];
   eval(numBuff, 1);
  }
 }
 eval(numBuff, 0);
 
printf("%c=%.6f\r\n", xVarName, (float)numSum / (float)xSum);
        isRight=0,xSum=0,numSum=0;
}
}
