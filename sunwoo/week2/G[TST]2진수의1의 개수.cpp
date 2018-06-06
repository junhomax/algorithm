#include <stdio.h>

int N;//노드수
int M;//색상번호
int SOL[14];
int MAP[14][14];
int RET;

int check(int V, int color)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		if (MAP[V][i] && SOL[i] == color) return 1;
	}
	return 0;
}
int flag;
int dfs(int V)  // V: 접점
{
	if (V > N) {
		return 1;
	}
	int j;
	for (j = 1; j <= M; j++)
	{
		if (check(V, j) == 1) continue;
		SOL[V] = j;
		if (dfs(V + 1) == 1) return 1;
		SOL[V] = 0;
	}
	return 0;
}
int main(void)
{
	scanf("%d %d", &N, &M);
	int i, j, tmp;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			scanf("%d", &tmp);
			MAP[i][j] = MAP[j][i] = tmp;
		}
	}

	RET = dfs(1);
	if (RET)
	{
		for (i = 1; i <= N; i++)
		{
			printf("%d ", SOL[i]);
		}

	}
	else
	{
		printf("-1");
	}
	return 0;

}