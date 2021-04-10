#include <iostream>
#include <algorithm>
using namespace std;
int n, ary[500][500], dp[500][500];
int dx[] = { 0, 0, 1, -1 },
dy[] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	int &cur = dp[x][y];
	if (cur) return cur;

	for (int d = 0; d < 4; d++) {
		if (x + dx[d] < 0 || n <= x + dx[d] || y + dy[d] < 0 || n <= y + dy[d]) continue;
		if (ary[x][y] < ary[x + dx[d]][y + dy[d]])
			cur = max(cur, dfs(x + dx[d], y + dy[d]));
	}
	return ++cur;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> ary[i][j];
	int mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!dp[i][j])
				mx = max(mx, dfs(i, j));
	cout << mx;
}
