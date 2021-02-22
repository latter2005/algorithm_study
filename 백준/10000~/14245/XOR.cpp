#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, m;
int ary[500001];

inline void update(int i, int val) {
	for (; i <= n; i += i & -i)
		ary[i] ^= val;
}
inline int query(int i) {
	int t = 0;
	for (; i; i -= i & -i)
		t ^= ary[i];
	return t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, t; i < n; i++) {
		cin >> t;
		update(i + 1, t);
		update(i + 2, t);
	}


	cin >> m;
	while (m--) {
		int op;
		cin >> op;
		if (op != 2) {
			int s, e, v;
			cin >> s >> e >> v;
			update(s + 1, v);
			update(e + 2, v);
		}
		else {
			int i;
			cin >> i;
			cout << query(i + 1) << '\n';
		}
	}
}