#include <iostream>
using namespace std;
typedef struct node {
	int dest;
	int link;
};
node vtx[2000000 - 1];
int s_idx[1000001], res;
bool dfs(int cur, int prev) {
	bool is_adaptor = false;
	for (int i = s_idx[cur]; i;) {
		int dest = vtx[i].dest;
		if (dest != prev) {
			if (!dfs(dest, cur))
				is_adaptor = true;
		}
		i = vtx[i].link;
	}
	if (is_adaptor)
		res++;
	return is_adaptor;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0, cur = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		vtx[++cur] = { v, s_idx[u] };
		s_idx[u] = cur;

		vtx[++cur] = { u, s_idx[v] };
		s_idx[v] = cur;
	}
	dfs(1, 0);
	printf("%d", res);
}

