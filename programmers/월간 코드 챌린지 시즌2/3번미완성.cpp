

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct vertex {
	long long cost;
	vector<int> edge;
}vertex;
long long dp[300000];
long long answer = 0;
vertex vtx[300000];
int dfs(int idx, int prev, long long val) {
	vertex &cur = vtx[idx];
	dp[idx] += val;
	for (int next : cur.edge) {
		if (next == prev)continue;
		cur.cost += dfs(next, idx, val);
	}

	answer += llabs(cur.cost);
	return cur.cost;
}

long long solution(vector<int> a, vector<vector<int>> edges) {

	int n = a.size();

	for (int i = 0; i < n; i++)
		vtx[i].cost = a[i];
	for (auto &i : edges) {
		vtx[i[0]].edge.push_back(i[1]);
		vtx[i[1]].edge.push_back(i[0]);
	}
	dfs(0, -1, 0);
	bool t = true;

	if ()
		return -1;

	return answer;
}
int main() {
	vector<int> a = { 10, 5, -10, 0, -8, 3, 92, -40, -40, -12 };
	vector<vector<int>> e = { {0, 2},{0, 1},{2, 3},{3, 4},{3, 5}, {1, 6}, {2, 8}, {8, 9}, {7, 5} };
	solution(a, e);
}