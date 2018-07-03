#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 987654321

int N;
int dp[10][10][10][104];
int in[101], out[101];

int change(int x) { // �ڹ��� ȸ��. ������ ȸ���� 9.8.7.6...���� �۾������� ����
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


	if (change(in[num] + a) == out[num]) // �����ִ� 3���� �ڹ����� ���ʺ��� Ȯ�� ������ ����ĭ���� ���鼭 �̵�
		dp[a][b][c][num] = solve(b, c, 0, num + 1);
													 

	for (int n = -3; n <= 3; n++) { // +- 3ĭ ȸ��
		if (n == 0) continue;
		int na = change(a + n);
		int nb = change(b + n);
		int nc = change(c + n);
		dp[a][b][c][num] = min(dp[a][b][c][num], solve(na, b, c, num) + 1); // ��ũ1��
		dp[a][b][c][num] = min(dp[a][b][c][num], solve(na, nb, c, num) + 1); // ��ũ2��
		dp[a][b][c][num] = min(dp[a][b][c][num], solve(na, nb, nc, num) + 1); // ��ũ3�� �� ȸ���ϴ� ����� �ּ��ΰ�
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
