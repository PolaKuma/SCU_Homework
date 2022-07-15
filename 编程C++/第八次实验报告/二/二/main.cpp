#include <iostream>
#include <string.h>
using namespace std;

template<class T>   //声明模版
class Complex{
private:
    T real;    //实数部分
    T imag;    //虚数部分
public:
    Complex():real(0),imag(0){}     //构造函数
    Complex(T r, T i):real(r),imag(i){}   //含参构造函数
    Complex operator+(const Complex &obj);  //重载运算符"+"
    Complex operator-(const Complex &obj);  //重载运算符"-"
    Complex operator*(const Complex &obj);  //重载运算符"*"
    Complex operator/(const Complex &obj);  //重载运算符"/"
    friend ostream& operator << (ostream&output, Complex<T>&c){     //重载运算符"<<"
        output << c.real << "+" << c.imag << "i";
        return output;
    }
};

template<class T>
Complex<T> Complex<T>::operator+(const Complex &obj){     //重载运算符"+"
    Complex c;
    c.real=real+obj.real;
    c.imag=imag+obj.imag;
    return c;
}

template<class T>
Complex<T> Complex<T>::operator-(const Complex &obj){     //重载运算符"-"
    Complex c;
    c.real=real-obj.real;
    c.imag=imag-obj.imag;
    return c;
}

template<class T>
Complex<T> Complex<T>::operator*(const Complex &obj){     //重载运算符"*"
    Complex  c;
    c.real=real*obj.real-imag*obj.imag;
    c.imag=imag*obj.real+real*obj.imag;
    return c;
}

template<class T>
Complex<T> Complex<T>::operator/(const Complex &obj){     //重载运算符"/"
    Complex  c;
    c.real=(real*obj.real+imag*obj.imag)/obj.real*obj.real+obj.imag*obj.imag;     //此处有危险未排除：除法溢出
    c.imag=(imag*obj.real-real*obj.imag)/obj.real*obj.real+obj.imag*obj.imag;
    return c;
}

int main()
{   //测试函数
    Complex<double> c1(1.5,2);  //测试double类型模版
    Complex<double> c2(3.4,1);
    Complex<double> c3;
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
    
    cout << endl;
    Complex<int> c4(2,2);   //测试int类型模版
    Complex<int> c5(3,1);
    Complex<int> c6;
    cout<<"c4="<<c4<<endl;
    cout<<"c5="<<c5<<endl;
    c6=c4+c5;
    cout<<"c4+c5="<<c6<<endl;
    c3=c1-c2;
    cout<<"c4-c5="<<c6<<endl;
    c3=c1*c2;
    cout<<"c4*c5="<<c6<<endl;
    c3=c1/c2;
    cout<<"c4/c5="<<c6<<endl;
 
    return 0;
}

