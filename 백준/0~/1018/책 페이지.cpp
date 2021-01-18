//https://latter2005.tistory.com/54
#include <cstdio>

int main(void) {
	int n, ary[10] = { 0 };
	scanf("%d", &n);
	for (int cur = n, expr = 1; cur; expr *= 10) {
		int idx = cur % 10, next = cur / 10;
		ary[0] += next * expr;
		for (int i = 1; i <= idx; i++)
			ary[i] += (next + 1)*expr;
		ary[idx] -= expr - (n%expr) - 1;
		for (int i = idx + 1; i < 10; i++)
			ary[i] += next * expr;

		cur = next;
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", ary[i]);
}