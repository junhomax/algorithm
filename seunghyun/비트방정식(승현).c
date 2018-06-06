#include <stdio.h>

int main() {

	long long X = 0L;
	long long K = 0L;
	long long Y = 0L;

	int x1[100];
	int k1[100];

	scanf("%lld %lld", &X, &K);

	
	
	for (int i = 0; i < 100; i++)
	{
		x1[i] = 2;
		k1[i] = 2;
	}

	int index = 99;
	while (X != 1)
	{
		x1[index] = X % 2;
		
		index--;
		X /= 2;
	}
	x1[index] = X;
	
	index = 99;
	while (K != 1)
	{
		k1[index] = K % 2;
		
		index--;
		K /= 2;
	}
	k1[index] = K;

	index = 99;
	int temp = 99;
	
	while (k1[temp] != 2)
	{
		if (x1[index] == 1)
		{
			x1[index] = 0;
		}
		else
		{
			x1[index] = k1[temp];
			temp--;
		}
		
		long long val = 1;
		for (int i = 0; i < 99 - index; i++)
		{
			val *= 2;

		}

		Y = Y + (val * x1[index]);

		index--;
	}
	
	printf("%lld", Y);




	return 0;
}
