#include <iostream>
using namespace std;

class CSolid{   //声明抽象类
public:
    virtual double GetArea()=0;     //纯虚函数需要初始化0告诉系统这是纯虚函数
    virtual double GetVolumn()=0;
};

class CCube:public CSolid{      //声明正方体类
private:
    double d;   //正方体的边长
public:
    CCube():d(0){}      //构造函数
    CCube(double d):d(d){}
    ~CCube(){}      //析构函数
    double GetArea(){       //获取表面积
        return 6*d*d;
    }
    double GetVolumn(){     //获取体积
        return d*d*d;
    }
};

class CBall:public CSolid{      //声明球类
private:
    double r;   //球的半径
public:
    CBall():r(0){}      //构造函数
    CBall(double r):r(r){}
    ~CBall(){}      //析构函数
    double GetArea(){       //获取表面积
        return 4*3.1415926*r*r;
    }
    double GetVolumn(){     //获取体积
        return 4*(3.1415926*r*r*r)/3;
    }
};

class CCylinder:public CSolid{      //声明圆柱体类
private:
    double r;   //底部半径
    double h;   //高
public:
    CCylinder():r(0),h(0){}     //构造函数
    CCylinder(double r,double h):r(r),h(h){}
    ~CCylinder(){}      //析构函数
    double GetArea(){       //获取表面积
        return 2*3.1415926*r*r+2*3.1415926*r*h;
    }
    double GetVolumn(){     //获取体积
        return 3.1415926*r*r*h;
    }
};

int main(){     //测试函数
    CCube oCube(2);     //定义边长为2的正方体
    CBall oBall(2);     //定义半径为2的球
    CCylinder oCylinder(2,3);       //定义底部半径为2，高为3的圆柱体
    CSolid *p;      //定义基类指针
    p=&oCube;       //使指针指向正方体类对象
    cout << "正方体的表面积为：" << p->GetArea() << endl << "正方体的体积为：" << p->GetVolumn() << endl;
    p=&oBall;       //使指针指向球类对象
    cout << "球的表面积为：" << p->GetArea() << endl << "球的体积为：" << p->GetVolumn() << endl;
    p=&oCylinder;       //使指针指向圆柱体类对象
    cout << "圆柱体的表面积为：" << p->GetArea() << endl << "圆柱体的体积为：" << p->GetVolumn() << endl;
    
    return 0;
}

