#include <stdio.h>
char dx[] = { 0,0,0,-1,1 },
	dy[] = { 0,1,-1,0,0 },
	dice[7] = { '0','0','0','0','0','0','0' }, cur[5] = { 1,3,4,2,5 }, c = 6;
int map[22][22];
int main() {
	char n, m, x, y;
	int k;
	scanf("%hhd%hhd%hhd%hhd%d", &n, &m, &x, &y, &k);
	getchar();
	for (char i = 1, j = 1; i <= n; i++, j=1)
		while (j <= m) {
			map[i][j++] = getchar();
			getchar();
		}
	x++; y++;
	for (int i = 0, d; i < k; i++) {
		d = getchar() - '0';
		getchar();
		char nx = x + dx[d], ny = y + dy[d];
		if (map[nx][ny]==0) continue;
		else if(map[nx][ny]=='0') {
			map[nx][ny] = dice[cur[d]];
		}
		else {
			dice[cur[d]] = map[nx][ny];
			map[nx][ny] = '0';
		}
		x = nx;
		y = ny;
		char tmp = c, idx = (d % 2) ? d + 1 : d - 1;
		c = cur[d];
		cur[d] = cur[0];
		cur[0] = cur[idx];
		cur[idx] = tmp;
		putchar(dice[cur[0]]);
		putchar('\n');
	}
}
