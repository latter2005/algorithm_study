#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	int ary[500001], dist[500001];

	ary[0] = 0x7fffffff;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ary[i];

	
	for (int i = 2; i <= n; i++) {
		if (ary[i - 1] < ary[i]) {
			int t = i - 1;
			while (ary[t] < ary[i])
				t = dist[t];

			dist[i] = t;
		}
		else {
			dist[i] = i - 1;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
}

