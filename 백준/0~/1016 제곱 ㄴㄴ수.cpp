#include <cstdio>
#include <bitset>
using namespace std;
int main() {
	long long a, b, i, j, t;
	bitset<1000001> ary;
	scanf("%lld%lld", &a, &b);
	int count = 0;
	for (i = (a + 3) / 4 * 4; i <= b; i += 4) {
		ary[i - a] = 1;
		count++;
	}
	for (i = 3, t; (t = i * i) <= b; i += 2) {
		for (j = (t + a - 1) / t * t; j <= b; j += t) {
			if (!ary[j - a]) {
				ary[j - a] = 1;
				count++;
			}
		}
	}
	printf("%d", b - a + 1 - count);
}
