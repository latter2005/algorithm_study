#include<iostream>
#include<vector>
#include<queue>
#define INF 0x7fffffff
#define MAX_SIZE 100
using namespace std;

int solution(vector<vector<int>> arr,int n, int start) {
	vector<pair<int, int>> graph[MAX_SIZE];
	int dist[MAX_SIZE];
	fill(dist, dist + MAX_SIZE, INF);
	for (auto &i : arr) {
		graph[i[0]].push_back({ i[1],i[2] });
		graph[i[1]].push_back({ i[0],i[2] });
	}
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	que.push({ start, 0 });
	dist[start] = 0;
	while (!que.empty()) {
		auto &t = que.top();
		int cur = t.first, cur_cost = t.second;
		que.pop();

		auto &cur_vtx = graph[cur];
		for (int i = 0; i < cur_vtx.size(); i++) {
			int next = cur_vtx[i].first, next_cost = cur_vtx[i].second;
			if (dist[next] > dist[cur] + next_cost) {
				dist[next] = dist[cur] + next_cost;
				que.push({ next, dist[next] });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", dist[i]);
	}
	return 0;
}

int main(){
	
	vector<vector<int>> arr = { {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}} };
	solution(arr, 6, 4);
	
}