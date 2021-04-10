#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	queue<int> bfs;
	vector<int> graph[32001];
	int indegree[32001] = { 0 };
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (!indegree[i])
			bfs.push(i);

	while (!bfs.empty()) {
		int cur = bfs.front();
		bfs.pop();
		cout << cur << ' ';
		for (int next : graph[cur])
			if (!(--indegree[next]))
				bfs.push(next);
	}

}