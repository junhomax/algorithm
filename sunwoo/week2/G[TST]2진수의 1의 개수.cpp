#include <stdio.h>

long long cnt = 0;
int n;

void count1(int *n)
{
	int temp = *n;
	while (*n > 0) {
		if ((*n % 2) == 1) ++cnt;
		*n /= 2;
	}
	*n = temp - 1;
}

int main()
{
	scanf("%d", &n);

	while (n>0) 
		count1(&n);

	printf("%d\n", cnt);
	return 0;
}
