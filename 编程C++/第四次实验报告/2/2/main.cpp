#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class CStrSub
{
    char* str;
public:
    CStrSub(const char* s);
    CStrSub(const CStrSub&);
    ~CStrSub();
    void set(char* s);
    void show()
    {
        cout << str << endl;
    }
};

CStrSub::CStrSub(const char* s)
{
    str = new char[strlen(s) + 1];
    if (!str)
    {
        cout << "申请空间失败！" << endl;
        exit(-1);
    }
    strcpy(str, s);
}

CStrSub::CStrSub(const CStrSub& temp)
{
    str = new char[strlen(temp.str) + 1];
    if (!str)
    {
        cout << "申请空间失败！" << endl;
        exit(-1);
    }
    strcpy(str, temp.str);
}

CStrSub:: ~CStrSub()
{
    if (str != NULL) delete[]str;
}

void CStrSub::set(char* s)
{
    delete[]str;
    str = new char[strlen(s) + 1];
    if (!str)
    {
        cout << "申请空间失败！" << endl;
        exit(-1);
    }
    strcpy(str, s);
}

CStrSub input(CStrSub *temp)
{
    char s[20];
    cout << "输入字符串：" << endl;
    cin >> s;
    temp->set(s);
    return *temp;
}

int main()
{
    CStrSub a("hello");
    a.show();
    CStrSub b = input(&a);
    a.show();
    b.show();

    return 0;
}

