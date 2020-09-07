#include <cstdio>
#include<algorithm>
int n, ary[20][20], min=1e9;
int a[10], b[10];
bool v[20];
void calc() {
	int x=0, y=0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			x += ary[a[i]][a[j]];
			y += ary[b[i]][b[j]];
		}
	}
	if (min > abs(x - y))min = abs(x - y);
}
void dfs(int cnt, int cur) {
	if (cnt >= n / 2) {
		for (int i = 0, j = 0; i < n; i++)
			if (!v[i]) b[j++] = i;
		calc();
		return;
	}
	for (int i = cur + 1; i < cnt + 1 + n / 2; i++) {
		v[i] = true;
		a[cnt] = i;
		dfs(cnt + 1, i);
		v[i] = false;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0, j = 0; i < n; i++, j = 0)
		while (j < n) scanf("%d", &ary[i][j++]);
	v[0] = true;
	dfs(1, 0);
	printf("%d", min);
}
