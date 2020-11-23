#include <cstdio>

int main() {
	int n, dp[1000][1000][3];
	scanf("%d\n%d", &n, &dp[0][1][0]);
	dp[0][1][1] = 0;
	for (int t, i = 1; i < n; i++) {
		int max = 0x7fffffff + 1;
		scanf("%d", &t);
		for (int j = 2; j <= i; j++) {
			dp[i][j][0] = dp[i - 1][j - 1][0] + j * t;
			max = max > dp[i - 1][j - 1][0] ? max : dp[i - 1][j - 1][0];
		}
		dp[i][1][2] = dp[i][1][1];
		dp[i][1][1] = max;
	}
}