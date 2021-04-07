#include <cstdio>

int main() {
	long long n;
	scanf("%lld", &n);
	if (n % 7 == 0 || n % 7 == 2)
		printf("CY");
	else
		printf("SK");
}