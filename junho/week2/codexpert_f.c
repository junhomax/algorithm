#include <stdio.h>
#define MAX_RANGE 32
int x,k;
int xBin[32], kBin[32];
int memoize[32], t_res[32];
int xCursor = 0, kCursor = 0;
long long res = 0;
int main(void) {
    register int insertCursor = 0, binCursor = 1, memoizeCursor = 0, destIndex = 0;
    scanf( "%d %d", &x, &k );
    
    while ( x ) {
        if ( ( xBin[ xCursor ] = x % 2 ) == 0 ) memoize[ memoizeCursor++ ] = xCursor;
        xCursor++;
        x /= 2;
    }
    while ( memoizeCursor < MAX_RANGE ) memoize[memoizeCursor++] = xCursor++;
    while ( k ) { kBin[ kCursor++ ] = k % 2; k /= 2; }
    while ( insertCursor < kCursor ) {
        t_res[ memoize[ insertCursor ] ] = kBin[ insertCursor ];
        destIndex = memoize[ insertCursor++ ];
    }
    
    for ( insertCursor = 0; insertCursor <= destIndex; insertCursor++ ) {
        res += ( t_res[insertCursor] * binCursor );
        binCursor *= 2;
    }
    
    printf( "%lld\n", res );
    
    return 0;
}
