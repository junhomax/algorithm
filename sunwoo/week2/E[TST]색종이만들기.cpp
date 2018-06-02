#include <stdio.h>

int paper[129][129] = { 0 };
int white = 0, blue = 0;

int divideAndConquer(int xStart, int xEnd, int yStart, int yEnd);
int main(void)
{
	int n, i, j;

	scanf(" %d", &n);

	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++)
			scanf(" %d", &paper[i][j]); //0=흰색 1=파란색
	}

	divideAndConquer(1, n, 1, n);

	printf("%d \n", white);
	printf("%d", blue);

	return 0;
}
int divideAndConquer(int xStart, int xEnd, int yStart, int yEnd)
{
	int i, j, a = 0;

	for (i = yStart; i <= yEnd; i++){
		for (j = xStart; j <= xEnd; j++){
			if (paper[i][j] != paper[yStart][xStart]){ // 한 구간 내의 색종이 색이 가장 왼쪽위 기준으로 모두 같은지 판별 
				a = 1; break;
			}
		}
		if (a == 1)
			break;
	}

	if (a == 0)
	{
		if (paper[yStart][xStart] == 0) // 한 구간내에 색이 모두 같다고 판별 났으면 무슨색인지 확인해서 색종이 개수를 올린다
			white++;
		else
			blue++;

		return 0;
	}
	else
	{
		int xMid = (xStart + xEnd) / 2, yMid = (yStart + yEnd) / 2;
		//색종이를 4등분하여 재귀적으로 개수를 샌다
		divideAndConquer(xStart, xMid, yStart, yMid);
		divideAndConquer(xMid + 1, xEnd, yStart, yMid);
		divideAndConquer(xStart, xMid, yMid + 1, yEnd);
		divideAndConquer(xMid + 1, xEnd, yMid + 1, yEnd);
	}
}
