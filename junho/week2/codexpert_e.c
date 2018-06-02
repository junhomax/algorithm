#include <stdio.h>
 
int n;
int paper[129][129];
int colorPaper[2] = { 0, 0 }; // 0 = white, 1 = blue
 
int isSameColor( int x, int y, int n );
void divideAndConquer( int x, int y, int n );
 
int main( void ) {
    register int i, j;
    scanf( "%d", &n );
    for ( i = 0; i < n; i++ ) for ( j = 0; j < n; j++ ) scanf( "%d", &paper[i][j] );
    divideAndConquer( 0, 0, n );
    printf( "%d\n%d\n", colorPaper[0], colorPaper[1] );
    return 0;
}
 
void divideAndConquer( int x, int y, int len ) {
    if ( len == 1 ) {
        colorPaper[ paper[x][y] ]++; return;
    }
    len /= 2;
    if ( !isSameColor( x , y, len ) ) divideAndConquer( x, y, len );
    if ( !isSameColor( x + len, y, len ) ) divideAndConquer( x + len, y, len );
    if ( !isSameColor( x, y + len, len ) ) divideAndConquer( x, y + len, len );
    if ( !isSameColor( x + len, y + len, len ) ) divideAndConquer( x + len, y + len, len );
}
 
int isSameColor( int x, int y, int len ) {
    register int i, j;
    int color = paper[x][y];
    for ( i = x; i < x + len; i++ ) for ( j = y; j < y + len; j++ )
        if ( paper[i][j] != color ) return 0;
     
    colorPaper[color]++;
    return 1;
}
