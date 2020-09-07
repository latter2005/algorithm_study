#include <cstdio>

class fast_io {
public:
	int next_int() {
		int x = 0;
		bool neg = false;
		register int c;
		c = getchar_unlocked();
		if (c == '-') {
			neg = true;
			c = getchar();
		}
		for (; (c > 47 && c < 58); c = getchar_unlocked())
			x = (x << 1) + (x << 3) + c - 48;
		if (neg)
			x *= -1;
		return x;
	}
};
fast_io fio;
short dx[] = { 0,0,-1,1,0,0 },
	  dy[] = { 1,-1,0,0,1,-1 }; // 동서북남
short ary[502][502];
int res, max;
void dfs(int x, int y, int b, int cnt, int val) {
	if (cnt == 4){
		if(res < val)
			res = val;
		return;
	}
	if (res > (4 - cnt) * max + val)
		return;
	for (int i = 0; i < 4; i++) {
		if (b == i) continue;
		int nx = x + dx[i], ny = y + dy[i];
		if(ary[nx][ny]!=0)
			dfs(nx, ny, i ^ 1, cnt + 1, val + ary[nx][ny]);
	}
}
inline void ex(int x, int y) {
	if (res > 3 * max + ary[x][y]) return;
	int tmp;
	for (int i = 0; i < 4; i++) {
		tmp = ary[x][y] +  ary[dx[i] + x][dy[i] + y]+ ary[dx[i+1] + x][dy[i+1] + y]+ ary[dx[i+2] + x][dy[i+2] + y];
		if (tmp > res)
			res = tmp;
	}
}
int main() {
	int n = fio.next_int(), m = fio.next_int();
	for (int i = 1, j = 1; i <= n; i++, j = 1)
		while (j <= m) {
			ary[i][j] = fio.next_int();
			if (ary[i][j] > max) 
				max = ary[i][j];
			j++;
		}
	for (int i = 1, j = 1; i <= n; i++, j = 0)
		while (j <= m) {
			dfs(i, j, -1, 1, ary[i][j]);
			ex(i, j++);
		}
	printf("%d", res);

}
