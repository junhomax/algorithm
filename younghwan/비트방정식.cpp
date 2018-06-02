#include <stdio.h>

#define ULL unsigned long long int
#define MAXDIGIT 64
ULL X, K;
int binaryX[MAXDIGIT];
int binaryK[MAXDIGIT];
int sol[MAXDIGIT];

int makeBinary(ULL N, int(*binary)[MAXDIGIT])
{
	int i = 0;
	ULL num = N;
	for (i = 0;; i++)
	{
		(*binary)[i] = num % 2;
		num /= 2;
		if (num == 0) break;
	}
	return i;
}

ULL makeDecimal(int(*binary)[MAXDIGIT], int digits)
{
	ULL ret = 0;
	for (int i = 0, d = 1; i <= digits; i++, d *= 2)
	{
		ret += ((*binary)[i] * d);
	}
	return ret;
}

void solve()
{
	int digitX = makeBinary(X, &binaryX);
	int digitK = makeBinary(K, &binaryK);

	printf("%c\n", 'X');
	for (int i = 0; i <= digitX; i++)
	{
		printf("%d", binaryX[i]);
	}
	printf("\n\n");

	printf("%s\n", "K¹øÂ°");
	for (int i = 0; i <= digitK; i++)
	{
		printf("%d", binaryK[i]);
	}
	printf("\n\n");


	for (int i = 0, k = 0; i <= digitX + digitK + 1; i++)
	{
		if (binaryX[i]) continue;
		printf("%d", binaryK[k]);
		sol[i] = binaryK[k++];
	}
	printf("\n");

	printf("%c\n", 'sol');
	for (int i = 0; i <= digitX + digitK + 1; i++)
	{
		printf("%d", sol[i]);
	}
	printf("\n\n");




	printf("%llu\n", makeDecimal(&sol, digitX + digitK + 1));	
}

int main()
{
	scanf("%llu %llu", &X, &K);
	solve();
	return 0;
}