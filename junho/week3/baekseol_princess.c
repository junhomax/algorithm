#include <stdio.h>
#define MAX_NUM_HAT 300000
#define MAX_COLOR_COMB 10000

int N, C, M;
int hat[MAX_NUM_HAT + 10];
int start, end;
int solve(void);
int main(void) {
    register int i;
    int res = 0;
    scanf("%d %d", &N, &C);
    for ( i = 1; i <= N; i++ ) scanf( "%d", &hat[i] );
    scanf( "%d", &M );
    while( M-- ) {
        scanf( "%d %d", &start, &end );
        res = solve();
        if ( res ) printf( "yes %d\n", res );
        else printf( "no\n" );
        res = 0;
    }
    
    return 0;
}

int solve(void) {
    int temp[MAX_COLOR_COMB + 10] = {};
    register int i;
    int goal = ( end - start + 1 ) / 2;
    
    for ( i = start; i <= end; i++ ) {
        if ( ++temp[hat[i]] > goal ) return hat[i];
    }
    
    return 0;
}
