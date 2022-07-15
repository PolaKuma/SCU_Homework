#include <fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

//(一）定义学生类
class Student
{
public:
    Student(){};
    Student(int n, string nam, double c, double m, double e):num(n),name(nam),cpp(c),math(m),english(e){total=c+m+e;}
    void set_value(int n,string nam, double c, double m, double e);
    string get_name(){return name;}
    double get_cpp(){return cpp;}
    double get_math(){return math;}
    double get_english(){return english;}
    double get_total(){return total;}
    void set_cpp(double c){cpp=c;}
    void set_math(double m){math=m;}
    void set_english(double e){english=e;}
    void set_total(double t){total=t;}
    friend  ostream& operator<<(ostream&, Student&);
private:
    int num;
    string name;
    double cpp;
    double math;
    double english;
    double total;
};

void Student::set_value(int n,string nam, double c, double m, double e)
{
    num=n;
    name=nam;
    cpp=c;
    math=m;
    english=e;
    total=c+m+e;
}

ostream& operator<<(ostream& out, Student& s)
{
    out<<s.num<<" "<<s.name<<" "<<s.cpp<<" "<<s.math<<" "<<s.english<<" "<<s.total<<endl;
    return out;
}

int main( )
{
    Student stud[100]; //stud[100]为保存数据的对象数组
    int i,n;
    string sname;
    double scpp, smath, senglish;

    //（二）读入学生的成绩，并求出总分，用对象数组进行存储。
    ifstream infile("score.dat",ios::in);  //以输入的方式打开文件,ASCII文件
    if(!infile)       //测试是否成功打开
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<100;i++)
    {
        infile>>n>>sname>>scpp>>smath>>senglish;
        stud[i].set_value(n,sname, scpp, smath, senglish);
    }
    infile.close();

    //（三）将所有数据保存到一个二进制文件binary_score.dat中
    ofstream outfile("binary_score.dat",ios::out|ios::binary);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<100;i++)
    {
        outfile.write((char*)&stud[i], sizeof(stud[i]));
    }
    //（三）最后在文件中写入你自己的各科成绩
    cout<<"输入你自己的信息：";
    cin>>n>>sname>>scpp>>smath>>senglish;
    Student me(n,sname, scpp, smath, senglish);
    outfile.write((char*)&me, sizeof(me));
    outfile.close();

    //（四）为验证输出文件正确，再将binary_score.dat中的记录逐一读出到学生对象中并输出查看。
    Student s;
    ifstream infile2("binary_score.dat",ios::in);
    if(!infile2)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    while(true)
    {
        infile2.read((char*)&s, sizeof(s));
        if(infile2.eof()) break;
        cout<<s;
    }
    infile2.close();
    return 0;
}

