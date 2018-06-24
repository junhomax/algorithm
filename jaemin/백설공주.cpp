#include <stdio.h>
int N, C;
int M;
int d[300000];
int d2[300001];
int color_idx[10001];
int color_cnt[10001];

int binary_find(int color, int t1, int t2) {
	t1--; t2--;
	int s = color_idx[color-1], e = color_idx[color]-1;
	int m = (s + e) / 2;
	int sol1 = -1 , sol2 = -1;
	if (t1 > d2[e] || t2 < d2[s]) return 0;
	while (s <= e) {
		m = (s + e) / 2;
		if (t1==d2[m]) {
			sol1 = m;
			break;
		}
		else if (t1 < d2[m]) {
			sol1 = m;
			e = m - 1;
		}
		else if(t1 > d2[m]){
			s = m + 1;
		}
	}
	if (color_idx[color] - sol1 <= (t2 - t1 + 1) / 2) return 0;
	s = color_idx[color - 1], e = color_idx[color] - 1;
	m = (s + e) / 2;
	while (s <= e) {
		m = (s + e) / 2;
		if (t2 == d2[m]) {
			sol2 = m;
			break;
		}
		else if (t2 < d2[m]) {
			e = m - 1;
		}
		else if (t2 > d2[m]) {
			sol2 = m;
			s = m + 1;
		}
	}
	if (sol2 - sol1 + 1 > (t2 - t1 + 1) / 2) return 1;
	return 0;
}
int find(int t1, int t2) {
	int find = 0;;
	for (int i = 1; i <= C; i++) {
		if (color_cnt[i] > (t2 - t1)/2 ) {
			if (binary_find(i, t1, t2) == 1) { find = i; break; }
		}
	}
	return find;
}
int main(void)
{
	int tmp1, tmp2;
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%d", &d[i]);
		color_cnt[d[i]]++;

	}
	color_idx[0] = 1; color_idx[1] = 1;
	for (int i = 2; i <= C; i++) {
		color_idx[i] = color_cnt[i - 1] + color_idx[i - 1];
	}
	for (int i = 0; i < N; i++) {
		d2[color_idx[d[i]]++] = i;
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		int res = find(tmp1, tmp2);
		if (res == 0) printf("no\n");
		else printf("yes %d\n", res);
	}

    return 0;
}

