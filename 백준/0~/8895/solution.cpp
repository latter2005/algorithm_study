//https://latter2005.tistory.com/33
#include <cstdio>
int main() {
	long long dp[20][20][20]={1};
	for (int n = 1; n < 20; n++)
		for (int l = 0; l < 20; l++)
			for (int r = 0; r < 20; r++) {
				dp[n][l][r] = (n - 1)*dp[n - 1][l][r];//사이
				if (l)dp[n][l][r] += dp[n - 1][l - 1][r];//왼쪽 끝
				if (r)dp[n][l][r] += dp[n - 1][l][r - 1];//오른쪽 끝
			}
	int t,n,l,r;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &l, &r);
		printf("%lld\n", dp[n - 1][l - 1][r - 1]);
	}
}
