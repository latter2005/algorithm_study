#include <iostream>
#include <vector>
#include <cmath>
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
std::vector <int> ary[100001];
int lazy[262144];
int l[100001], r[100001], tree[262144], cnt, n, m;
/*
9
0 1 2 2 1 5 5 5 6
1
3 0

*/
int update(int s, int e, int idx, int x, int y, int k) {
	if (lazy[idx] == 1) {
		tree[idx] = (e - s + 1);
		lazy[idx] = 0;
		if (s != e) lazy[idx * 2] = lazy[idx * 2 + 1] = 1;
	}
	if (lazy[idx] == 2) {
		tree[idx] = 0;
		lazy[idx] = 0;
		if (s != e) lazy[idx * 2] = lazy[idx * 2 + 1] = 2;
	}
	if (s > y || e < x) return tree[idx];
	if (s >= x && e <= y) {
		lazy[idx] = k;
		if (k == 1) tree[idx] = (e - s + 1);
		else tree[idx] = 0;
		return tree[idx];
	}
	int m = (s + e) >> 1;
	return tree[idx] = update(s, m, idx * 2, x, y, k) + update(m + 1, e, idx * 2 + 1, x, y, k);
}

int ret(int s, int e, int idx, int x, int y) {
	if (lazy[idx] == 1) {
		tree[idx] = (e - s + 1);
		lazy[idx] = 0;
		if (s != e) lazy[idx * 2] = lazy[idx * 2 + 1] = 1;
	}
	if (lazy[idx] == 2) {
		tree[idx] = 0;
		lazy[idx] = 0;
		if (s != e) lazy[idx * 2] = lazy[idx * 2 + 1] = 2;
	}
	if (s > y || e < x) return 0;
	if (s >= x && e <= y)return tree[idx];
	int m = (s + e) >> 1;
	return ret(s, m, idx * 2, x, y) + ret(m + 1, e, idx * 2 + 1, x, y);
}
int dfs(int n) {
	if (ary[n].empty()) return (++cnt);
	l[n] = dfs(ary[n][0]);
	for (int i = 1; i < ary[n].size(); i++)dfs(ary[n][i]);
	r[n] = cnt;
	cnt++;
	return l[n];
}
//void dfs(int cr) {
//	l[cr] = ++cnt;
//	for (auto& iter : ary[cr]) dfs(cr);
//	r[cr] = cnt;
//}
int main() {
	FASTIO
	std::cin >> n;
	for (int i = 1, t; i <= n; i++) {
		std::cin >> t;
		ary[t].push_back(i);
	}
	dfs(1);
	lazy[1] = 1;
	std::cin >> m;
	while (m--) {
		int q, i;
		std::cin >> q >> i;
		if (q == 1 || q == 2)update(1, cnt, 1, l[i], r[i], q);
		else {
			std::cout << ret(1, cnt, 1, l[i], r[i]) << '\n';
		}
	}
}
