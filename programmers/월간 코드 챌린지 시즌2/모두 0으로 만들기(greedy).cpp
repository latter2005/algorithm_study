#include <string>
#include <vector>
#include <queue>
using namespace std;


long long solution(vector<int> a, vector<vector<int>> edges) {
	long long answer = 0;

	int n = a.size();
	long long cost[300000];
	for (int i = 0; i < n; i++)
		cost[i] = a[i];

	vector<int> gph[300000];
	for (auto &i : edges) {
		gph[i[0]].push_back(i[1]);
		gph[i[1]].push_back(i[0]);
	}

	int inbound[300000];
	queue<int> que;
	for (int i = 0; i < n; i++) {
		inbound[i] = gph[i].size();
		if (gph[i].size() == 1)
			que.push(i);
	}
		
		
	bool visited[300000] = { 0 };
	int cur, next;
	while (!que.empty()) {
		cur = que.front();
		que.pop();
		visited[cur] = 1;

		for (int i = 0; i < gph[cur].size();i++) {
			if (visited[gph[cur][i]])continue;
			next = gph[cur][i];
			cost[next] += cost[cur];
			answer += cost[cur] > 0 ? cost[cur] : -cost[cur];
			if (--inbound[next] == 1)que.push(next);
		}
	}

	if (cost[cur])return -1;
	return answer;
}

int main() {
	vector<int> a = { -5,0,2,1,2 };
	vector<vector<int>> e = { {0,1},{3,4},{2,3},{0,3} };
	solution(a, e);
}

/*
{-5,0,2,1,2}	{{0,1},{3,4},{2,3},{0,3}}	9
{0,1,0}	{{0,1},{1,2}}
*/