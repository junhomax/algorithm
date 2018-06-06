#include <stdio.h>

int N;
int board[128+10][128+10];
int bcount = 0;
int wcount = 0;

int check(int x, int y,int size)
{
	int value = board[x][y];

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (value != board[i][j])
				return -1;
		}
	}
	if (value == 0)
		wcount++;
	else
		bcount++;

	return 1;

}

void input()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);
		}

	}
}


void solve(int x, int y, int size)
{
	if (size == 1)
	{
		if (board[x][y] == 0)
			wcount++;
		else
			bcount++;

		return ;
	}
	
	size = size / 2;
	

	if (check(x, y, size) < 0)
	{
		solve(x,y,size);
	}

	if (check(x, y+size, size) < 0)
	{

		solve(x, y+size, size);
	}

	if (check(x + size, y, size) < 0)
	{
		solve(x+size, y, size);
	}

	if (check(x + size, y + size, size) < 0)
	{
		solve(x + size, y + size, size);
	}

}



int main()
{
	input();

	check(1, 1, N);

	solve(1,1,N);

	printf("%d\n%d", wcount, bcount);

	return 0;
}
