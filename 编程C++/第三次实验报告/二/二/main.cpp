#include <iostream>
#include <cstring>
using namespace std;

class Person{
private:
    char *name;
    char *sex;
    int age;
public:
    Person();   //无参数构造函数
    Person(char *name,int age,char *sex);   //有参数构造函数
    Person(const Person &obj);      //拷贝构造函数
    ~Person(){};    //析构函数
    void print();   //输出人员信息函数
};

Person::Person(){
    name=(char*)"张三";
    sex=(char*)"男";
    age=18;
}

Person::Person(char *name,int age,char *sex){
    this->name=name;
    this->sex=sex;
    this->age=age;
}

Person::Person(const Person &obj){      //申请内存采用深度拷贝形式
    name=new char[strlen(obj.name)+1];
    sex=new char[strlen(obj.sex)+1];
    strcpy(this->name,obj.name);
    strcpy(this->sex,obj.sex);
    this->age=obj.age;
}

void Person::print(){
    cout << "人员姓名：" << name << endl << "人员性别：" << sex << endl << "人员年龄：" << age << endl;
}
int main(){     //测试主函数
    Person P1;
    Person P2((char*)"李四",19,(char*)"男");
    Person P3(P2);
    P1.print();
    P2.print();
    P3.print();
    return 0;
}


