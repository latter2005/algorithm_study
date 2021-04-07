#include <cstdio>

int main() {
	int n, l, res = 0;
	scanf("%d%d", &n, &l);

	int ary[100][100], tary[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &ary[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tary[j][i] = ary[i][j];
	for (int i = 0; i < n; i++) {
		int cnt = 1, j = 1;
		for (; j < n; j++) {
			if (ary[i][j - 1] == ary[i][j])	++cnt;
			else if (ary[i][j - 1] + 1 == ary[i][j] && cnt >= l)	
				cnt = 1;
			else if (ary[i][j - 1] - 1 == ary[i][j] && cnt >= 0)	
				cnt = 1-l;
			else	break;
		}
		if (j == n && cnt>=0)
			res++;
	}
	for (int i = 0; i < n; i++) {
		int cnt = 1, j = 1;
		for (; j < n; j++) {
			if (tary[i][j - 1] == tary[i][j])	++cnt;
			else if (tary[i][j - 1] + 1 == tary[i][j] && cnt >= l)	
				cnt = 1;
			else if (tary[i][j - 1] - 1 == tary[i][j] && cnt >= 0)	
				cnt = 1-l;
			else	break;
		}
		if (j == n && cnt >= 0)
			res++;
	}
	printf("%d\n", res);
}
