//
//  main.c
//  C
//
//  Created by Junjie on 2022/1/2.
//
#include <stdio.h>
#include <string.h>

int main(){
    char a[101]={0};
    gets(a);
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='\\' && i!=strlen(a)-1){   //判断转义字符
            switch(a[i+1]){ //一般类型转义字符
                case 'a':printf("%02X ",7); i++; break;
                case 'b':printf("%02X ",8); i++; break;
                case 'f':printf("%02X ",12); i++; break;
                case 'n':printf("%02X ",10); i++; break;
                case 'r':printf("%02X ",13); i++; break;
                case 't':printf("%02X ",9); i++; break;
                case 'v':printf("%02X ",11); i++; break;
                case '\\':printf("%02X ",92); i++; break;
                case '?':printf("%02X ",63); i++; break;
                case '*':printf("%02X ",39); i++; break;
                case '"':printf("%02X ",34); i++; break;
                case '0':printf("%02X ",0); i++; break;
            }
            if(a[i+1]=='x'){    //十六进制转义字符
                for(int j=2;j<4;j++){
                    if(a[i+j]>'a' && a[i+j]<'z'){
                        printf("%c",a[i+j]-32);
                    }else{
                        printf("%c",a[i+j]);
                    }
                }
                printf(" ");
                i=i+3;
            }
            else if(a[i+3]>='0' && a[i+3]<='7'){    //八进制转义字符
                printf("%02X ",(a[i+1]-'0')*64+(a[i+2]-'0')*8+(a[i+3]-'0'));
                i=i+3;
            }
        }
        else    //非转义字符
            printf("%02X ",a[i]);
    }
}
