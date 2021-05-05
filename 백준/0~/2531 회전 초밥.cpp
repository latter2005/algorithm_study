#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, d, k, c;
	short ary[33000];
	//scanf("%d%d%d%d", &n, &d, &k, &c);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
		//scanf("%d", &ary[i]);
		cin >> ary[i];
	for (int i = 0; i < k; i++)
		ary[n + i] = ary[i];

	short visited[3001] = { 0 }, count = 1;
	visited[c] = 1;
	for (int i = 0; i < k; i++) {
		if (!visited[ary[i]]++)
			count++;
	}

	int mx = count;
	for (int i = 1; i < n; i++) {
		if (!--visited[ary[i - 1]])
			count--;
		
		if (!visited[ary[i+k - 1]]++)
			count++;

		mx = mx < count ? count : mx;
	}
	cout << mx;
}