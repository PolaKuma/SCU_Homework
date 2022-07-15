#include <iostream>
#include <string>
using namespace std;

class Teacher{
protected:
    string name;
    int age;
    string sex;
    string adress;
    string telephoneNumber;
    string title;
public:
    Teacher(string name, int age, string sex, string title, string adress, string telephoneNumber);
    void Display();
};

Teacher::Teacher(string name, int age, string sex, string title, string adress, string telephoneNumber):name(name),age(age),sex(sex),title(title),adress(adress),telephoneNumber(telephoneNumber){}

void Teacher::Display(){
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
    cout << "sex:"  << sex << endl;
    cout << "title:" << title << endl;
    cout << "adress:" << adress << endl;
    cout << "tel:" << telephoneNumber << endl;
}

class Cadre{
protected:
    string name;
    int age;
    string sex;
    string adress;
    string telephoneNumber;
    string post;
public:
    Cadre(string name, int age, string sex, string post, string adress, string telephoneNumber);
    void Display();
};

Cadre::Cadre(string name, int age, string sex, string post, string adress, string telephoneNumber):name(name),age(age),sex(sex),post(post),adress(adress),telephoneNumber(telephoneNumber){}

void Cadre::Display(){
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
    cout << "sex:"  << sex << endl;
    cout << "post:" << post << endl;
    cout << "adress:" << adress << endl;
    cout << "tel:" << telephoneNumber << endl;
}

class Teacher_Cadre:public Teacher, public Cadre{   //多重继承
private:
    double wages;
public:
    Teacher_Cadre(string name,int age,string sex,string title,string post,string adress,string telephoneNumber,double wages);
    void Show();
};

Teacher_Cadre::Teacher_Cadre(string name,int age,string sex,string title,string post,string adress,string telephoneNumber,double wages):Teacher(name,age,sex,title,adress,telephoneNumber),Cadre(name,age,sex,post,adress,telephoneNumber),wages(wages){}

void Teacher_Cadre::Show(){
    Teacher::Display();
    cout << "post:" << Cadre::post << endl;
    cout << "wages:" << wages << endl;
}

int main(){     //测试函数
    Teacher_Cadre test("Wang-li",50,"f","prof.","president","135 Beijing Road,Shanghai","(021)61234567",1534.5);
    test.Show();
    return 0;
}

