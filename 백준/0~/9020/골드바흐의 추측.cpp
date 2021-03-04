#include <cstdio>
#include <string.h>
int main(){
	int n;
	char p[10001];
	memset(p, 1, 10001);
	p[1] = 0;
	for (int i = 2; i*i <= 10000; i++)
		if (p[i])
			for (int j = i * i; j <= 10000; j += i)
				p[j] = 0;
	scanf("%d", &n);
	for (; ~scanf("%d", &n);) {
		int x = n / 2, y = x;
		while (!p[x] || !p[y]) { x--; y++; }
		printf("%d %d\n", x, y);
	}	
}