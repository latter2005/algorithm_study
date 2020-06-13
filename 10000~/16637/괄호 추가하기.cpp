#include <cstdio>
char a[20], o[9];
int N, m = -0x7FFFFFFF, n[10], e = 0;
inline int clc(char o, int x, int y) {
	switch (o) { case '+':return x + y; case '-':return x - y; case '*':return x * y; }
}
void dfs(int c) {
	if (c == N) {
		int v = n[0];
		for (int i = 0; i < e; i++) v = clc(o[i], v, n[i + 1]);
		if (v > m)m = v;
		return;
	}

	int t = n[e];
	n[e] = clc(a[c], n[e], a[c + 1] - 48);
	dfs(c + 2);
	n[e] = t;

	o[e] = a[c];
	n[++e] = a[c + 1] - 48;
	dfs(c + 2);
	e--;
}
int main() {
	scanf("%d%s", &N, a);
	n[0] = a[0] - 48;
	dfs(1);
	printf("%d", m);
}
