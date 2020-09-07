#include <cstdio>
#include <limits.h>
char a[20], o[9];
int N, max = INT_MIN, n[10], e=0;
inline int clc(char o, int x, int y) {
	switch (o){
	case '+':return x + y;
	case '-':return x - y;
	case '*':return x*y;
	}
}
void dfs(int c, bool f) {
	if (c == N) {
		int val = n[0];
		for (int i = 0; i < e; i++) val = clc(o[i], val, n[i+1]);
		if (val > max)max = val;
		return;
	}
	if (f) { // 계산
		int t = n[e];
		n[e] = clc(a[c], n[e], a[c + 1] - '0');
		dfs(c + 2, false);
		n[e] = t;
	}
	//스텍추가 후 넘어감
	o[e] = a[c];
	n[++e] = a[c + 1] - '0';
	dfs(c + 2, true);
	e--;
}
int main() {
	scanf("%d%s", &N, a);
	n[0] = a[0]-48;
	dfs(1, true);
	printf("%d", max);
}
