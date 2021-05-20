#include <stdio.h>

int main() {
	int k, n;
	int ary[10000];
	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; i++)
		scanf("%d", &ary[i]);

	

	int left = 1, right = 0x7fffffff, mid, cnt;
	while (left < right) {
		mid = (right + left + 1U) / 2, cnt = 0;
		for (int i = 0; i < k && cnt < n; i++)
			cnt += ary[i] / mid;
		if (cnt < n)right = mid - 1;
		else left = mid;
	}
	printf("%d", left);
}