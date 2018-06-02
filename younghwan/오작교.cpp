#include <stdio.h>

#define MAX 1500
#define CIRCULAR 200*200
int R, C;	//세로,가로
char tmp_map[MAX][MAX];
char map[MAX][MAX];
char chk[MAX][MAX];
typedef struct st
{
	int i, j;
	int deleted = 0;
}POS;
POS start;
POS end;
POS que[CIRCULAR];
POS Xque[1500*1500];
int Xwp = 0, Xrp = 0;
int x = 0;
int sol = 0;

void inputData()
{
	int i, j;
	int check = 0;
	POS ndata;
	scanf("%d %d", &R, &C);
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			scanf(" %c", &map[i][j]);
			tmp_map[i][j] = map[i][j];
			if (map[i][j] == 'X')
			{
				ndata.i = i; ndata.j = j;
				Xque[Xwp++] = ndata;
			}
			if (map[i][j] == 'L')
			{
				if (check)
				{
					end.i = i; end.j = j;
				}
				else
				{
					check = 1;
					chk[i][j] = 1;
					start.i = i; start.j = j;
				}
			}
		}
	}
}

int birdBridge()
{
	int di[4] = { -1, 0, 1, 0 };
	int dj[4] = { 0, 1, 0, -1 };
	POS ndata, tdata;

	Xrp = 0;
	int flag = 0;
	while (Xwp != Xrp)
	{
		tdata = Xque[Xrp++];
		if (tdata.deleted) continue;

		flag = 0;
		for (register int k = 0; k < 4; k++)
		{
			if (flag) break;
			ndata.i = tdata.i + di[k];
			ndata.j = tdata.j + dj[k];

			if (ndata.i < 0 || ndata.i >= R || ndata.j < 0 || ndata.j >= C) continue;
			if (map[ndata.i][ndata.j] != 'X')
			{
				tmp_map[tdata.i][tdata.j] = '.';
				tdata.deleted = 1;
				flag = 1;		
			}
		}
	}

	Xrp = 0;
	while (Xwp != Xrp)
	{
		tdata = Xque[Xrp++];
		
		if (map[tdata.i][tdata.j] != tmp_map[tdata.i][tdata.j])
		{
			map[tdata.i][tdata.j] = '.';
		}
	}

	return 1;
}

int solve()
{
	int di[4] = { -1, 0, 1, 0 };
	int dj[4] = { 0, 1, 0, -1 };
	POS ndata, tdata;
	int wp = 0, rp = 0;

	que[wp++] = start;

	for(;;)
	{
		// 길이 없으면 1분 뒤 까마귀와 까치의 길을 확인
		if (wp == rp)
		{
			sol += birdBridge();
			rp--;
			if (rp < 0) rp = CIRCULAR - 1;
		}

		// 일반적인 BFS로 견우나 직녀가 만나는 지 확인
		tdata = que[rp++];
		rp %= CIRCULAR;

		for (register int k = 0; k < 4; k++)
		{
			ndata.i = tdata.i + di[k];
			ndata.j = tdata.j + dj[k];

			if (ndata.i < 0 || ndata.i >= R || ndata.j < 0 || ndata.j >= C) continue;
			if (map[ndata.i][ndata.j] == 'X') continue;
			if (chk[ndata.i][ndata.j]) continue;
			if (ndata.i == end.i && ndata.j == end.j) return sol;

			chk[ndata.i][ndata.j] = 1;
			que[wp++] = ndata;
			wp %= CIRCULAR;
		}
	}
	return sol;
}

int main()
{
	inputData();
	printf("%d\n", solve());

	return 0;
}