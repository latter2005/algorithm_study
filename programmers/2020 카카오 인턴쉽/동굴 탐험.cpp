#include <string>
#include <vector>

using namespace std;

vector<int> edge[200000];
bool visited[200000];
int hang[200000], ord[200000];

void dfs(int cur) {
	if (visited[cur])return;

	if (!visited[ord[cur]]) {
		hang[ord[cur]] = cur;
		return;
	}
	visited[cur] = 1;
	dfs(hang[cur]);
	for (int next : edge[cur])
		dfs(next);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

	for (auto &i : path) {
		edge[i[0]].push_back(i[1]);
		edge[i[1]].push_back(i[0]);
	}
	for (auto &i : order) 
		ord[i[1]] = i[0];

	if (ord[0])return false;

	visited[0] = 1;
	for (int next : edge[0])
		dfs(next);

	for (int i = 0; i < n; i++)
		if (!visited[i])
			return false;

	return true;
}