#include <cstdio>
#include <intrin.h>
int t[10000], d[10000];
int n, h;

void calc(int p, int k) {
	if (d[p] == 0) t[p] = t[p << 1] + t[p << 1 | 1];
	else t[p] = d[p] * k;
}

void build(int l, int r) {
	int k = 2;
	for (l += n, r += n - 1; l > 1; k <<= 1) {
		l >>= 1, r >>= 1;
		for (int i = r; i >= l; --i) calc(i, k);
	}
}
void apply(int p, int value, int k) {
	t[p] = value * k;
	if (p < n) d[p] = value;
}
void push(int l, int r) {
	int s = h, k = 1 << (h - 1);
	for (l += n, r += n - 1; s > 0; --s, k >>= 1)
		for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
			apply(i << 1, d[i], k);
			apply(i << 1 | 1, d[i], k);
			d[i] = 0;
		}
}

void modify(int l, int r, int value) {
	if (value == 0) return;
	push(l, l + 1);
	push(r - 1, r);
	bool cl = false, cr = false;
	int k = 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
		if (cl) calc(l - 1, k);
		if (cr) calc(r, k);
		if (l & 1) apply(l++, value, k), cl = true;
		if (r & 1) apply(--r, value, k), cr = true;
	}
	for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
		if (cl) calc(l, k);
		if (cr && (!cl || l != r)) calc(r, k);
	}
}
int query(int l, int r) {
	push(l, l + 1);
	push(r - 1, r);
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

int main() {
	scanf("%d", &n);

	unsigned long tmp;
	_BitScanForward(&tmp, n);
	h = sizeof(int) * 8 - tmp;

	for (int i = 0; i < n; ++i)
		scanf("%d", &t[n + i]);
	build(0, n);
	modify(0, n, 10);
	printf("%d", query(0, n));
}