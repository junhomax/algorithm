#include <stdio.h>
 
int n, res = 0;
int getOneFromBinary( int num );
 
int main(void) {
    scanf( "%d", &n );
    while ( n ) res += __builtin_popcount( n-- );
    printf( "%d\n", res );
    return 0;
}
