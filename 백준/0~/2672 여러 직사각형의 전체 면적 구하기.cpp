#include <cstdio>
#include <algorithm>
typedef struct rect {
	double x1, y1, x2, y2;
}rect;

int main() {
	int n;
	scanf("%d", &n);

	rect ary[30];
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf%lf%lf", &ary[i].x1, &ary[i].y1, &ary[i].x2, &ary[i].y2);
		ary[i].x2 += ary[i].x1;
		ary[i].y2 += ary[i].y1;
	}

	double x[60], y[60];
	for (int i = 0; i < n; i++) {
		x[i << 1] = ary[i].x1;
		y[i << 1] = ary[i].y1;
		x[i << 1 | 1] = ary[i].x2;
		y[i << 1 | 1] = ary[i].y2;
	}
	int size = n << 1;
	std::sort(x, x + size);
	std::sort(y, y + size);

	double res = 0;

	for(int i=1;i<size;i++)
		for(int j=1;j<size;j++)
			for (int cur = 0; cur < n; cur++) 
				if (ary[cur].x1 <= x[i - 1] && x[i] <= ary[cur].x2 &&
					ary[cur].y1 <= y[j - 1] && y[j] <= ary[cur].y2) {
					res += (x[i] - x[i - 1]) * (y[j] - y[j - 1]);
					break;
				}
	
	long long t = res * 1000;
	t = (t + 5) / 10;
	if (t % 100)printf("%lld.%lld", t / 100, t % 100);
	else printf("%lld", t / 100);
}