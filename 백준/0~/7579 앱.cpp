//https://latter2005.tistory.com/55
#include <cstdio>
#define max(a,b) a>b ? a : b
int main() {
	int n, m, ans = 0x7fffffff;
	int mem[100], cost[100], dp[10001] = { 0 };
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &mem[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &cost[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 10000; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
			if (dp[j] >= m && j < ans)ans = j;
		}
	}
	printf("%d", ans);
}