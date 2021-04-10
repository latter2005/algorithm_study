#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	short dp[2][1001] = { 0 }, mx=0;
	char ary[1001] = { 0 };

	for (int i = 1, f = 0, nf = 1; i <= n; i++) {
		cin >> ary;
		for (int j = 1; j <= m; j++) {
			if (ary[j - 1] != '0') {
				dp[f][j] = min({ dp[nf][j], dp[nf][j - 1], dp[f][j - 1] }) + 1;
				if (dp[f][j] > mx)
					mx = dp[f][j];
			}
			else
				dp[f][j] = 0;
		}
		nf = !nf;
		f = !f;
	}
	cout << mx * mx;
}