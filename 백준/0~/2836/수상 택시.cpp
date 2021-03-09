#include <iostream>
#include <algorithm>
using namespace std;
typedef struct pir {
	int cur, dest;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	pir ary[300000];
	cin >> n >> m;

	for (int i = 0; i < n;) {
		cin >> ary[i].cur >> ary[i].dest;
		if (ary[i].cur > ary[i].dest)i++;
		else n--;
	}

	sort(ary, ary + n, [](const pir &a, const pir& b)->bool {
		return a.dest < b.dest;
	});

	long long res = 0;
	int left = ary[0].dest, right = ary[0].cur;
	for (int i = 1; i < n; i++) {
		if (ary[i].dest < right) {
			right = right < ary[i].cur ? ary[i].cur : right;
		}
		else {
			res += right - left;
			left = ary[i].dest, right = ary[i].cur;
		}
	}
	res += right - left;
	cout << (res<<1) + m;
}

/*
3 15
10 2
13 12
5 3

*/