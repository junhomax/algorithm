#include <stdio.h>
int arr[500000];
int Ptr = 0;
int N;
int main(void) {
    int tmp, sol;
    int s, e,m;
    long long cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        s = 0; e = Ptr-1;
        scanf("%d", &tmp);
        sol = Ptr;
        while (s<=e) {
            m = (s + e) / 2;
            if (arr[m] <= tmp) {
                e = m - 1;
                sol = m;
            }
            else {
                s = m + 1;
            }
        }
        if(sol != 0) cnt += (Ptr - sol) + 1;
        else cnt += Ptr - sol;
        s = 0; e = Ptr - 1; sol = Ptr;
        while (s <= e) {
            m = (s + e) / 2;
            if (arr[m] < tmp) {
                e = m - 1;
                sol = m;
            }
            else {
                s = m + 1;
            }
        }
        Ptr = sol;
        arr[Ptr++] = tmp;
    }
    printf("%lld", cnt);
 
    return 0;
}