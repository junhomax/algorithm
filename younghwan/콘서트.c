#include <stdio.h>

#define MAX 500002
int N;
typedef struct st
{
	int pos;
	int height;
}INFO;
INFO stack[MAX];
int sp;
#define EMPTY 0
unsigned long long count;
int maxh;

int factorial(int num)
{
	int ret = 0;
	for (int i = 1; i <= num; i++)
	{
		ret += i;
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		INFO input = { 0 };
		scanf("%d", &input.height);
		input.pos = i;

		if (sp == EMPTY)
		{
			stack[++sp] = input;
		}
		else
		{
			if (stack[sp].height < input.height)
			{
				while (sp != EMPTY && stack[sp].height < input.height)
				{
					count++;
					sp--;
				}

				stack[++sp] = input;
			}
			else if (stack[sp].height == input.height)
			{
				int ptr = sp;
				int cnt = 0;
				while (sp != EMPTY && stack[ptr].height == input.height)
				{
					cnt++;
					ptr--;
				}

				count += cnt;
				if (ptr != EMPTY) count++;

				stack[++sp] = input;
			}
			else if (stack[sp].height > input.height)
			{
				count++;
				stack[++sp] = input;
			}
		}
	}

	while (sp != EMPTY)
	{
		if (stack[sp].height < stack[sp - 1].height) count++;
		sp--;
	}

	
	printf("%d\n", count);

	return 0;
}
