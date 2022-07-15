#include <iostream>
using namespace std;

void selection_sort(int arr[]) {
    int i,j,min;
    for (i=0; i<9;i++) {    //遍历数组寻找最小值
        min=i;
        for (j=i+1;j<10;j++)
            if(arr[min]>arr[j])
                min=j;
        swap(arr[i],arr[min]);  //将最小值移至起始端
    }
}

int main(){
    int number[11]={0};
    for(int i=0;i<10;i++)
        cin >> number[i];
    selection_sort(number);
    for(int i=0;i<10;i++)
        cout << number[i] << endl;
    return 0;
}


