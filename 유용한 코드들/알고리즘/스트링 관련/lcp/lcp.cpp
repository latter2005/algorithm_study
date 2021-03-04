//Suffix Array: O(NlogN), LCP: O(N)    made by plzrun.
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define CHARNUM 256
using namespace std;
vector<int> sfx, g, ng, cnt, orderToIdx;
vector<int> lcp, prevsfx, plcp;
////get Suffix Array O(NlogN) using counting sort.
vector<int> getsfx(const string &s) {
	const int n = s.size();
	int lim = max(n + 1, CHARNUM + 1);
	sfx.clear(); g.clear(); ng.clear(); orderToIdx.clear();
	sfx.resize(n), g.resize(n + 1), ng.resize(n + 1), orderToIdx.resize(n + 1, 0);

	for (int i = 0; i < n; i++) sfx[i] = i, g[i] = s[i];

	for (int t = 1; t < n; t <<= 1) {
		cnt.clear(); cnt.resize(lim, 0);
		for (int i = 0; i < n; i++) cnt[g[min(i + t, n)]]++;
		for (int i = 1; i < lim; i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) orderToIdx[--cnt[g[min(i + t, n)]]] = i;

		cnt.clear(); cnt.resize(lim, 0);
		for (int i = 0; i < n; i++) cnt[g[i]]++;
		for (int i = 1; i < lim; i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) sfx[--cnt[g[orderToIdx[i]]]] = orderToIdx[i];

		auto cmp = [&](int i, int j)->bool {
			if (g[i] == g[j]) return g[i + t] < g[j + t];
			else return g[i] < g[j];
		};

		ng[sfx[0]] = 1;
		for (int i = 1; i < n; i++) {
			if (cmp(sfx[i - 1], sfx[i])) ng[sfx[i]] = ng[sfx[i - 1]] + 1;
			else ng[sfx[i]] = ng[sfx[i - 1]];
		}
		g = ng;
	}

	//get LCP O(N)
	lcp.clear(); prevsfx.clear(); plcp.clear();
	lcp.resize(n); prevsfx.resize(n + 1); plcp.resize(n + 1);

	prevsfx[sfx[0]] = -1;
	for (int i = 1; i < n; i++) prevsfx[sfx[i]] = sfx[i - 1];
	for (int i = 0, common = 0; i < n; i++) {
		if (prevsfx[i] == -1) plcp[i] = 0;
		else {
			while (s[i + common] == s[prevsfx[i] + common]) common++;
			plcp[i] = common;
			common = max(common - 1, 0);
		}
	}
	for (int i = 0; i < n; i++) lcp[i] = plcp[sfx[i]];

	return sfx;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	vector<int> sfx = getsfx(s);

	printf("sfx: ");
	for (auto &p : sfx) printf("%d ", p);
	puts("");

	printf("lcp: ");
	for (auto &p : lcp) printf("%d ", p);
	puts("");

	return 0;
}


