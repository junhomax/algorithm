#include <stdio.h>

int N;

/*
int count(int n)
{
	int cnt = 0;
	while (n != 0)
	{
		n = n & (n - 1);
		cnt++;
	}
	return cnt;
}

void solve()
{
	int sum = 0;

	for (int i = N; i > 0; i--)
	{
		sum += count(i);
	}
	printf("%d", sum);
}
*/
void solve()
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += __builtin_popcount(i);
	}
	printf("%d", sum);
}

int main()
{
	scanf("%d", &N);
	solve();
	

	return 0;
}
