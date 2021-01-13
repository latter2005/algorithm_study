#include <cstdio>
#include <cstring>
#include <algorithm>

int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	int n, k;
	int ary[15] = { 0 }, size[15], octal[51];
	long long dp[1 << 15][101] = { 0 };
	char tmp[15][51];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp[i]);
	}
	scanf("%d", &k);
	octal[0] = 1 % k;
	for (int i = 1; i <= 50; i++)
		octal[i] = octal[i - 1] * 10 % k;

	for (int i = 0; i < n; i++) {
		size[i] = strlen(tmp[i]);
		for (int j = size[i] - 1, c = 1; j >= 0; --j, c *= 10) {
			ary[i] += ((tmp[i][j] - '0') * c) % k;
		}
		ary[i] %= k;
	}
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < n; l++) {
				if ((i & (1 << l)) == 0) {
					int next = j * octal[size[l]];
					next %= k;
					next += ary[l];
					next %= k;
					dp[i | (1 << l)][next] += dp[i][j];
				}
			}
		}
	}
	long long p = dp[(1 << n) - 1][0], q = 1;
	
	if (p) {
		for (int i = 2; i <= n; i++)q *= i;
		int t = gcd(p, q);
		p /= t;
		q /= t;
		printf("%lld/%lld", p, q);
	}
	else
		printf("0/1");


}

/*
5
5221
40
1
5
8
9
*/