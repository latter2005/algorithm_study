#include <cstdio>
int n, l, r;
char a[100][100];
void s(char *v) {
	for (int i = 0, next = 1, cnt = 1; next < n; i++, next++) {
		if (v[i] == v[next])cnt++;
		else if (v[i] + 1 == v[next]) {
			if (cnt < l) return;
			cnt = 1;
		}
		else if (v[i] == v[next] + 1) {
			for (; next <= i+l ; next++) {
				if (next >= n)return;
				if (v[i] != v[next] + 1)return;
			}
			next--;
			i = next - 1;
			cnt = 0;
		}
		else return;
	}
	r++;
}
int main() {
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++) {
		char t[100];
		for (int j = 0; j < n; j++) {
			scanf("%hhd", &t[j]);
			a[j][i] = t[j];
			getchar();
		}
		s(t);
	}
	for (int i = 0; i < n; i++)
		s(a[i]);
	printf("%d", r);
}
