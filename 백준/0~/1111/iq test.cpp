#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n > 2) {
		int x, y, z, a, b;
		scanf("%d%d%d", &x, &y, &z);
		a = y-x ? (z - y) / (y - x) : 0;
		b = y - x * a;
		if (y*a + b != z) { printf("B"); return 0; }
		for (int i = 3; i < n; i++) {
			y = z;
			scanf("%d", &z);
			if (y*a + b != z) { printf("B"); return 0; }
		}
		printf("%d", z*a + b);
	}
	else if (n == 2) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y)
			printf("%d", x);
		else
			printf("A");
	}
	else
		printf("A");
}

