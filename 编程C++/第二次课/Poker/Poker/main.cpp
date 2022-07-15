//
//  main.cpp
//  Poker
//
//  Created by Junjie on 2022/3/24.
//

#include <iostream>
#include <cstring>
using namespace std;

class Cards{
public:
    string rank;
    string suit;
};

class Poker{
private:
    Cards card[4][13];
public:
    Poker() { //构造函数
        string SUITS[] = {"c","d","h","s"};
        string RANKS[] = {"2","3","4","5","6","7","8","9","10","A","J","Q","K"};
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<13;j++)
            {
                card[i][j].suit=SUITS[i];
                card[i][j].rank=RANKS[j];
            }
        }
    }

void shuffle() { //洗牌
    srand((unsigned)time(NULL));    //产生随机种子
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            int randnum1 = rand()%4;
            int randnum2 = rand()%13;
            
            //进行洗牌(交换)
            Cards temp=card[i][j];
            card[i][j]=card[randnum1][randnum2];
            card[randnum1][randnum2]=temp;
        }
    }
}

void deal(int n){    //发牌
    cout << "您获得的牌：" << endl;
    for(int j=0;j<n;j++){
        cout << (*card+j)->suit << (*card+j)->rank << endl;
    }
}
    
void Add(int n){    //计算总点数
    int total=0;
    for(int i=0;i<n;i++){
        if(card[0][i].rank[0]=='A')
            total+=11;
        else if(card[0][i].rank[0]=='J' || card[0][i].rank[0]=='Q' || card[0][i].rank[0]=='K')
            total+=10;
        else if(card[0][i].rank[0]>='2' && card[0][i].rank[0]<='9')
            total+=(int)card[0][i].rank[0]-48;
        else if(card[0][i].rank[0]=='1')
            total+=10;
        }
    cout << "总点数为：" << total << endl;
    }
};

int main(){
    Poker test;
    test.shuffle(); //洗牌
    test.deal(2); //发牌
    test.Add(2);    //计算总点数
}
