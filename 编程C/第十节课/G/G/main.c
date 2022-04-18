//
//  main.c
//  G
//
//  Created by Junjie on 2021/11/25.
//

#include <stdio.h>
#include <string.h>

#define BUF_SS 101

void Highlight(char *buf){
    unsigned long length=strlen(buf);
    for (int q=0;q<length;){
    char temp1[101]={0},temp2[101]={0},temp3[101]={0};
    int i=0,j=0,k=0,p=0;
    for (i=q;i<strlen(buf) && buf[i]!='_';i++,q++){
        temp1[i]=buf[i];
    }
    for (j=i+1,q+=1;j<strlen(buf) && buf[j]!='_';j++,q++){
        temp2[k]=buf[j];
        k++;
    }
    for (i=j+1,q+=1;i<strlen(buf);i++,q++){
        temp3[p]=buf[i];
        p++;
    }
    strcpy(buf,temp1);
    strcat(buf,"<em>");
    strcat(buf,temp2);
    strcat(buf,"</em>");
    strcat(buf,temp3);
}
}
//强调转换

void Superlink(char *buf){
    unsigned long length=strlen(buf);
    for (int q=0;q<length;){
        char temp1[101]={0},temp2[101]={0},temp3[101]={0},temp4[101]={0},temp5[101]={0};
        int i=0,j=0,k=0,p=0;
        for (i=q;i<strlen(buf) && buf[i]!='[';i++,q++){
            temp1[i]=buf[i];
        }
        for (j=i,q+=1;j<strlen(buf) && buf[j]!=')';j++,q++){
            temp2[k]=buf[j];
            k++;
        }
        temp2[k]=buf[j];
        sscanf(temp2,"[%[^]]](%[^)])",temp3,temp4);
        for (i=j+1,q+=1;i<strlen(buf);i++,q++){
            temp5[p]=buf[i];
            p++;
        }
        strcpy(buf,temp1);
        strcat(buf,"<a href=\"");
        strcat(buf,temp4);
        strcat(buf,"\">");
        strcat(buf,temp3);
        strcat(buf,"</a>");
        strcat(buf,temp5);
    }
}
//超级链接转换

int main(void){
    char buf[101],convertbuf[101][300]={0};
    int count=0;
    while (gets(buf)){
        
        if (buf[0]=='#'){
            int i=0,k=0;
            char temp_buf[101]={0};
            for (i=0;buf[i]=='#';i++);
            char temp1[5]={'<','h',i+48,'>','\0'},temp2[6]={'<','/','h',i+48,'>','\0'};
            for (;buf[i]=='#' || buf[i]==' ';i++);
            for (int j=i;j<strlen(buf)&&buf[j]!='\n';j++){
                temp_buf[k]=buf[j];
                k++;
            }
            for (int i=0;i<101;i++){
                if (temp_buf[i]=='['){
                    Superlink(temp_buf);
                }
                if (temp_buf[i]=='_'){
                    Highlight(temp_buf);
                }
            } //判断这一字符串中的超级链接和强调（之后类似语句同理）
            strcpy(convertbuf[count],temp1);
            strcat(convertbuf[count],temp_buf);
            strcat(convertbuf[count],temp2);
        }
        //标题转换
        
        else if (buf[0]=='*'){
            int place=0;
            for (place=0;buf[place]==' '||buf[place]=='*';place++);
            for (int i=place,j=0;i<strlen(buf);i++,j++){
                convertbuf[count][j]=buf[i];
            }
        }
        //预留无序列表（先保存*之后的字符串），之后继续转换
        
        else if (buf[0]!='#' && buf[0]!='*' && buf[0]!='\0'){
            strcpy(convertbuf[count],"<p>");
            strcat(convertbuf[count],buf);
            strcat(convertbuf[count],"</p>");
        }
        //文本转换（先全部化为<p></p>形式，方便连续文本转换）
        
        memset(buf,0,sizeof buf);
        count++;
    }
    
    for (int i=0;i<101;i++){
        if (convertbuf[i][0]!='<' && convertbuf[i][0]!='\0'){
            for (int m=0;m<strlen(convertbuf[i]);m++){
                if (convertbuf[i][m]=='_'){
                    Highlight(convertbuf[i]);
                }
                if (convertbuf[i][m]=='['){
                    Superlink(convertbuf[i]);
                }
            }
            char temp_convert[500]={0};
            strcat(temp_convert,"<ul>\n<li>");
            strcat(temp_convert,convertbuf[i]);
            strcat(temp_convert,"</li>");
            strcpy(convertbuf[i],temp_convert);
            //先转换第一行，因为要在前面加一行<ul>\n
            int j;
            for (j=i+1;convertbuf[j][0]!='<' && convertbuf[j][0]!='\0';j++){
                char temp[101]={0};
                for (int k=0;k<strlen(convertbuf[j]);k++){
                    if (convertbuf[j][k]=='_'){
                        Highlight(convertbuf[j]);
                    }
                    if (convertbuf[j][k]=='['){
                        Superlink(convertbuf[j]);
                    }
                }
                strcpy(temp,"<li>");
                strcat(temp,convertbuf[j]);
                strcat(temp,"</li>");
                strcpy(convertbuf[j],temp);
            }
            //转换剩下的
            strcpy(convertbuf[j],"</ul>");
            //行尾加上</ul>
        }
    }
    //无序列表的转换
    
    for (int i=0;i<101;i++){
        if (convertbuf[i][1]=='p'){
            char temp[101]={0};
            sscanf(convertbuf[i],"<p>%[^<]",temp);
            strcpy(convertbuf[i],"<p>");
            strcat(convertbuf[i],temp);
            //先转换第一行，因为要提取除<p></p>以外的字符串，所以强调和超级链接之后转换
            for (int k=0;k<strlen(convertbuf[i]);k++){
                if (convertbuf[i][k]=='_'){
                    Highlight(convertbuf[i]);
                }
                if (convertbuf[i][k]=='['){
                    Superlink(convertbuf[i]);
                }
            }
            for (i+=1;convertbuf[i][0]!='\0'&& convertbuf[i][1]!='u';i++){
                char temp1[101]={0};
                sscanf(convertbuf[i],"<p>%[^<]",temp1);
                strcpy(convertbuf[i],temp1);
                for (int k=0;k<strlen(convertbuf[i]);k++){
                    if (convertbuf[i][k]=='_'){
                        Highlight(convertbuf[i]);
                    }
                    if (convertbuf[i][k]=='['){
                        Superlink(convertbuf[i]);
                    }
                }
            }
            strcat(convertbuf[i-1],"</p>");
        }
    }
    //连续文本的转换
    
    for (int i=0;i<101;i++){
        if (convertbuf[i][0]!='\0')
        printf("%s\n",convertbuf[i]);
    }
    //输出
}
