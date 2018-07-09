/**************************************************************
    Problem: 2543
    User: jaemin.yeon
    Language: C++
    Result: Success
    Time:39 ms
    Memory:2120 kb
****************************************************************/
 
 
#include <stdio.h>
int N;
int x, y;
int arr[513][513];
void solve(int start_x, int start_y, int dest_x, int dest_y, int x, int y)
{
    int m_x = (start_x + dest_x) / 2;
    int m_y = (start_y + dest_y) / 2;
    int sel;
    if (start_x >= dest_x && start_y >= dest_y) return;
    if (x <= m_x && y <= m_y) {
        sel = 1;
        solve(start_x, start_y, m_x, m_y, x, y);
        arr[m_x + 1][m_y] = 1;
        arr[m_x + 1][m_y+1] = 1;
        arr[m_x ][m_y+1] = 1;
    }
    else if (x <= m_x && y > m_y) {
        sel = 2;
        solve(start_x, m_y+1, m_x, dest_y, x, y);
        arr[m_x][m_y] = 2;
        arr[m_x + 1][m_y + 1] = 2;
        arr[m_x+1][m_y] = 2;
    }
    else if (x > m_x && y <= m_y) {
        sel = 3;
        solve(m_x + 1, start_y, dest_x, m_y, x, y);
        arr[m_x][m_y] = 3;
        arr[m_x + 1][m_y + 1] = 3;
        arr[m_x][m_y + 1] = 3;
    }
    if (x > m_x && y > m_y) {
        sel = 4;
        solve(m_x+1, m_y+1, dest_x, dest_y, x, y);
        arr[m_x][m_y] = 4;
        arr[m_x][m_y + 1] = 4;
        arr[m_x + 1][m_y] = 4;
    }
    if(sel !=1) solve(start_x, start_y, m_x, m_y, m_x, m_y);
    if (sel != 2) solve(start_x, m_y + 1, m_x, dest_y, m_x, m_y + 1);
    if (sel != 3) solve(m_x + 1, start_y, dest_x, m_y, m_x+1, m_y);
    if (sel != 4) solve(m_x + 1, m_y + 1, dest_x, dest_y, m_x + 1, m_y + 1);
 
}
int main(void)
{
    scanf("%d", &N);
    scanf("%d %d", &x, &y);
    solve(1, 1, N, N, x+1, y+1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}