#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, k;
	cin >> k >> n;
	vector<string> ary(n);
	string mx;
	for (int i = 0; i < k; i++) {
		cin >> ary[i];
		mx = mx.size() < ary[i].size() || (mx.size() == ary[i].size() && mx < ary[i]) ? ary[i] : mx;
	}
	for (int i = k; i < n; i++)
		ary[i] = mx;

	sort(ary.begin(), ary.end(), [](string &a, string &b)->bool {
		return a + b > b + a;
	});

	for (int i = 0; i < n; i++)
		cout << ary[i];

}
