//https://latter2005.tistory.com/37
#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

vector <short> graph[501];
short match[501];
bool visit[501];
bool dfs(short i) {
	for (short next : graph[i]) {
		if (visit[next])continue;
		visit[next] = true;
		if (!match[next] || dfs(match[next])) {
			match[next] = i;
			return true;
		}
	}
	return false;
}
int main() {
	int n, k, res = 0;

	scanf("%d%d", &n, &k);
	for (short i = 0, s, e; i < k; i++) {
		scanf("%hd%hd", &s, &e);
		graph[s].push_back(e);
	}
	for (short i = 1; i <= n; i++) {
		memset(visit, 0, n+1);
		if (dfs(i))res++;
	}
	printf("%hd", res);
}
/*
5 4
2 1
2 3
4 1
4 5
*/