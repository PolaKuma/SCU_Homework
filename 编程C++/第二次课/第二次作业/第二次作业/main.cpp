//经过查阅发现动态输入数组可以使用vector函数包
#include <iostream>
#include <vector>
using namespace std;

void Plusone(vector<int>& digits){
    for(unsigned long i=digits.size()-1;i>=0;i--){  //倒序遍历数组
        if(digits[i]!=9){   //如果遍历数组不等于9，那么就+1，直接退出循环得到结果
            ++digits[i];
            break;
        }else
            digits[i]=0;    //遍历到9，那就让这个数置0，继续执行如上操作
    }
    
    if(digits[0]==0)    //题设首位不为0，如果第一位变成0，也就是需要申请一个新的lenth+1的数组，最开始那位置1
        digits.insert(digits.begin(),1);    //使用vector内置函数直接插入1
    for(int i=0;i<digits.size();i++)    //打印函数结果
        cout << digits[i] << " ";
}

int main(){
    vector<int> test;   //测试数组
    int number;
    do{     //使用vector内置函数动态输入数组
        cin >> number;
        test.push_back(number);
    }while(cin.get()!='\n');
    Plusone(test);
    return 0;
}










