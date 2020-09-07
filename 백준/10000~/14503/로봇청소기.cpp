#include <cstdio>
int n, m, x, y, cd, cnt;
char ary[50][50];
char dx[] = { -1, 0, 1, 0, -1, 0, 1 },
	 dy[] = { 0, 1, 0, -1, 0, 1, 0 };
int main() {
	scanf("%d%d%d%d%d\n", &n, &m, &x, &y, &cd);
	cd += 3;
	for (int i = 0, j = 0; i < n; i++, j = 0) {
		while (j < m) {
			ary[i][j++] = getchar();
			getchar();
		}
	}
	while (1) {
		if (ary[x][y] == '0') {
			ary[x][y] = 'v';
			cnt++;
		}
		int d=-1, nx, ny;
		while (++d < 4) {
			int nd = cd - d;
			nx = x + dx[nd];
			ny = y + dy[nd];
			if (ary[nx][ny] == '0') {
				x = nx;
				y = ny;
				cd = nd%4 + 3;
				break;
			}
		}
		if (d >= 4) {
			nx = x + dx[cd - 1];
			ny = y + dy[cd - 1];
			if (ary[nx][ny] == '1')
				break;
			x = nx; y = ny;
		}
	}
	printf("%d", cnt);
}
