#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 987654321

int N;
int dp[10][10][10][104];
int in[101], out[101];

int change(int x) { // 자물쇠 회전. 음수로 회전은 9.8.7.6...으로 작아지도록 설정
	if (x < 0) 
		return (10 - ((-x) % 10)) % 10;
	else 
		return x % 10;
}

int solve(int a, int b, int c, int num) {
	if (num == N) return 0;

//	int &ret = dp[a][b][c][num];
	if (dp[a][b][c][num] != -1) 
		return dp[a][b][c][num];
	dp[a][b][c][num] = INF;


	if (change(in[num] + a) == out[num]) // 보고있는 3개의 자물쇠중 왼쪽부터 확인 맞으면 다음칸으로 당기면서 이동
		dp[a][b][c][num] = solve(b, c, 0, num + 1);
													 

	for (int n = -3; n <= 3; n++) { // +- 3칸 회전
		if (n == 0) continue;
		int na = change(a + n);
		int nb = change(b + n);
		int nc = change(c + n);
		dp[a][b][c][num] = min(dp[a][b][c][num], solve(na, b, c, num) + 1); // 디스크1개
		dp[a][b][c][num] = min(dp[a][b][c][num], solve(na, nb, c, num) + 1); // 디스크2개
		dp[a][b][c][num] = min(dp[a][b][c][num], solve(na, nb, nc, num) + 1); // 디스크3개 를 회전하는 경우중 최소인것
	}
	return dp[a][b][c][num];
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &N);
	for (int n = 0; n < N; n++)
		scanf("%1d", &in[n]);
	for (int n = 0; n < N; n++)
		scanf("%1d", &out[n]);
	printf("%d\n", solve(0, 0, 0, 0));
	return 0;
}
