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
			scanf(" %d", &paper[i][j]); //0=��� 1=�Ķ���
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
			if (paper[i][j] != paper[yStart][xStart]){ // �� ���� ���� ������ ���� ���� ������ �������� ��� ������ �Ǻ� 
				a = 1; break;
			}
		}
		if (a == 1)
			break;
	}

	if (a == 0)
	{
		if (paper[yStart][xStart] == 0) // �� �������� ���� ��� ���ٰ� �Ǻ� ������ ���������� Ȯ���ؼ� ������ ������ �ø���
			white++;
		else
			blue++;

		return 0;
	}
	else
	{
		int xMid = (xStart + xEnd) / 2, yMid = (yStart + yEnd) / 2;
		//�����̸� 4����Ͽ� ��������� ������ ����
		divideAndConquer(xStart, xMid, yStart, yMid);
		divideAndConquer(xMid + 1, xEnd, yStart, yMid);
		divideAndConquer(xStart, xMid, yMid + 1, yEnd);
		divideAndConquer(xMid + 1, xEnd, yMid + 1, yEnd);
	}
}