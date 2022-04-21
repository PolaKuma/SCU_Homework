//
//  main.cpp
//  Poker(finished)
//
//  Created by Junjie on 2022/3/29.
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
    Poker();    //构造函数
    ~Poker(){};     //析构函数
    void shuffle();     //洗牌
    void deal(int n);    //发牌
    int Add(int n,int a,int nowTotal);    //计算总点数（n为抽几张牌，a为从哪张牌开始抽，nowTotal是现有点数）
    void Play();   //主游戏程序
};

Poker::Poker(){
    string SUITS[] = {"c","d","h","s"};
    string RANKS[] = {"2","3","4","5","6","7","8","9","10","A","J","Q","K"};
    for(int i=0;i<4 || Add(2,0,0)>21 || Add(2,2,0)>21;i++)
    {
        for(int j=0;j<13 || Add(2,0,0)>21 || Add(2,2,0)>21;j++)
        {
            card[i][j].suit=SUITS[i];
            card[i][j].rank=RANKS[j];
        }
    }
}

void Poker::shuffle(){
    srand((int)time(0));    //产生随机种子
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

void Poker::deal(int n){
    cout << "您获得的牌：" << endl;
    for(int j=0;j<n;j++)
        cout << (*card+j)->suit << (*card+j)->rank << endl;
}

int Poker::Add(int n,int a, int nowTotal){
    int total=0;
    for(int i=a;i<n+a;i++){
        if((*card+i)->rank[0]=='A')
            if(nowTotal+11<=21){
                total+=11;
            }else
                total++;
        else if((*card+i)->rank[0]=='J' || (*card+i)->rank[0]=='Q' || (*card+i)->rank[0]=='K')
            total+=10;
        else if((*card+i)->rank[0]>='2' && (*card+i)->rank[0]<='9')
            total+=(int)(*card+i)->rank[0]-48;
        else if((*card+i)->rank[0]=='1')
            total+=10;
        }
    return total;
}

void Poker::Play(){
    //最初准备工作
    Poker player;   //定义玩家
    Poker computer;     //定义电脑
    player.shuffle();   //洗牌，以玩家的牌为主牌，之后全从玩家牌抽牌（避免重复抽牌）
    player.deal(2);     //给玩家发1，2张牌，电脑牌点数即第3，4张牌
    int playerTotal=player.Add(2,0,0);      //定义玩家总点数
    int computerTotal=player.Add(2,2,0);    //定义电脑总点数
    int count=0;    //定义抽到第几张牌
    char choice;    //定义是否继续抽牌选择
    cout << "闲家此时总点数为：" << playerTotal << endl;
    cout << "庄家此时有一张牌：" << player.card[0][2].suit << player.card[0][2].rank << endl;
    
    //玩家继续抽牌
    cout << "是否继续抽牌？";
    cin >> choice;
    for(count=4;choice=='Y' && playerTotal<=21 ;count++){
        cout << "您抽中了：" << (*player.card+count)->suit << (*player.card+count)->rank << endl;
        playerTotal+=player.Add(1,count,playerTotal);
        cout << "闲家此时总点数为：" << playerTotal << endl;
        if(playerTotal>21)  //如果玩家点数超过21则不能继续抽牌
            break;
        cout << "是否继续抽牌？" ;
        cin >> choice;
    }
    
    //电脑抽牌，若点数小于等于17必须抽牌，大于则不能抽牌
    while(computerTotal<=17)
        computerTotal+=player.Add(1,count,computerTotal);
    
    //判断成败并输出结果
    if(computerTotal>21 && playerTotal>21){
        cout << "平局！" << endl << "闲家此时总点数为：" << playerTotal << endl << "庄家此时总点数为：" << computerTotal << endl;
    }else if(computerTotal>21 && playerTotal<=21){
        cout << "闲家获胜！" << endl << "闲家此时总点数为：" << playerTotal << endl << "庄家此时总点数为：" << computerTotal << endl;
    }else if (computerTotal<=21 && playerTotal>21){
        cout << "庄家获胜！" << endl << "闲家此时总点数为：" << playerTotal << endl << "庄家此时总点数为：" << computerTotal << endl;
    }else{
        if(computerTotal>playerTotal){
            cout << "庄家获胜！" << endl << "闲家此时总点数为：" << playerTotal << endl << "庄家此时总点数为：" << computerTotal << endl;
        }else if (computerTotal<playerTotal){
            cout << "闲家获胜！" << endl << "闲家此时总点数为：" << playerTotal << endl << "庄家此时总点数为：" << computerTotal << endl;
        }else
            cout << "平局！" << endl << "双方此时总点数为：" << playerTotal << endl;
    }
}
int main(){     //测试程序
    Poker test;
    test.Play();
    return 0;
}

