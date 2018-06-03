#if 01

#include <stdio.h>

long long x, y, k;
int main() {

	scanf("%lld%lld", &x, &k);

	for (int i = 0, j = 0; j < 32; i++, j++)  // 2ÀÇ 32½ÂÀº 40¾ï
	{
		while ((1ll << i) & x)
			i++;
		if ((1ll << j) & k)
			y += (1ll << i);
	}
	printf("%lld\n", y);
	return 0;
}
#endif