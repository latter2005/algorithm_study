#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m, ary[1001], w[1001] = { 0 }, wt, dp[1001][1001][2] = { 0 };
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &ary[i], &w[i]);
		w[i] += w[i - 1];
	}
	wt = w[n];
	int right = n - 1;
	for (int left = 1; left <= m; ++left) {
		for (; right >= m; --right) {
			int x = 0x7fffffff, y = 0x7fffffff, consume = wt - (w[right] - w[left - 1]);
			if (left != 1) {
				x = min(x, dp[left - 1][right][0] + consume * (ary[left] - ary[left - 1]));
				y = min(y, dp[left - 1][right][0] + consume * (ary[right] - ary[left - 1]));
			}
			if (right != n) {
				x = min(x, dp[left][right + 1][1] + consume * (ary[right + 1] - ary[left]));
				y = min(y, dp[left][right + 1][1] + consume * (ary[right + 1] - ary[right]));
			}
			dp[left][right][0] = x;
			dp[left][right][1] = y;
		}
		right = n;
	}
	printf("%d", min(dp[m][m][0], dp[m][m][1]));
}
