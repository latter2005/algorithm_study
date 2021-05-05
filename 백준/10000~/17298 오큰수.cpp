#include <cstdio>

int main() {
	int n;
	int ary[1000000], nge[1000000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	nge[n - 1] = -1;


	for (int i = n - 2; i >= 0; i--) {
		int idx = i + 1;
		while (idx != -1 && ary[idx] <= ary[i])
			idx = nge[idx];
		nge[i] = idx;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", nge[i] != -1 ? ary[nge[i]] : -1);
}