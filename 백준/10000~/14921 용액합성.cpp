#include <cstdio>
#include <algorithm>
class fast_io {
public:
	int next_int() {
		int x = 0;
		bool neg = false;
		register int c;
		c = _getchar_nolock();
		if (c == '-') {
			neg = true;
			c = getchar();
		}
		for (; (c > 47 && c < 58); c = _getchar_nolock())
			x = (x << 1) + (x << 3) + c - 48;
		if (neg)
			x *= -1;
		return x;
	}
};
fast_io fio;
int ary[100000];
int main() {
	int min = 2147483647, c, s;
	int n = fio.next_int();
	for (int i = 0; i < n; i++) 
		ary[i] = fio.next_int();
	for (int i = 0, j=n-1;i<j;s<0?i++:j--) {
		s = ary[i] + ary[j];
		if (labs(s) < labs(min)) min = s;
	}
	printf("%d", min);
}
