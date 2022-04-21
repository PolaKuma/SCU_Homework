//
//  main.cpp
//  五子棋
//
//  Created by Junjie on 2022/4/21.
//
#include<iostream>
#include<string>
using namespace std;


class Chess{
public:
    char board[15][15];
    Chess(){for(int i=0;i<15;i++){for(int j=0;j<15;j++){board[i][j]='-';}}};
    ~Chess(){};
    int Judge();
    int searchRight();
    int searchDown();
    int searchX();
    void Print();
    void Play();
};

int Chess::searchRight(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int point=0;
            for(int k=0;k<5;k++){
                if(board[i][j+k]=='X')
                    point++;
                else if(board[i][j+k]=='O')
                    point--;
            }
            if(point>=5)
                return 1;
            else if (point<=-5)
                return -1;
        }
    }
    return 0;
}

int Chess::searchDown(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int point=0;
            for(int k=0;k<5;k++){
                if(board[i+k][j]=='X')
                    point++;
                else if(board[i+k][j]=='O')
                    point--;
            }
            if(point>=5)
                return 1;
            else if (point<=-5)
                return -1;
            }
        }
    return 0;
}

int Chess::searchX(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int point=0;
            for(int k=0;k<5;k++){
                if(board[i+k][j+k]=='X')
                    point++;
                else if(board[i+k][j+k]=='O')
                    point--;
            }
            if(point>=5)
                return 1;
            else if (point<=-5)
                return -1;
        }
    }
    return 0;
}

int Chess::Judge(){
    if(searchRight()==1 || searchDown()==1 || searchX()==1){
        cout << "Black!" << endl;
        return 1;
    }
    else if(searchRight()==-1 || searchDown()==-1 || searchX()==-1){
        cout << "White!" << endl;
        return -1;
    }
    else
        return 0;
}

void Chess::Print(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Chess::Play(){
    Chess obj;
    obj.Print();
    while(1){
        int B_x,B_y;
        int W_x,W_y;
        cin >> B_x >> B_y;
        obj.board[B_x][B_y]='X';
        obj.Print();
        if(obj.Judge()!=0)
            break;
        cin >> W_x >> W_y;
        obj.board[W_x][W_y]='O';
        obj.Print();
        obj.Judge();
        if(obj.Judge()!=0)
            break;
    }
}

int main(){
    Chess test;
    test.Play();
}
