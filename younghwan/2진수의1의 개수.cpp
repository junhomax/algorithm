#include <stdio.h>

int binary[56];
long long int N;

int makeBinary(long long int N)
{
	int i = 0;
	int num = N;
	for (i = 0;; i++)
	{

		binary[i] = num % 2;
		num /= 2;
		if (num == 0) break;
	}
	return i;
}

int sqr(int n)
{
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		num *= 2;
	}
	return num;
}

int solve(int digits)
{
	int i, j, d, tmp, k;
	int sol = 0;
	int end = sqr(digits);
	for (i = 1; i <= end; i *= 2)
	{
		sol += (((N + 1) / 2) / i) * i;

		if (((N + 1) % i) && (((N + 1) / i) % 2))
		{
			sol += ((N + 1) % i);
		}
	}
	return sol;
}

int main()
{
	scanf("%lld", &N);
	printf("%d\n", solve(makeBinary(N)));

	return 0;
}