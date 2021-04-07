#include <cstdio>
#include <cmath>

typedef struct pir {
	int x, y;
};
pir ary[20], total;
int n;
double mn;
void dfs(int cur, int idx, int x, int y) {
	if (cur) {
		for (int i = idx; i <= n - cur; i++)
			dfs(cur - 1, i + 1, x + ary[i].x, y + ary[i].y);
		return;
	}
	double t = sqrt(pow(total.x - (x << 1), 2) + pow(total.y - (y << 1), 2));
	if (t < mn)mn = t;

}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		total = {}; mn = 1e308;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &ary[i].x, &ary[i].y);
			total.x += ary[i].x;
			total.y += ary[i].y;
		}
		dfs((n >> 1) - 1, 1, ary[0].x, ary[0].y);
		printf("%.7lf\n", mn);
	}
}