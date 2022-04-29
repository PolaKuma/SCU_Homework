#include <iostream>
#include <graphics.h>
using namespace std;
#define BLOCK 24

class Chess{
private:
    int map[15][15]={0};
    int number;
    int x;
    int y;
    bool is_Show;
public:
    Chess();
    ~Chess(){}
    void Display();
    void moseMoveMsg(ExMessage *msg);
    void mosePressMsg(ExMessage *msg);
    int Judge();
    void Play();
};

Chess::Chess():number(0),x(0),y(0),is_Show(false){}

void Chess::Display(){
    setlinecolor(BLACK);
    for (int i = 0; i < 15; i++) {
        if (i == 0 || i == 14)
            setlinestyle(PS_SOLID, 2.5);
        else
            setlinestyle(PS_SOLID, 1);
        line(5 * BLOCK, 6 * BLOCK + i * BLOCK, 5 * BLOCK + 14 * BLOCK, 6 * BLOCK + i * BLOCK);
        line(5 * BLOCK + i * BLOCK, 6 * BLOCK, 5 * BLOCK + i * BLOCK, 6 * BLOCK + 14 * BLOCK);
    }
    setfillcolor(BLACK);
    solidcircle(5 * BLOCK + 7 * BLOCK, 6 * BLOCK + 7 * BLOCK, 4.5);
    solidcircle(5 * BLOCK + 3 * BLOCK, 6 * BLOCK + 3 * BLOCK, 4.5);
    solidcircle(5 * BLOCK + 3 * BLOCK, 6 * BLOCK + 11 * BLOCK, 4.5);
    solidcircle(5 * BLOCK + 11 * BLOCK, 6 * BLOCK + 3 * BLOCK, 4.5);
    solidcircle(5 * BLOCK + 11 * BLOCK, 6 * BLOCK + 11 * BLOCK, 4.5);

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (map[i][j] == 1) {
                setfillcolor(BLACK);
                solidcircle(5 * BLOCK + BLOCK * i, 6 * BLOCK + BLOCK * j,10);
            }
            else if (map[i][j] == -1) {
                setfillcolor(WHITE);
                solidcircle(5 * BLOCK + BLOCK * i, 6 * BLOCK + BLOCK * j,10);
            }
        }
    }
    if (is_Show) {
        rectangle(x - 10, y - 10, x + 10, y + 10);
    }
}

void Chess::moseMoveMsg(ExMessage *msg){
    is_Show=false;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            int gridx = (j+5)*BLOCK;
            int gridy = (i+6)*BLOCK;
            if (abs(msg->x - gridx) <= 10 && abs(msg->y - gridy) <= 10) {
                is_Show = true;
                x = gridx;
                y = gridy;
            }
        }
}
}

void Chess::mosePressMsg(ExMessage *msg){
    if (msg->message == WM_LBUTTONDOWN) {
        if (number % 2 == 0 && map[x / BLOCK - 5][y / BLOCK - 6]==0) {
            map[x / BLOCK - 5][y / BLOCK - 6] = 1;
            number++;
        }
        else if (number % 2 == 1 && map[x / BLOCK - 5][y / BLOCK - 6] == 0) {
            map[x / BLOCK - 5][y / BLOCK - 6] = -1;
            number++;
        }
    }
}

int Chess::Judge(){
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if ((map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 1 && map[i + 3][j] == 1 && map[i + 4][j] == 1) ||
                (map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1 && map[i][j + 3] == 1 && map[i][j + 4] == 1) ||
                (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 1 && map[i + 4][j + 4] == 1)||
                (map[i][j] == 1 && map[i - 1][j + 1] == 1 && map[i - 2][j + 2] == 1 && map[i - 3][j + 3] == 1 && map[i - 4][j + 4] == 1)) {
                FlushBatchDraw();
                MessageBox(GetHWnd(), "BLACK WIN!", "RESULT", MB_OK);
                return 1;
            }
            else if ((map[i][j] == -1 && map[i + 1][j] == -1 && map[i + 2][j] == -1 && map[i + 3][j] == -1 && map[i + 4][j] == -1) ||
                (map[i][j] == -1 && map[i][j + 1] == -1 && map[i][j + 2] == -1 && map[i][j + 3] == -1 && map[i][j + 4] == -1) ||
                (map[i][j] == -1 && map[i + 1][j + 1] == -1 && map[i + 2][j + 2] == -1 && map[i + 3][j + 3] == -1 && map[i + 4][j + 4] == -1)||
                (map[i][j] == -1 && map[i - 1][j + 1] == -1 && map[i - 2][j + 2] == -1 && map[i - 3][j + 3] == -1 && map[i - 4][j + 4] == -1)) {
                FlushBatchDraw();
                MessageBox(GetHWnd(), "WHITE WIN!", "RESULT", MB_OK);
                return 1;
            }
        }
    }
    return 0;
}

void Chess::Play(){
    initgraph(600, 500);
    IMAGE bk;
    loadimage(&bk, "Res/BK.jpg");
    putimage(0, 0, &bk);
    while (true) {
        BeginBatchDraw();
        putimage(0, 0, &bk);
        Display();
        if (Judge() != 0)
            break;
        EndBatchDraw();
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE)) {
            switch (msg.message) {
            case WM_MOUSEMOVE: //鼠标移动
                moseMoveMsg(&msg);
                break;
            case WM_LBUTTONDOWN: //鼠标左键
                mosePressMsg(&msg);
                break;
            default: break;
            }
        }
    }
    getchar();
}

int main(){
    Chess test;
    test.Play();
    return 0;
}
