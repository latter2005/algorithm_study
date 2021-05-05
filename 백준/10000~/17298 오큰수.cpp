#include <cstdio>

int main() {
	int n;
	int ary[1000000], stk[1000000], ans[1000000], top = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	ans[n - 1] = -1;
	stk[0] = ary[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		while (top && ary[i] >= stk[top - 1])--top;
		ans[i] = top ? stk[top - 1] : -1;
		stk[top++] = ary[i];
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
}