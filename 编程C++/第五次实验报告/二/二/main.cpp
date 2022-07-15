#include <iostream>
#include <cmath>
using namespace std;

class Circle;
class Point{
protected:
    double x;
    double y;
public:
    Point():x(0),y(0){};    //默认构造函数(0,0)
    Point(double x, double y):x(x),y(y){}   //含参数构造函数
    virtual ~Point(){};     //析构函数，为delete干净采用虚析构函数
    friend ostream& operator<<(ostream&output,const Point &p);    //重载运算符"<<"
    friend int locate(const Point p, const Circle c);   //判断与圆的位置
    friend void crossover_point1(Point &p, Circle &c, Point &p1, Point &p2);    //获得交点，为得到x,y采用友元函数
};

ostream& operator<<(ostream&output,const Point &p){     //重载运算符"<<"的实现
    output << "(" << p.x << "," << p.y<< ")";
    return output;
}

class Circle:public Point{
private:
    double r;
public:
    Circle(double x,double y,double r):Point(x,y),r(r){}    //含参数构造函数
    virtual ~Circle(){};    //析构函数，为delete干净采用虚析构函数
    friend ostream& operator<<(ostream&output,const Circle &c);     //重载运算符"<<"
    friend int locate(const Point p, const Circle c);       //判断与圆的位置
    friend void crossover_point1(Point &p, Circle &c, Point &p1, Point &p2);    //获得交点，为得到x,y采用友元函数
    bool operator > (const Circle &c);      //重载六种运算符
    bool operator < (const Circle &c);
    bool operator >= (const Circle &c);
    bool operator <= (const Circle &c);
    bool operator == (const Circle &c);
    bool operator != (const Circle &c);
};

ostream& operator<<(ostream&output,const Circle &c){        ////重载运算符"<<"的实现
    output << "(" << c.x << "," << c.y << "," << c.r << ")";
    return output;
}

int locate(Point p,Circle c){   //判断与圆位置函数的实现
    double d=sqrt((c.x-p.x)*(c.x-p.x)+(c.y-p.y)*(c.y-p.y));
    if(d>c.r){      //比较距离与半径大小
        return 1;
    }else if(d<c.r){
        return -1;
    }else
        return 0;
}

bool Circle::operator>(const Circle &c){    //六种重载运算符的实现
    return (this->r - c.r) > 1e-7;
}

bool Circle::operator<(const Circle &c){
    return (c.r - this->r) > 1e-7;
}

bool Circle::operator>=(const Circle &c){
    return !(*this < c);
}

bool Circle::operator<=(const Circle &c){
    return !(*this > c);
}

bool Circle::operator==(const Circle &c){
    return abs(this->r - c.r) < 1e-7;
}

bool Circle::operator!=(const Circle &c){
    return abs(this->r - c.r) > 1e-7;
}

void crossover_point1(Point &p, Circle &c, Point &p1,Point &p2 ){       //求交点函数的实现，直接套用数学公式
    p1.x = (c.x + sqrt(c.r*c.r/(1+((c.y-p.y)/(c.x-p.x))*((c.y-p.y)/(c.x-p.x)))));
    p2.x = (c.x - sqrt(c.r*c.r/(1+((c.y-p.y)/(c.x-p.x))*((c.y-p.y)/(c.x-p.x)))));
    p1.y = (p.y + (p1.x -p.x)*(c.y-p.y)/(c.x-p.x));
    p2.y = (p.y + (p2.x -p.x)*(c.y-p.y)/(c.x-p.x));
}

int main(){     //测试函数
    Circle c1(3,2,4),c2(4,5,5);      //c2应该大于c1
    Point p1(1,1),p2(3,-2),p3(7,3);  //分别位于c1内、上、外
 
    cout<<"圆c1: "<< c1;
    cout<<"点p1: " << p1;
    cout<<"点p1在圆c1之"<<((locate(p1, c1)>0)?"外":((locate(p1, c1)<0)?"内":"上"))<<endl;
    cout<<"点p2: "<<p2;
    cout<<"点p2在圆c1之"<<((locate(p2, c1)>0)?"外":((locate(p2, c1)<0)?"内":"上"))<<endl;
    cout<<"点p3: "<<p3;
    cout<<"点p3在圆c1之"<<((locate(p3, c1)>0)?"外":((locate(p3, c1)<0)?"内":"上"))<<endl;
    cout<<endl;
  
    cout<<"圆c1: "<<c1;
    if(c1>c2) cout<<"大于"<<endl;
    if(c1<c2) cout<<"小于"<<endl;
    if(c1>=c2) cout<<"大于等于"<<endl;
    if(c1<=c2) cout<<"小于等于"<<endl;
    if(c1==c2) cout<<"等于"<<endl;
    if(c1!=c2) cout<<"不等于"<<endl;
    cout<<"圆c2: "<<c2<<endl;
    cout<<endl;
  
    Point p4,p5;
    crossover_point1(p1,c1, p4, p5);
  
    cout<<"点p1: "<<p1;
    cout<<"与圆c1: "<<c1;
    cout<<"的圆心相连，与圆交于两点，分别是："<<endl;
    cout<<"交点: "<<p4;
    cout<<"交点: "<<p5;
    cout<<endl;
    return 0;
}

