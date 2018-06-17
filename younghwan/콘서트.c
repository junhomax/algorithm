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
int count;
int maxh;

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
			stack[sp++] = input;
		}
		else
		{
			int tmph = stack[sp].height;
			for (;;)
			{
				if (sp == EMPTY || stack[sp].height >= input.height) break;
				tmph = tmph > stack[sp].height ? tmph : stack[sp].height;
				sp--;
				if (stack[sp].height >= tmph) count++;
			}
			stack[++sp] = input;
			count++;
		}
	}
	
	printf("%d\n", count);

	return 0;
}
