#include <cstdio>

#include <unistd.h>
namespace io {
	const signed IS = 1 << 14, OS = 1 << 20;
	char I[IS + 1], *J = I;
	//char O[OS], *K = O;

	inline void daer() { if (J >= I + IS - 64) { char*p = I; do*p++ = *J++; while (J != I + IS); p[read(0, p, I + IS - p)] = 0; J = I; } }
	template<int N = 10, typename T = int> inline T getu() { daer(); T x = 0; int k = 0; do x = x * 10 + *J - '0'; while (*++J >= '0'&&++k < N); ++J; return x; }
	template<int N = 10, typename T = int>inline  T geti() { daer(); bool e = *J == '-'; J += e; return(e ? -1 : 1)*getu<N, T>(); }
	/*inline void flush() { write(1, O, K - O); K = O; }
	template<int N = 10, typename T = int> inline void putu(T n) { char s[(N + 7) / 8 * 8], *p = s; int k = 0; do*p++ = n % 10 + 48; while ((n /= 10) && ++k < N); do*K++ = *--p; while (p != s); *K++ = 10; if (K >= O + OS - 64)flush(); }
	template<int N = 10, typename T = int> inline void puti(T n) { if (n < 0)*K++ = '-', n = -n; putu<N, T>(n); }*/
	struct f { f() { I[read(0, I, IS)] = 0; }~f() { /*flush();*/ } }flu;
};//출처 : https://cgiosy.github.io/posts/fast-io
using namespace io;
short dx[] = { 0,0,-1,1,0,0 },
dy[] = { 1,-1,0,0,1,-1 }; // 동서북남
short ary[502][502];
int res, max;
void dfs(int x, int y, int b, int cnt, int val) {
	if (cnt == 4) {
		if (res < val)
			res = val;
		return;
	}
	if (res > (4 - cnt) * max + val)
		return;
	for (int i = 0; i < 4; i++) {
		if (b == i) continue;
		int nx = x + dx[i], ny = y + dy[i];
		if (ary[nx][ny] != 0)
			dfs(nx, ny, i ^ 1, cnt + 1, val + ary[nx][ny]);
	}
}
inline void ex(int x, int y) {
	if (res > 3 * max + ary[x][y]) return;
	int tmp;
	for (int i = 0; i < 4; i++) {
		tmp = ary[x][y] + ary[dx[i] + x][dy[i] + y] + ary[dx[i + 1] + x][dy[i + 1] + y] + ary[dx[i + 2] + x][dy[i + 2] + y];
		if (tmp > res)
			res = tmp;
	}
}
int main() {
	int n = getu(), m = getu();
	for (int i = 1, j = 1; i <= n; i++, j = 1)
		while (j <= m) {
			ary[i][j] = getu();
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