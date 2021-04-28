#include<iostream>
#include<vector>
#include<queue>
#define INF 0x7fffffff
#define MAX_SIZE 100
using namespace std;

vector<int> solution(vector<vector<int>> arr,int n, int start) {
	vector<pair<int, int>> graph[MAX_SIZE];
	vector<int> dist(n+1, INF);
	//fill(dist, dist + MAX_SIZE, INF);
	for (auto &i : arr) {
		graph[i[0]].push_back({ i[1],i[2] });
	}
	dist[start] = 0;
	//기존루프
	for (int i = 1; i < n; i++) {
		for (int from = 1; from <= n; from++) {
			for (auto &edge : graph[from]) {
				int to = edge.first;
				int cost = dist[from] + edge.second;
				if (dist[from] != INF && dist[to] > cost) {
					dist[to] = cost;
				}
			}
		}
	}
	//n번째 -> 음수사이클
	for (int from = 1; from <= n; from++) {
		for (auto &edge : graph[from]) {
			int to = edge.first;
			int cost = dist[from] + edge.second;

			if (dist[from] != INF && dist[to] > cost) {
				dist.clear();
				return dist;
			}
		}
	}
	for (auto &i : dist)
		printf("%d\n", i);
	return dist;
}

int main(){
	
	vector<vector<int>> arr = { {{1, 2, 15}, {1, 3, 10}, {2, 4, 7}, {2, 5, 4}, {3, 5, 3}, {4, 3, -2}, {4, 6, -4}, {5, 4, 3}, {5, 6, 1}} };
	solution(arr, 6, 1);
	
}