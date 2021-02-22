#include <vector>
#include <queue>
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