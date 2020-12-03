#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	long long dp[10000], k_1 = 0, k_2 = 0;
	scanf("%d\n%lld", &n, &dp[1]);
	dp[0] = 0;
	for (int t, i = 1; i < n; i++) {
		scanf("%d", &t);
		long long tmp = -9223372036854775807;
		
		for (int j = i; j >= 1; j--) {
			tmp = dp[j] > tmp ? dp[j] : tmp;
			dp[j + 1] = dp[j] + (j + 1) * t;
		}

		dp[0] = k_1 > k_2 ? k_1 : k_2;
		dp[1] = dp[0] + t;

		k_2 = k_1;
		k_1 = tmp;

		
	}
	long long m = max(k_1, k_2);
	for (int i = 1; i <= n; i++)
		m = dp[i] > m ? dp[i] : m;
	printf("%lld", m);

}
/*
7
-1 3 4 -7 -2 -2 1

7
-100000 5 -100000 5 -100000 5 -100000

8
-1 -1 -1 -1 100 100 -10000 100

11
-1 -1 -1 -100000000 -1 -1 -1 -1 -1 -1 10000

*/