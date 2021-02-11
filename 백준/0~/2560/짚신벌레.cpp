#include <cstdio>
int main() {
	int ary[10001] = { 1 }, adult = 0;
	int a, b, d, n, front = 0, end;
	scanf("%d%d%d%d", &a, &b, &d, &n);
	if (a > n) {
		printf("1");
		return 0;
	}
	end = d;
	while (n--) {
		a = a != 0 ? a - 1 : end;
		b = b != 0 ? b - 1 : end;
		d = d != 0 ? d - 1 : end;
		front = front != 0 ? front - 1 : end;
		adult = (adult + ary[a] - ary[b] + 1000) % 1000;
		ary[front] = adult;
		ary[d] = 0;
	}
	a = 0;
	for (int i = 0; i <= end; i++)
		a += ary[i];
	printf("%d", a % 1000);
}