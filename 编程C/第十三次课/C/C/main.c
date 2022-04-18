//
//  main.c
//  C
//
//  Created by Junjie on 2021/12/26.
//

#include <stdio.h>
#include <string.h>

typedef struct Words{
    char word[20];
    int count;
}words[500];

int main(){
    char setense[1001]={0};
    int count=0;
    while((gets(setense))!=NULL){
        int place=0;
        for(int i=0;i<1001;i++){
            if(setense[i]>='A' && setense[i]<='Z')
                setense[i]+=32;
            if(setense[i]<65||setense[i]>122)
                setense[i]=' ';
        }
        char temp_word[20]={0};
        scanf("%[a-z]",temp_word);
        for(place=0;)
    }
}
