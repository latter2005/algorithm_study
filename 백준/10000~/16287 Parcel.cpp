//https://latter2005.tistory.com/57
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int w, n, ary[5000];
	bool dp[400001] = { 0 };
	scanf("%d%d", &w, &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	sort(ary, ary + n);
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < i; j++)
			dp[ary[i] + ary[j]] = true;

		for (int j = i + 2; j < n; j++) {
			int t = w - ary[i + 1] - ary[j];
			if (t < 0)break;
			if (t <= 400000 && dp[t]) {
				printf("YES");
				return 0;
			}
		}

	}
	printf("NO");
}