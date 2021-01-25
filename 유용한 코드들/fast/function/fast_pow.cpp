#include <cstdio>

long long fast_power(long long base, long long power, long long mod) {
	long long result = 1;
	while (power > 0) {
		if (power % 2)  
			result = (result*base) % mod;
		base = (base * base) % mod;
		power >>= 1; 
	}
	return result;
}
int main() {
	printf("%d", fast_power(6, 3, 1000000007));
}