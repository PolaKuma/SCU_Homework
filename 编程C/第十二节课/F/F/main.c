//
//  main.c
//  F
//
//  Created by Junjie on 2021/12/9.
//

#include <stdio.h>
#include <string.h>

struct Privilege{//定义权限
    char privilege[33];
    int s;
}P[101];

struct Roles{//定义角色
    char roles[33];
    int count;
    struct Privilege pri[11];
}R[101];

struct User{//定义用户
    char users[33];
    int count;
    struct Roles role[11];
}U[101];

int main(){
    int p,r,u,q;
    scanf("%d",&p);
    for(int i=0;i<p;i++){//读入权限
        char temp[100]={0};
        scanf("%s",temp);
        sscanf(temp,"%[A-z]:%d",P[i].privilege,&P[i].s);
    }
    scanf("%d",&r);
    for(int i=0;i<r;i++){//读入角色
        scanf("%s %d",R[i].roles,&R[i].count);
        int a=0;
        for(int j=0;j<R[i].count;j++){
            char temp[100]={0};
            struct Privilege Temp;
            scanf("%s",temp);
            sscanf(temp,"%[A-z]:%d",Temp.privilege,&Temp.s);
            for(int k=0;k<101;k++){//将角色与权限对应
                if(strcmp(P[k].privilege,Temp.privilege)==0){
                    R[i].pri[a]=Temp;
                    a++;
                }
            }
        }
    }
    scanf("%d",&u);
    for(int i=0;i<u;i++){//读入用户
        scanf("%s %d",U[i].users,&U[i].count);
        for(int j=0;j<U[i].count;j++){
            char temp[100]={0};
            scanf("%s",temp);
            for(int k=0;k<101;k++){//将用户与角色对应
                if(strcmp(R[k].roles,temp)==0){
                    U[i].role[j]=R[k];
                }
            }
        }
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        char theuser[33]={0};//存放当前扫描用户
        scanf("%s",theuser);
        struct Privilege pri_temp;//存放当前扫描权限
        pri_temp.s=0;
        char temp[100]={0};
        scanf("%s",temp);
        sscanf(temp,"%[A-z]:%d",pri_temp.privilege,&pri_temp.s);
        struct User user_temp;//将当前扫描用户单独提出来（以当前用户与相应权限进行比对）
        for(int j=0;j<101;j++){
            if(strcmp(theuser,U[j].users)==0){
                user_temp=U[j];
            }
        }
        int flag=0,j=0,k=0;
        for(j=0;j<11;j++){//查看是否含有权限
            for(k=0;k<11;k++){
                if(strcmp(user_temp.role[j].pri[k].privilege,pri_temp.privilege)==0){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            for(int x=0;x<101;x++){
                if(strcmp(P[x].privilege,user_temp.role[j].pri[k].privilege)==0){
                    if(P[x].s==0){
                        printf("true\n");
                        break;
                    }
                    else if (P[x].s!=0 && user_temp.role[j].pri[k].s>=pri_temp.s && pri_temp.s!=0){
                        for(int m=0;m<11;m++){
                            for(int q=0;q<11;q++){//寻找最大值
                                if(strcmp(pri_temp.privilege,user_temp.role[m].pri[q].privilege)==0){
                                    if(user_temp.role[m].pri[q].s>user_temp.role[j].pri[k].s){
                                        user_temp.role[j].pri[k].s=user_temp.role[m].pri[q].s;
                                    }
                                }
                            }
                        }
                        printf("true\n");
                    }
                    else if (P[x].s!=0 && user_temp.role[j].pri[k].s>=pri_temp.s && pri_temp.s==0){
                        for(int m=0;m<11;m++){
                            for(int q=0;q<11;q++){//寻找最大值
                                if(strcmp(pri_temp.privilege,user_temp.role[m].pri[q].privilege)==0){
                                    if(user_temp.role[m].pri[q].s>user_temp.role[j].pri[k].s){
                                        user_temp.role[j].pri[k].s=user_temp.role[m].pri[q].s;
                                    }
                                }
                            }
                        }
                        printf("%d\n",user_temp.role[j].pri[k].s);
                    }
                }
            }
        }
        else
            printf("false\n");
    }
}
