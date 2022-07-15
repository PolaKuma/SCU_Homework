//
//  main.cpp
//  test
//
//  Created by Junjie on 2022/3/24.
//

//扑克随机洗牌结果到保存文件
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#define SUIT_NUMBER 4
#define FACE_NUMBER 13
using namespace std;
 
class Card //扑克类
{
public:
    string suit; //花色
    string face; //面值
};
 
class CardManager
{
private:
    Card deck[SUIT_NUMBER][FACE_NUMBER]; //4*13=52张扑克牌
public:
    CardManager() { //构造函数
        string suit[] = {"红桃","花块","梅花","黑桃"};
        string face[]=
        {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        for(int i=0;i<SUIT_NUMBER;i++)
        {
            for(int j=0;j<FACE_NUMBER;j++)
            {
                deck[i][j].suit=suit[i];
                deck[i][j].face=face[j];
            }
        }
    }
    
    void shuffle() { //洗牌
        srand(time(NULL));
        for(int i=0;i<SUIT_NUMBER;i++)
        {
            for(int j=0;j<FACE_NUMBER;j++)
            {
                int randnum1 = rand()%SUIT_NUMBER;
                int randnum2 = rand()&FACE_NUMBER;
                
                //进行洗牌(交换)
                Card temp=deck[i][j];
                deck[i][j]=deck[randnum1][randnum2];
                deck[randnum1][randnum2]=temp;
            }
        }
    }
    
    void deal() { //发牌
        cout<<"=================="<<endl;
        cout<<" 52张牌洗牌结果 "<<endl;
        string person[] = {"甲","乙","丙","丁"};
        for(int i=0;i<SUIT_NUMBER;i++)
        {
            cout<<person[i]<<"的牌："<<endl;
            for(int j=0;j<FACE_NUMBER;j++)
            {
                cout<<"第"<<j+1<<"张："<<deck[i][j].suit<<deck[i][j].face<<"\t\t";
                if((j+1) % 4 == 0) {
                    cout<<endl;
                }
            }
            cout<<endl<<endl;
        }
    }
};
 
int main() //主函数
{
    CardManager cm; //扑克管理类对象
    cm.shuffle(); //洗牌
    cm.deal(); //发牌
    
    return 0;
}


