#include <cstdio>
#include <algorithm>

using namespace std;
int n, m, ary[1001], w[1001] = { 0 }, wt, dp[1001][1001][2];
int solve(int left, int right, bool tag) {
	if (dp[left][right][tag])return dp[left][right][tag];
	else if (left==1 && right==n) return dp[left][right][tag] = 0;
	int val = 0x7fffffff, consume = wt - (w[right] - w[left - 1]);

	if (left>1)
		val = solve(left - 1, right, false) +
		consume * (tag ? ary[right] - ary[left - 1] : ary[left] - ary[left - 1]);
	if (right<n)
		val = min(val, solve(left, right + 1, true) +
			consume * (tag ? ary[right + 1] - ary[right] : ary[right + 1] - ary[left]));
	return dp[left][right][tag] = val;
}
int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &ary[i], &w[i]);
		w[i] += w[i - 1];
	}
	wt = w[n];

	printf("%d", solve(m,m, false));
}

/*
6 5
3 2
11 10
12 18
13 19
15 15
17 19
*/