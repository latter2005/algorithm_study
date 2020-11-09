#include <stdio.h>
int main() {
	int n, t;
	char ary[101] = "", dup = 0, max = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		ary[t]++;
	}
	for (int i = 2; i <= n; i++) {
		if (ary[max] < ary[i]) {
			max = i;
			dup = 0;
		}
		else if (ary[max] == ary[i])
			dup = 1;
	}
	printf((dup || !ary[max]) ? "skipped" : "%d", max);	
}