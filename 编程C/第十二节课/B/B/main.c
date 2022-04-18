//
//  main.c
//  B
//
//  Created by Junjie on 2021/12/8.
//

#include <stdio.h>
#include <string.h>

int main(){
    char Cmessage[201][201]={0};
    int count=0;
    while(1){
        char message[3][201]={0},temp[201]={0};
        for(int i=0;i<3;i++){
            gets(message[i]);
            if(strcmp(message[0],"ENDOFINPUT")==0){
                break;
            }
        }
        if(strcmp(message[0],"ENDOFINPUT")==0){
            break;
        }
        for(int i=0;i<strlen(message[1]);i++){
            if(message[1][i]>='A' && message[1][i]<='Z'){
            if(message[1][i]-5-'A'>=0)
                message[1][i]=(message[1][i]-5-'A')%26+'A';
            else if(message[1][i]-5-'A'<0)
                message[1][i]=message[1][i]-5-'A'+'A'+26;
            }
        }
        strcpy(Cmessage[count],message[1]);
        count++;
    }
    for(int i=0;i<count;i++){
        puts(Cmessage[i]);
    }
}
