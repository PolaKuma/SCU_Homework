#include <iostream>
#include <string.h>
using namespace std;

class Complex{
private:
    double real;    //实数部分
    double imag;    //虚数部分
public:
    Complex():real(0),imag(0){}     //构造函数
    Complex(double r, double i):real(r),imag(i){}   //含参构造函数
    Complex operator+(const Complex &obj);  //重载运算符"+"
    Complex operator-(const Complex &obj);  //重载运算符"-"
    Complex operator*(const Complex &obj);  //重载运算符"*"
    Complex operator/(const Complex &obj);  //重载运算符"/"
    friend ostream& operator << (ostream&, Complex&);   //重载运算符"<<"
    friend istream& operator >> (istream&, Complex&);   //重载运算符">>"
};

Complex Complex::operator+(const Complex &obj){     //重载运算符"+"
    Complex c;
    c.real=real+obj.real;
    c.imag=imag+obj.imag;
    return c;
}

Complex Complex::operator-(const Complex &obj){     //重载运算符"-"
    Complex c;
    c.real=real-obj.real;
    c.imag=imag-obj.imag;
    return c;
}

Complex Complex::operator*(const Complex &obj){     //重载运算符"*"
    Complex  c;
    c.real=real*obj.real-imag*obj.imag;
    c.imag=imag*obj.real+real*obj.imag;
    return c;
}

Complex Complex::operator/(const Complex &obj){     //重载运算符"/"
    Complex  c;
    c.real=(real*obj.real+imag*obj.imag)/obj.real*obj.real+obj.imag*obj.imag;     //此处有危险未排除：除法溢出
    c.imag=(imag*obj.real-real*obj.imag)/obj.real*obj.real+obj.imag*obj.imag;
    return c;
}

ostream& operator << (ostream& output, Complex &c){     //重载运算符"<<"
    output << c.real << "+" << c.imag << "i";
    return output;
}

istream& operator >> (istream &is, Complex &c){     //重载运算符">>"
    char s[50]={0},m_real[50]={0};      //s用于存放a+bi一行
    is >> s;
    for(int i=0;i<strlen(s);i++){if(s[i]=='i'||s[i]=='I')c.imag=1;} //判断是否含虚数i，题中i系数只能为1或0（无系数）
    for(int i=0;i<strlen(s)&&s[i]!='+';i++){m_real[i]=s[i];} //得到实数部分
    c.real=atoi(m_real);    //转化实数部分
    return is;
}

int main()
{   //测试函数
    Complex c1,c2,c3;
    cout<<"c1: "<<endl;;
    cin>>c1;
    cout<<"c2: "<<endl;
    cin>>c2;
    cout<<"c1="<<c1<<endl;
    cout<<"c2="<<c2<<endl;
    c3=c1+c2;
    cout<<"c1+c2="<<c3<<endl;
    c3=c1-c2;
    cout<<"c1-c2="<<c3<<endl;
    c3=c1*c2;
    cout<<"c1*c2="<<c3<<endl;
    c3=c1/c2;
    cout<<"c1/c2="<<c3<<endl;
 
    return 0;
}

