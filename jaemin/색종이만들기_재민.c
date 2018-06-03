#include <stdio.h>
 
int arr[128][128];
int white_res = 0 , blue_res = 0;
int main(void)
{
    int N, i, j;
    void func(int x, int y, int size);
    scanf("%d", &N);
    for (i = 0; i < N; i++) for (j = 0; j < N; j++) scanf("%d", &arr[i][j]);
    func(0, 0, N);
    printf("%d\n%d", white_res, blue_res);
    return 0;
}
void func(int x, int y, int size) {
    int start_color = arr[x][y];
    int i, j,res = 0;
    if (size==0) return;
    for (i = x; i < size + x; i++) {
        for (j = y; j < size + y; j++) {
            if (arr[i][j] != start_color) {
                res = 1;
                break;
            }
        }
        if (res) break;
    }
    if (res) {
        func(x, y, size/2);
        func(x+ size / 2, y, size / 2);
        func(x, y+ size / 2, size / 2);
        func(x+ size / 2, y+ size / 2, size / 2);
    }
    else {
        if (start_color) blue_res++;
        else white_res++;
    }
}