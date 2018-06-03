#include <iostream>
 
using namespace std;
char arr[1503][1503];
class XMaker {
public:
    int x;
    int y;
    int level;
    XMaker() {}
    XMaker(int i, int j, int k) : x(i), y(j), level(k) {}
};
XMaker Queue[1500 * 1500];
XMaker J[2];
int RdPtr = 0;
int WrPtr = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int R, C, JIndex = 0;
bool result = false;
int main(void)
{
    int checkX(int i, int j);
    int checkK(int i, int j);
    void prgressX(int i, int j, int cnt);
    int MoveJ(int i, int j, char s);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'L') J[JIndex++] = XMaker(i, j, 0);
        }
    }
 
    int cnt = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (checkX(i, j) != 0 && arr[i][j] != 'X') {
                Queue[WrPtr++] = XMaker(i, j, cnt);
            }
        }
    }
 
    for (;;) {
        int tmp = RdPtr;
        for (; WrPtr != RdPtr; RdPtr++) {
            if (Queue[RdPtr].level != cnt) break;
            prgressX(Queue[RdPtr].x, Queue[RdPtr].y, Queue[RdPtr].level);
        }
        arr[J[0].x][J[0].y] = 'K';
        if (cnt == 1) {
            if (MoveJ(J[0].x, J[0].y, 'K') != 0) break;
        }
        else {
            for (; WrPtr != tmp; tmp++) {
                if (Queue[tmp].level != cnt) break;
                if (checkK(Queue[tmp].x, Queue[tmp].y) > 0) {
                    arr[Queue[tmp].x][Queue[tmp].y] = 'K';
                    if (MoveJ(Queue[tmp].x, Queue[tmp].y, 'K') != 0) {
                        result = true;
                        break;
                    }
                }
            }
            if (result)break;
        }
        cnt++;
    }
    cout << cnt;
 
    return 0;
}
int checkX(int i, int j) {
    for (int a = 0; a < 4; a++) {
        if (arr[i + dx[a]][j + dy[a]] != 'X' &&  i + dx[a] >= 0 && i + dx[a] < R  && j + dy[a] >= 0 && j + dy[a] < C) {
            return 1;
        }
    }
}
int checkK(int i, int j) {
    int ck = 0;
    for (int a = 0; a < 4; a++) {
        if (arr[i + dx[a]][j + dy[a]] == 'K'&&  i + dx[a] >= 0 && i + dx[a] < R  && j + dy[a] >= 0 && j + dy[a] < C) {
            ck++;
        }
    }
    return ck;
}
void prgressX(int i, int j, int cnt) {
    for (int a = 0; a < 4; a++) {
        if (arr[i + dx[a]][j + dy[a]] == 'X') {
            Queue[WrPtr++] = XMaker(i + dx[a], j + dy[a], cnt + 1);
            arr[i + dx[a]][j + dy[a]] = 'V';
        }
    }
}
int MoveJ(int i, int j, char s) {
    int num = 0;
    for (int a = 0; a < 4; a++) {
        if (arr[i + dx[a]][j + dy[a]] != 'X' && arr[i + dx[a]][j + dy[a]] != s && i + dx[a] >= 0 && i + dx[a] < R  && j + dy[a] >= 0 && j + dy[a] < C) {
            if (J[1].x == i + dx[a] && J[1].y == j + dy[a]) return 1;
            arr[i + dx[a]][j + dy[a]] = s;
            num += MoveJ(i + dx[a], j + dy[a], s);
        }
    }
    return num;
}