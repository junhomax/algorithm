#include <iostream>
using namespace std;
int main() {
    int a[30]; int n; int i = 0; 
    cin >> n;
     
    while (n != 0 || n%2 == 1) {
        a[i++] = n % 2;
        n /= 2;
    }
    int sum = 0; int one = 0;
    for (int j = i-1; j >= 0; j--) {
        if (a[j] == 1) {
            int tmp = 1;
            for (int k = 0; k < j ; k++) tmp *= 2;
            sum += ((tmp*j)/2 + tmp*one++);
        }
    }
    sum += one;
    cout << sum ;
    return 0;
}