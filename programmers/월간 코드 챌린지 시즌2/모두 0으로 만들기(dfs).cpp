#include <string>
#include <vector>
#include <stack>
using namespace std;
long long answer = 0;
vector<long long> cost;
vector<int> gph[300000];
void dfs(int cur, int prev) {
	for (int next : gph[cur]) {
		if (next != prev) {
			dfs(next, cur);
			answer += cost[next] > 0 ? cost[next] : -cost[next];
			cost[cur] += cost[next];
		}
	}
}
long long solution(vector<int> a, vector<vector<int>> edges) {

	cost.assign(a.begin(), a.end());

	for (auto &i : edges) {
		gph[i[0]].push_back(i[1]);
		gph[i[1]].push_back(i[0]);
	}

	dfs(0, -1);
	if (cost[0])return-1;
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