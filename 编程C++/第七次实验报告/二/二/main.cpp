#include <iostream>
using namespace std;

class Discount{
private:
    int num;    //售货员编号
    double price;   //商品价格
    int quantity;   //出售数量
    static int n;   //出售总数量
    static double sum;  //出售总价格
    static double discount; //折扣
public:
    void Input(){cin >> num >> quantity >> price;}
    void Sum();
    static double Average(){return sum/n;}
    static void Display(){cout << sum << endl << Average() << endl;}
};

double Discount::sum=0;
int Discount::n=0;
double Discount::discount=0.05;

void Discount::Sum(){
    if(quantity>10){sum+=quantity*price*(1-discount)*0.98; n+=quantity;}
    else{sum+=quantity*price*(1-discount); n+=quantity;}
}

int main(){
    int m;
    cin >> m;
    Discount *people=new Discount[m+1];
    for(int i=0;i<m;i++){
        people[i].Input();
    }
    for(int i=0;i<m;i++){people[i].Sum();}
    Discount::Display();
    
    return 0;
}

