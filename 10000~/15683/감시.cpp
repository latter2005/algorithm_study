#include <cstdio>
#include <vector>
typedef struct point { int l, x, y; 
point(int l, int x, int y) : l(l), x(x), y(y) {};
}point;
int n, m, z_cnt, res;
char ary[10][10], visited[10][10];
int dx[7] = {-1, 0, 1, 0, -1, 0, 1 },
	dy[7] = {0, 1, 0, -1, 0, 1, 0 };
std::vector <point> stack, s_5;
inline void check(int x, int y, int d, int* z) {
	x += dx[d]; y += dy[d];
	while (ary[x][y]) {
		if (ary[x][y] == '0') {
			if (visited[x][y])visited[x][y]++;
			else { visited[x][y]++; (*z)--; }
		}
		x += dx[d]; y += dy[d];
	}
}
inline void un_check(int x, int y, int d) {
	x += dx[d]; y += dy[d];
	while (ary[x][y]) {
		if (ary[x][y] == '0') {
			visited[x][y]--;
		}
		x += dx[d]; y += dy[d];
	}
}
void dfs(int c, int z) {
	if (c == stack.size()) {
		if (res > z)res = z;
		return;
	}
	point t = stack[c];
	if (t.l == 1) {
		for (int d = 0; d < 4; d++) {
			int nz = z;
			check(t.x, t.y, d , &nz);
			dfs(c + 1, nz);
			un_check(t.x, t.y, d);
		}
	}
	if (t.l == 2) {
		for (int d = 0; d < 2; d++) {
			int nz = z;
			check(t.x, t.y, d, &nz);
			check(t.x, t.y, d + 2, &nz);
			dfs(c + 1, nz);
			un_check(t.x, t.y, d);
			un_check(t.x, t.y, d + 2);
		}
	}
	else {
		for (int d = 0; d < 4; d++) {
			int nz = z;
			for(int i=0;i<t.l-1;i++)
				check(t.x, t.y, d+i, &nz);
			dfs(c + 1, nz);
			for (int i = 0; i < t.l - 1; i++)
				un_check(t.x, t.y, d + i);
		}
	}
}

int main() {
	scanf("%d%d\n", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char tmp; 
			scanf("%hhd", &tmp);
			tmp += '0';
			ary[i][j] = tmp;

			if (tmp == '0') z_cnt++;
			else if (tmp == '6')ary[i][j] = 0;
			else if (tmp == '5')s_5.push_back(point(0, i, j));
			else if (tmp != 0)
				stack.push_back(point((int)(tmp - '0'), i, j));
		}
	}res = z_cnt;
	for (auto i : s_5) {
		for (int d = 0, nx=i.x + dx[d], ny=i.y + dy[d]; d < 4; d++, nx = i.x + dx[d], ny = i.y + dy[d]) {
			while (ary[nx][ny]) {
				if (ary[nx][ny] == '0') {
					if (visited[nx][ny])visited[nx][ny]++;
					else { visited[nx][ny]++; z_cnt--; }
				}
				nx += dx[d]; ny += dy[d];
			}
		}
	}
	dfs(0, z_cnt);
	printf("%d", res);
	return 0;
}
