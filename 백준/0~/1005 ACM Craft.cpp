#include <stdio.h>
#define max(a,b) (a>b?(a):(b))
typedef struct bding {
	int cost, in, e_len;
	int edge[1000];
}bding;

int main() {
	int t, n, k, s, d, w;

	bding ary[1001];

	scanf("%d", &t);

	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &ary[i].cost);
			ary[i].in = 0;
			ary[i].e_len = 0;
		}
			
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &s, &d);
			ary[s].edge[ary[s].e_len++] = d;
			ary[d].in++;
		}
		scanf("%d", &w);
		int stack[1000], top =-1;
		for (int i = 1; i <= n; i++)
			if (!ary[i].in)
				stack[++top] = i;

		int dp[1000] = { 0 };
		while (top != -1) {
			int cur = stack[top--];

			for (int i = 0; i < ary[cur].e_len; i++) {
				int next = ary[cur].edge[i];
				dp[next] = max(dp[next], dp[cur] + ary[cur].cost);
				if (!--ary[next].in && ary[next].e_len)
					stack[++top] = next;
			}

		}
		printf("%d\n", dp[w] + ary[w].cost);
	}

}