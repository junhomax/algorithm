#include <stdio.h>

#define MAX_NUM 101
#define CIRCULAR_NUM 10
#define MAX_SPIN_NUM 3
#define INIT_NUM -1
#define INF 987654321
#define SMAX(a,b) (a) > (b) ? (a) : (b)
#define SMIN(a,b) (a) < (b) ? (a) : (b)

int N;
int target[MAX_NUM], answer[MAX_NUM];
int memoize[CIRCULAR_NUM][CIRCULAR_NUM][CIRCULAR_NUM][MAX_NUM + 3];

/*
 This function initiates the array for memoization.
 input       : void
 output      : void
 complexity  : O(N)
 */
void init( void ) {
    register int i, j, k, l;
    for ( i = 0; i < CIRCULAR_NUM; i++ )
        for ( j = 0; j < CIRCULAR_NUM; j++ )
            for ( k = 0; k < CIRCULAR_NUM; k++ )
                for ( l = 0; l < MAX_NUM + 3; l++ )
                    memoize[i][j][k][l] = INIT_NUM;
}

/*
 This function calculates the lowest cost for spin target lock to adjust answer lock.
 input       : int ( expected number to spin )
 output      : int ( the lowest cost to spin )
 complexity  : O(1)
 */
int calcSpin( int expectedNum ) {
    return expectedNum < 0 ?
    ( CIRCULAR_NUM - ( ( -expectedNum ) % CIRCULAR_NUM ) ) % CIRCULAR_NUM
    : expectedNum % CIRCULAR_NUM;
}

/*
 This function calculates the lowest cost for spin all target number
 to answer number by simulating spin of number.
 input       : int firstNumber, int secondNumber, int thirdNumber, int slidingNumber
 output      : int ( the lowest cost to spin all target lock elements )
 complexity  : O(N); O(3 * 6 * N)
 */
int solve( int first, int second, int third, int num ) {
    int i;
    int &ret = memoize[first][second][third][num];
    if ( num == N ) return 0;
    if ( ret != -1 ) return ret;
    ret = INF;
    
    if ( calcSpin( target[num] + first ) == answer[num] ) {
        ret = solve( second, third, 0, num + 1 );
    }
    
    for ( i = -MAX_SPIN_NUM; i <= MAX_SPIN_NUM; i++ ) {
        int afterFirst, afterSecond, afterThird;
        if ( i == 0 ) continue;
        afterFirst  = calcSpin( first + i );
        afterSecond = calcSpin( second + i );
        afterThird  = calcSpin( third + i );
        
        ret = SMIN( ret, solve( afterFirst, second, third, num ) + 1 );
        ret = SMIN( ret, solve( afterFirst, afterSecond, third, num ) + 1 );
        ret = SMIN( ret, solve( afterFirst, afterSecond, afterThird, num ) + 1 );
    }
    
    return ret;
}

int main( void ) {
    register int i;
    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) scanf( "%d", &target[i] );
    for ( i = 0; i < N; i++ ) scanf( "%d", &answer[i] );
    
    init();
    printf( "%d\n", solve( 0, 0, 0, 0 ) );
    
    return 0;
}
