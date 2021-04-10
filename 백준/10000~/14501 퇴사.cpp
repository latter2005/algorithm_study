#include <cstdio>
int t[15],p[15],n,res;
void d(int cur, int val) {
	if (cur > n)return;
	if (val > res)res = val;
	if (cur == n)return;
	d(t[cur], val + p[cur]);
	d(cur + 1, val);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &t[i], &p[i]);
		t[i] += i;
	}
	d(0, 0);
	printf("%d", res);
}
