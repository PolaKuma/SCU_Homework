#include <iostream>
#include<algorithm>
using namespace std;

template<class T>
class Sort{
public:
    void bubbleSort(T arr[],int n);     //冒泡排序
    void selectSort(T arr[],int n);     //选择排序
    void insertSort(T arr[],int n);     //插入排序
};

template<class T>
void Sort<T>::bubbleSort(T arr[], int n){
    int i, j, flag;
    T temp;
    for(i = 0; i < n-1; i++) { // 进行n-1次
        flag = 0; // 交换标志，0表示无交换，1表示有交换
        for(j = 0; j < (n-i-1); j++) { // 数组下标最大为n-1
            if(arr[j] > arr[j+1]) { // 逆序就交换
            flag = 1; // 有交换
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
          }
        }
        if(flag == 0) // 无交换,说明已经全部排好序，提前结束
          break;
      }
    }

template<class T>
void Sort<T>::selectSort(T arr[], int n){
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
            swap(arr[i],arr[minIndex]);
        }
    }
}

template<class T>
void Sort<T>::insertSort(T arr[], int n){
    for(int i=0;i<n;i++){
        int j=i-1,k=arr[i];
        while(j>=0&&arr[j]>k){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
}

int main() {
    int i, n, arr[20];
    Sort<int> test;     //创建测试用例
    cout << "请输入要排序的数的个数：";
    cin >> n;
    cout << "请输入要排序的数：";
    for(i = 0; i < n; i++)
        cin >> arr[i];
    cout << "排序前：" << endl;
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    test.bubbleSort(arr, n);
    cout << "排序后：" << endl;
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    test.selectSort(arr, n);
    cout << "排序后：" << endl;
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    test.insertSort(arr, n);
    cout << "排序后：" << endl;
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
  return 0;
}

