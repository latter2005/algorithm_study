#include <cstdio>
#include <cstring>

int n, m, vc, zc, res;
int ary[10][10], v[10][2];
char dx[] = { 1, -1, 0, 0 },
	 dy[] = { 0, 0, 1, -1 };
void spr() {
	int c = zc + vc - 3;
	int tmp[10][10];
	int stack[100][2], top = vc-1;
	memcpy(tmp, ary, sizeof(ary));
	memcpy(stack, v, sizeof(int) * 2 * vc);
	while (top > -1 && c > res) {
		int x = stack[top][0], y = stack[top--][1];
		c--;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (tmp[nx][ny] == '0') {
				tmp[nx][ny] = '2';
				stack[++top][0] = nx;
				stack[top][1] = ny;
			}
		}
	}
	if (top==-1)
		res = c;
}
void mk(int x, int y, int cnt) {
	if (cnt > 2) {
		spr();
		return;
	}
	for (int i = x, j = y + 1; i <= n; i++, j = 1) {
		while (j <= m) {
			if (ary[i][j] == '0') {
				ary[i][j] = '1';
				mk(i, j, cnt + 1);
				ary[i][j] = '0';
			}
			j++;
		}
	}
}
int main() {
	scanf("%d%d\n", &n, &m);
	for (int i = 1,  j=1; i <= n; i++,j=1) {
		while (j <= m) {
			ary[i][j] = getchar();
			getchar();
			if (ary[i][j] == '0') zc++;
			else if (ary[i][j] == '2') { v[vc][0] = i; v[vc++][1] = j; }
			j++;
		}
	}
	mk(1, 0, 0);
	printf("%d", res);
}
