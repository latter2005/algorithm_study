#include <cstdio>

long gcd(long a, long b) {
	long r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int gcd2(int a, int b)
{
	while (b) b ^= a ^= b ^= a %= b;
	return a;
}
int main() {
	printf("%d", gcd2(35, 49));
}