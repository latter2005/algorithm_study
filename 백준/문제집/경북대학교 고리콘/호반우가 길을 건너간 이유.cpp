#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//#include <unistd.h>
//namespace io {
//	const signed IS = 1 << 22, OS = 1 << 20;
//	char I[IS + 1], *J = I, O[OS], *K = O;
//
//	inline void daer() { if (J >= I + IS - 64) { char*p = I; do*p++ = *J++; while (J != I + IS); p[read(0, p, I + IS - p)] = 0; J = I; } }
//	template<int N = 10, typename T = int> inline T getu() { daer(); T x = 0; int k = 0; do x = x * 10 + *J - '0'; while (*++J >= '0'&&++k < N); ++J; return x; }
//	template<int N = 10, typename T = int>inline  T geti() { daer(); bool e = *J == '-'; J += e; return(e ? -1 : 1)*getu<N, T>(); }
//	inline void flush() { write(1, O, K - O); K = O; }
//
//	template<int N = 10, typename T = int> inline void putu(T n) { char s[(N + 7) / 8 * 8], *p = s; int k = 0; do*p++ = n % 10 + 48; while ((n /= 10) && ++k < N); do*K++ = *--p; while (p != s); *K++ = 10; if (K >= O + OS - 64)flush(); }
//	template<int N = 10, typename T = int> inline void puti(T n) { if (n < 0)*K++ = '-', n = -n; putu<N, T>(n); }
//	struct f { f() { I[read(0, I, IS)] = 0; }~f() { flush(); } }flu;
//};
//using namespace io;
void print(int cross, int move_down, int move_right, int t) {
	printf("%d\n", ((cross + move_down + move_right) << 1) + t);
	for (int i = 0; i < cross; i += 2) {
		printf("%d %d\n%d %d\n", i, i, i + 1, i + 1);
		printf("%d %d\n%d %d\n", i, i, i + 1, i + 1);
	}
	int cx = cross - 1, cy = cross - 1;
	for (int i = cross; i < cross + move_down; i += 2) {
		printf("%d %d\n%d %d\n", i, cy, i + 1, cy);
		printf("%d %d\n%d %d\n", i, cy, i + 1, cy);
	}
	for (int i = cross; i < cross + move_right; i += 2) {
		printf("%d %d\n%d %d\n", cx, i, cx, i + 1);
		printf("%d %d\n%d %d\n", cx, i, cx, i + 1);
	}
}
int main() {
	int n, m;
	short ary[1000][1000], path[4001][2];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &ary[i][j]);
	int cross = (n < m ? n : m) & 0x7ffffffe;
	int cx = cross - 1, cy = cross - 1;
	int move_down = (n-1-cx) & 0x7ffffffe, move_right = (m - 1 - cy) & 0x7ffffffe;
	cx += move_down;
	cy += move_right;
	
	if (cx != n - 1 && cy != m-1) {
		print(cross, move_down, move_right, 4);
		printf("%d %d\n%d %d\n", cx, cy + 1, cx + 1, cy + 1);
		printf("%d %d\n%d %d\n", cx, cy + 1, cx + 1, cy + 1);
	}
	else if (cx != n - 1) {
		print(cross, move_down, move_right, 4);
		printf("%d %d\n%d %d\n", cx + 1, cy - 1, cx + 1, cy);
		printf("%d %d\n%d %d\n", cx + 1, cy - 1, cx + 1, cy);
	}
	else if (cy != m - 1) {
		print(cross, move_down, move_right, 4);
		printf("%d %d\n%d %d\n", cx - 1, cy + 1, cx, cy + 1);
		printf("%d %d\n%d %d\n", cx - 1, cy + 1, cx, cy + 1);
	}
	else {
		print(cross, move_down, move_right, 0);
	}
	
}

/*
2 7
0 0 0 0 0 0 0
0 0 0 0 0 0 0

3 3
0 0 0
0 0 0
0 0 0

4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
*/