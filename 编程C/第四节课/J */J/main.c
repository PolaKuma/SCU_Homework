//
//  main.c
//  J
//
//  Created by Junjie on 2021/10/16.
//

#include <stdio.h>

int main() {
    char ch;
    int count[128] = {0};
    do{
        ch=getchar();
        count[ch] += 1;
    }
    while(ch!='\n');
    do{
        ch=getchar();
        count[ch] = 0;
    }while(ch!='\n');
    
    int flag = 0;
    for(int i = 32; i < 128; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            printf("%c", i);
            flag = 1;
        }
    }
    if(!flag){
        printf("null");
    }
    return 0;
}
