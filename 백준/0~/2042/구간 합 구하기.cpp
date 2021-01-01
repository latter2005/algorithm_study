//https://latter2005.tistory.com/40
#include <cstdio>
using namespace std;

int main() {
	long long n, m, k;
	long long tree[2000002];
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &tree[n + i]);
	for (int i = n - 1; i > 0; i--)
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1) {
			b += n - 1;
			long long gap = c - tree[b];
			tree[b] = c;
			for (b >>= 1; b >= 1; b >>= 1) {
				tree[b] += gap;
			}
		}
		else {
			long long sum = 0;
			for (b += n - 1, c += n; b < c; b >>= 1, c >>= 1) {
				if (b & 1) sum += tree[b++];
				if (c & 1) sum += tree[--c];
			}
			printf("%lld\n", sum);
		}
	}
}
