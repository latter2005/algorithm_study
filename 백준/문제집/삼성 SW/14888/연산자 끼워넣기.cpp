#include <cstdio>
int n, a=2147483647, b=a+1;
int v[11],o[4];
void d(int c, int t) {
	if (c >= n) {
		if (t < a) a = t;
		if (t > b) b = t;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (o[i]) {
			o[i]--;
			if(i==0)d(c + 1, t + v[c]);
			if (i == 1)d(c + 1, t - v[c]);
			if (i == 2)d(c + 1, t * v[c]);
			if (i == 3)d(c + 1, t / v[c]);
			o[i]++;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d",&v[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d",&o[i]);
	d(1, v[0]);
	printf("%d\n%d", b, a);
}
