#include<cstdio>
#define m(x,d)x=d!=1?(x+1)%8:(x+7)%8
#define f(x)x!=1?1:-1
char a[4][9]; 
int p[4][3] = { {0,2,6},{0,2,6},{0,2,6},{0,2,6} }, n, c, d, i, l, r;
int main() { 
	scanf("%s%s%s%s", a[0], a[1], a[2], a[3]); 
	scanf("%d", &n); 
	while (n--) { 
		scanf("%d%d", &c, &d); c--; 
		for (l = c - 1; l >= 0 && a[l][p[l][1]] != a[l + 1][p[l + 1][2]]; l--); 
		for (r = c + 1; r < 4 && a[r - 1][p[r - 1][1]] != a[r][p[r][2]]; r++); 
		for (int k = c, t = d; k > l; k--, t = f(t)) { 
			m(p[k][0], t); m(p[k][1], t); m(p[k][2], t); 
		}
		for (int k = c + 1, t = f(d); k < r; k++, t = f(t)) { 
			m(p[k][0], t); m(p[k][1], t); m(p[k][2], t); 
		} 
	}
	for (i = 0, n = 0, c = 1; i < 4; i++, c <<= 1)
		if (a[i][p[i][0]] == '1')n += c; 
	printf("%d", n); 
}
