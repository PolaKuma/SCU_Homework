#include <iostream>
using namespace std;

class IllegalArgumentException{     //定义异常类
public:
    IllegalArgumentException(){}
    ~IllegalArgumentException(){}
    void GetExceptionReason() const{cout << "N必须是正数或者0" << endl;}   //报错原因
};

int main(){
    while(true){    //开始输入N必须为0或正整数，不是则跳转回来
        try{
            int N;      //定义数字数量
            cout << "输入N的值：";
            cin >> N;
            if(N<0)     //如果N为负数，则抛出一个异常
                throw IllegalArgumentException();
            cout << "你需要输入" << N << "个数" << endl;
            int tempNumber;     //临时存储数字
            double sum=0;       //定义数字求和
            for(int i=0;i<N;i++){
                cout << "请输入第" << i+1 << "个数：";
                try{
                    cin >> tempNumber;
                    if(tempNumber<0)    //如果数字为负数，则抛出一个异常
                        throw IllegalArgumentException();
                    sum+=tempNumber;
                }catch(IllegalArgumentException E){     //捕获数字为负数的异常
                    E.GetExceptionReason();
                    i--;    //提示用户重新输入
                }
            }
            cout << "平均数是：" << sum/N << endl;   //计算平均数
            break;      //成功计算后退出程序
        }catch(IllegalArgumentException E){     //捕获N为负数的异常
            E.GetExceptionReason();
        }
    }
    return 0;
}


