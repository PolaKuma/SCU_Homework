#include <iostream>
#include <cstring>
using namespace std;

class String{
private:
    char *p;
    int len;
public:
    String():p(NULL),len(0){};  //构造函数
    String(const char *s){      //参数为字符串构造函数
        len=int(strlen(s));
        p=new char[len+1];
        strcpy(p,s);
    }
    String(String &str){    //参数为对象复制构造函数
        len=str.len;
        p=new char[len+1];
        strcpy(p,str.p);
    };
    ~String(){}     //析构函数
    void display(){cout << p << endl;}      //输出函数
    friend String operator+(String &s1, String &s2);    //重载运算符+
    friend String operator-(String &s1, String &s2);    //重载运算符-
};

String operator+(String &s1, String &s2){
    String s;
    s.len=s1.len+s2.len;
    s.p=new char[s.len+1];
    strcpy(s.p, s1.p);
    strcat(s.p, s2.p);
    return s;
}

String operator-(String &s1, String &s2){
    for(int i=s1.len-1;i>=0 && s1.p[i]==' ';i--,s1.len--){s1.p[i]='\0';}
    String temp(s2);    //用于临时存储s2删除前导0的结果
    for(int i=0;i<s2.len && s2.p[i]==' ';i++,s2.len--); //得到s2去除0长度
    for(int i=s2.len-1,j=0;i>=0;i--,j++){temp.p[i]=s2.p[temp.len-j-1];}
    String s;   //用于存放结果
    s.len=s1.len+temp.len;
    s.p=new char[s.len+1];
    strcpy(s.p, s1.p);
    strcat(s.p, temp.p);
    return s;
}

int main( )
{
    String string1(" Hello  "), string2(" World ");
    string1.display();
    string2.display();
    String string3;
    string3 = string1 + string2;
    string3.display();
    string3 = string1 - string2;
    string3.display();
    return 0;
}


