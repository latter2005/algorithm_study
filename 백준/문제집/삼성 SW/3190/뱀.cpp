#include <stdio.h>

int main() {
	int n, k;
	char map[102][102] = {};
	scanf("%d%d", &n, &k);
	while (k--) {
		int x, y;
		scanf("%d%d", &x, &y);
		map[x][y] = 3;
	}

	for (int i = 0; i <= n + 1; i++)
		map[0][i] = map[i][0] = map[n + 1][i] = map[i][n + 1] = 2;

	int l, cnt=0;
	int dx =  0, dy = 1;
	short rq[101][2] = { {1, 1}, }, h = 0, t = 0;
	map[1][1] = 1;
	scanf("%d", &l);
	l++;
	while (l--) {
		int X;
		char C;
		if(l>0)
			scanf("%d %c", &X, &C);
		else X = 101;
		while (cnt < X) {
			int hx = rq[h][0], hy = rq[h][1];
			cnt++;
			hx += dx;
			hy += dy;
			if (map[hx][hy] == 3) {
				map[hx][hy] = 1;
				if (h > 100) h = 0;
				else h++;
				rq[h][0] = hx;
				rq[h][1] = hy;
			}
			else if (map[hx][hy] == 1 || map[hx][hy] == 2) {
				X = -1;
				break;
			}
			else {
				int tx = rq[t][0], ty = rq[t][1];
				map[tx][ty] = 0;
				map[hx][hy] = 1;
				if (h > 100) h = 0;
				else h++;
				rq[h][0] = hx;
				rq[h][1] = hy;
				if (t > 100) t = 0;
				else t++;
			}
		}
		if (X == -1)
			break;
		if (C == 'L'){
			int tmp = dx;
			dx = -dy;
			dy = tmp;
		}
		else{
			int tmp = dx;
			dx = dy;
			dy = -tmp;
		}

	}
	printf("%d", cnt);
}
