#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n, max_val = 0x7fffffff + 1, res = 0x7fffffff + 1;
int ary[1000];



int main() {
	int combo = 1;
	int dp[1000][1000][3];//no 1, 2
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);

	for (int i = 0; i < n; i++) {
		
			combo++;
	}
	printf("%d", cur);
}
/*
4
3 4 -7 8
*/