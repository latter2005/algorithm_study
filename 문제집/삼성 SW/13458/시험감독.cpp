#include <stdio.h>
class fast_io {
public:
	int next_int() {
		int x = 0;
		bool neg = false;
		register int c;
		c = _getchar_nolock();
		if (c == '-'){
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
int b, c, n;
int a[1000001];
long long r;
fast_io fio;
int main() {
	n = fio.next_int();
	for (int i = 0; i < n; i++)
		a[i] = fio.next_int();
	b = fio.next_int();
	c = fio.next_int();
	for (int i = 0, t=a[i]-b; i < n; t=a[++i]-b) 
		r += (t>0) ? (t-1)/c + 2 : 1;
	printf("%lld", r);
}
//리눅스용은 getchar_unlock()
