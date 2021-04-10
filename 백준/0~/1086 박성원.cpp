#include <cstdio>
#include <cstring>
#include <algorithm>

long long gcd(long long a, long long b) {
	long long r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	int n, k;
	char tmp[15][51];
	long long dp[1 << 15][101] = { 0 };
	int ary[15] = { 0 }, size[15], octal[51];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp[i]);
		size[i] = strlen(tmp[i]);
	}
	scanf("%d", &k);
	octal[0] = 1;
	for (int i = 1; i <= 50; i++)
		octal[i] = (octal[i - 1] * 10) % k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size[i]; j++) {
			ary[i] = ((tmp[i][j] - '0') + ary[i] * 10) % k;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) 
		for(int j=0;j<k;j++)
			for (int t = 0; t < n; t++) 
				if ((i&(1 << t)) == 0) 
					dp[i | (1 << t)][(j*octal[size[t]] + ary[t]) % k] += dp[i][j];
				

	long long p = dp[(1<<n)-1][0], q = 1;
	for (long long i = 2; i <= n; i++)q *= i;
	long long t = gcd(p, q);
	p /= t;
	q /= t;
	printf("%lld/%lld", p, q);
}
