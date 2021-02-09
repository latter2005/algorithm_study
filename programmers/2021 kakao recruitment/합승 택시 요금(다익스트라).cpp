#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef struct edge {
	int dist, cost;
	bool operator<(const edge &t)const {
		return dist < t.dist;
	}
	edge(int d, int c) :dist(d), cost(c) {};
}edge;
void dijkstra(vector<edge> vtx[201], unsigned dist[], int start) {
	priority_queue <edge, vector<edge>, less<edge>> que;
	que.emplace(start, 0);
	dist[start] = 0;
	while (!que.empty()) {
		int cur = que.top().dist, cost = que.top().cost;
		auto &cur_vtx = vtx[cur];
		que.pop();
		for (int i = 0; i < cur_vtx.size(); i++) {
			if (dist[cur_vtx[i].dist] > dist[cur] + cur_vtx[i].cost) {
				dist[cur_vtx[i].dist] = dist[cur] + cur_vtx[i].cost;
				que.emplace(cur_vtx[i].dist, dist[cur_vtx[i].dist]);
			}
		}
	}
}
int solution(int n, int start, int a, int b, vector<vector<int>> arr) {
	int res = 0x7fffffff;
	unsigned dist[3][201];
	memset(dist, -1, sizeof dist);
	vector<edge> vtx[201];
	for (auto &t : arr) {
		vtx[t[0]].emplace_back(t[1], t[2]);
		vtx[t[1]].emplace_back(t[0], t[2]);
	}
	dijkstra(vtx, dist[0], start);
	dijkstra(vtx, dist[1], a);
	dijkstra(vtx, dist[2], b);
	for (int i = 1; i <= n; i++) {
		if (dist[0][i] != -1) {
			int t = dist[0][i] + dist[1][i] + dist[2][i];
			res = res > t ? t : res;
		}
	}
		
	return res;
}

int main() {
	vector<vector<int>> arr = { {{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}} };

	printf("%d", solution(6, 4, 5, 6, arr));

}

