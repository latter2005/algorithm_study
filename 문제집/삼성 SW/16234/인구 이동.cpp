#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef struct point {
	int x,y;
}point;
int dx[4] = {1, -1, 0, 0},
	dy[4] = {0, 0, 1, -1},
N, L, R, top, val, cnt, list_cnt;
int ary[52][52],visit[52][52];
point stack[2501],list[2501]; 
void dfs(int x, int y) {
	if (visit[x][y]) return;
	visit[x][y] = 1;
	stack[top++] = { x, y };
	val += ary[x][y];
	for (int d = 0; d < 4; d++) {

		int tx = dx[d] + x, ty = dy[d] + y, gap = abs(ary[tx][ty] - ary[x][y]);
		if (ary[tx][ty]!=-1 && !visit[tx][ty] && L <= gap && gap <= R) {
			dfs(tx, ty);
		}
	}
	if (top > 1 && x == stack[0].x && y == stack[0].y) {
		val /= top;
		for (int i = 0; i < top; i++) {
			ary[stack[i].x][stack[i].y] = val;
			list[list_cnt++] = { stack[i].x , stack[i].y };
		}
		cnt = 1;  	
	}
}
int main() {
	int tcnt = 0;
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 0; i <= N; i++)
		ary[0][i] = ary[i][0] = ary[N+1][i] = ary[i][N+1] = -1;
	for (int i = 1, j = 1; i <= N; i++, j = 1)
		while (j <= N)
			scanf("%d", &ary[i][j++]);
	for (int i = 1; i <= N; i++)
		for (int j = (i&1) + 1; j <= N; j+=2) {
			dfs(i, j);
			top = 0; val = 0;
		}
	point tmp_list[2501];
	if (cnt) {
		for (tcnt++; cnt; tcnt++) {
			memset(visit, 0, sizeof(visit));
			cnt = 0;
			int tmp = list_cnt;
			memcpy(tmp_list, list, sizeof(point) * list_cnt);
			list_cnt = 0;
			for (int i = 0; i < tmp; i++) {
				dfs(tmp_list[i].x, tmp_list[i].y);
				top = 0; val = 0;
			}
		}
	}
	printf("%d", tcnt>0?tcnt-1:0);
}