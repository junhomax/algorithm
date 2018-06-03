#include <iostream>
using namespace std;
int main() {
    int a[32]; int x; int i = 0; int k; int x__;
    cin >> x >> k;
    while (x != 0 || x % 2 == 1) {
        a[i++] = x % 2;
        x /= 2;
    }
    int one = 0; int pre = 0; int tmp =1;
    for (int j = 0; j < i; j++) {
        if (a[j] == 0) {
            for (int p = pre; p < j; p++) tmp *= 2;
            pre = j;
            a[one++] = tmp;
            tmp = 1;
        }
    }
    for (int p = pre; p < i; p++) tmp *= 2;
    a[one] = tmp;
    for (int j = one+1; j < 32; j++) {
        a[j] = 2;
    }
    unsigned long long sum = 0; i = 0; unsigned long long con = 1;
    while (k != 0 || k % 2 == 1) {
        sum = sum + a[i]*(k % 2)*con;
        con *= a[i++];
        k /= 2;
    }
    cout << sum;
    return 0;
}