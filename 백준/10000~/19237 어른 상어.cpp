#include <cstdio>
#include <cstring>

typedef struct shark {
	int x, y, d;
	int priority[4][4];
}shark;
typedef struct node {
	int num, sk, cnt;
};
int main() {
	int n, m, k;
	shark sk[401];
	node map[20][20];
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j].num);
			if (map[i][j].num) {
				map[i][j].sk = map[i][j].num;
				map[i][j].cnt = k;
				sk[map[i][j].num] = { i, j };
			}
				
		}
	

	for (int i = 1; i <= m; i++)
		scanf("%d", &sk[i].d), sk[i].d--;

	for (int i = 1; i <= m; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++) {
				scanf("%d", &sk[i].priority[j][k]);
				--sk[i].priority[j][k];
			}
				
	int dx[4] = { -1,1,0,0 },
		dy[4] = { 0,0,-1,1 };
	int depth = 0, cnt = m - 1;
	while (depth < 1000) {
		depth++;

		for (int i = 1; i <= m; i++) {
			if (sk[i].x == -1) continue;

			map[sk[i].x][sk[i].y].num = 0;
			bool t = true;

			for (int d = 0; t && d < 4; d++) {//빈칸
				int nd = sk[i].priority[sk[i].d][d];
				int nx = sk[i].x + dx[nd], ny = sk[i].y + dy[nd];
				if (nx < 0 || ny < 0 || nx == n || ny == n || map[nx][ny].cnt >= depth) continue;

				t = false;
				if (map[nx][ny].num) {//겹치면 죽음
					sk[i].x = -1;
					cnt--;
				}
				else {
					sk[i].x = nx;
					sk[i].y = ny;
					sk[i].d = nd;
					map[nx][ny].num = i;
					map[nx][ny].sk = i;
				}

			}
			if (t) {//냄새
				for (int d = 0; d < 4; d++) {
					int nd = sk[i].priority[sk[i].d][d];
					int nx = sk[i].x + dx[nd], ny = sk[i].y + dy[nd];
					if (nx < 0 || ny < 0 || nx == n || ny == n || map[nx][ny].sk != i) continue;
					sk[i].x = nx;
					sk[i].y = ny;
					sk[i].d = nd;
					break;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			if (sk[i].x == -1) continue;
			map[sk[i].x][sk[i].y].cnt = depth + k;
		}

		if (!cnt) {
			printf("%d", depth);
			return 0;
		}
	}

	printf("-1");

}