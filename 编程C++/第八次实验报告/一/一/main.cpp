#include <iostream>
using namespace std;

template<typename T>    //定义一个模版T
void MathHelper(T num[],int size){
    T max=num[0], min=num[0], total=0;
    for(int i=0;i<size;i++){
        if(num[i]>max)  //最大值
            max=num[i];
        if(num[i]<min)  //最小值
            min=num[i];
        total+=num[i];
    }
    cout << "Max：" << max << endl;
    cout << "Min：" << min << endl;
    if(size==0)
        cout << "Average:" << 0 << endl;        //防止空集情况
    else
        cout << "Average:" << total/double(size) << endl;
}

int main() {
    //测试函数
    int a[10] = { 3,2,1,5,4,6,7,8 };    //以int类型调试模版
    double b[10] = { 3.14,4.5,6.7,4.2,6.6 };    //以double类型调试模版
    MathHelper<int>(a, sizeof(a) / sizeof(a[0]));
    cout << endl;
    MathHelper<double>(b, sizeof(b) / sizeof(b[0]));
    
    return 0;
}


