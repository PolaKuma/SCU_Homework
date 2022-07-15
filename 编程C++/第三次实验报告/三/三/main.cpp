#include <iostream>
using namespace std;

class Person{
private:
    char *name;
    int id;
public:
    Person(char *name,int id);      //构造函数
    ~Person(){      //析构函数
        if(name!=NULL){
            delete[] name;
            name=NULL;
        }
    };
    void Display();     //输出函数
};

class CollegeStu:public Person{     //共有继承Person的派生类CollegeStu
private:
    char *major;
    double score;
public:
    CollegeStu(char *name,int id,char *major,double score);     //构造函数
    ~CollegeStu(){      //析构函数
        if(major!=NULL){
            delete[] major;
            major=NULL;
        }
    };
    void Display();     //输出函数
};

Person::Person(char *name,int id){
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->id=id;
}

void Person::Display(){
    cout << "Name:" << name << endl;
    cout << "ID:" << id << endl;
}

CollegeStu::CollegeStu(char *name,int id,char *major,double score):Person(name,id){
    this->major=new char[strlen(major)+1];      //申请相应内存实现深拷贝
    strcpy(this->major,major);
    this->score=score;
}

void CollegeStu::Display(){
    Person::Display();
    cout << "Major:" << major << endl;
    cout << "C++ Score:" << score << endl;
}

int main(){     //测试主函数
    char name[40],major[100];
    int id;
    double score;
    cin >> name >> id >> major >> score;
    CollegeStu test(name,id,major,score);
    test.Display();
    return 0;
}


