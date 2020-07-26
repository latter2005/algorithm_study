#include <cstdio>
#include <cmath>
typedef struct point {
	int x, y;
}point;

int n, m, kfc_cnt, house_cnt, res = 0x7fffffff;
int dist[13][100], tmp[14];

void dfs(int cur, int count) {
	if (count == m) {
		int total = 0;
		for (int i = 0; i < house_cnt; i++) {
			int min = 0x7fffffff;
			for (int j = 0; j < m; j++) {
				if (dist[tmp[j]][i] < min) min = dist[tmp[j]][i];
			}
			total += min;
		}

		if (total < res) res = total;
		return;
	}
	else if (m - count > kfc_cnt - cur) return;
	tmp[count] = cur;
	dfs(cur + 1, count + 1);

	dfs(cur + 1, count);
}

int main() {
	point house[100], kfc[13];
	scanf("%d%d", &n, &m);
	for (int i = 0, j = 0, t; i < n; i++, j = 0)
		while (j < n) {
			scanf("%d", &t);
			if (t == 1) { house[house_cnt].x = i; house[house_cnt++].y = j; }
			else if (t == 2) { kfc[kfc_cnt].x = i; kfc[kfc_cnt++].y = j; }
			j++;
		}
	for (int i = 0; i < kfc_cnt; i++) {
		for (int j = 0; j < house_cnt; j++) {
			dist[i][j] = (int)(labs(kfc[i].x - house[j].x) + labs(kfc[i].y - house[j].y));
		}
	}
	dfs(0, 0);
	printf("%d", res);
}