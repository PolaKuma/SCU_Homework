#include <iostream>
using namespace std;

class Box{
private:
    double m_a;
public:
    Box();      //构造函数
    ~Box(){};       //析构函数
    void SetA(double a);    //设置立方体边长
    double GetVolume();     //计算体积
    double GetArea();   //计算表面积
    void Display();     //输出计算的结果
};

Box::Box(){
    m_a=0;
}

void Box::SetA(double a){
    m_a=a;
}

double Box::GetVolume(){
    return m_a*m_a*m_a;
}

double Box::GetArea(){
    return 6*m_a*m_a;
}

void Box::Display(){
    cout << "立方体的边长为：" << m_a << endl << "立方体的体积为：" << GetVolume() << endl << "立方体的表面积为：" << GetArea() << endl;
}

int main(){     //测试函数
    Box test1;
    Box test2;
    test1.SetA(2);
    test2.SetA(2.5);
    test1.Display();
    test2.Display();
    return 0;
}




