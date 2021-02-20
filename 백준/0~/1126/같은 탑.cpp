#include <cstdio>
#include <cstring>
#include <algorithm>
#define mx(a,b)a>b?a:b
using namespace std;
int main() {
	int n;
	int ary[50], dp[2][500001];
	memset(dp, -1, sizeof dp);
	dp[0][0] = dp[1][0] = 0;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	sort(ary, ary + n);

	for (int i = 0, max_len = 0; i < n; i++) {
		for (int j = 0; j <= max_len; j++) {
			if (dp[0][j] == -1)continue;
			dp[1][j + ary[i]] = max(dp[1][j + ary[i]], dp[0][j] + ary[i]);//높은 블록에 쌓기
			if (j < ary[i]) //낮은 블록에 쌓기
				dp[1][ary[i] - j] = max(dp[1][ary[i] - j], dp[0][j] + ary[i] - j);
			
			else 
				dp[1][j - ary[i]] = max(dp[1][j - ary[i]], dp[0][j]);
		}
		max_len += ary[i];
		memcpy(dp[0], dp[1], 4 * (max_len + 1));
	}
	printf("%d", dp[0][0] > 0 ? dp[0][0] : -1);
}