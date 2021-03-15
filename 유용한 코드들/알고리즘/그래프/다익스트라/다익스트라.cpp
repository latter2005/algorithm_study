#include <vector>
#include <queue>
typedef struct edge {
	int dest, cost;
	bool operator<(const edge &t)const {
		return cost > t.cost;
	}
	edge(int d, int c) :dest(d), cost(c) {};
}edge;
void dijkstra(vector<edge> vtx[201], unsigned dist[], int start) {
	memset(dist, 0x7f, sizeof dist);
	dist[start] = 0;

	priority_queue <edge, vector<edge>> que;
	que.push({ s, 0 });
	
	while (!que.empty()) {
		int cur = que.top().dist, cost = que.top().cost;
		auto &cur_vtx = vtx[cur];
		que.pop();
		for (int i = 0; i < cur_vtx.size(); i++) {
			if (dist[cur_vtx[i].dist] > dist[cur] + cur_vtx[i].cost) {
				dist[cur_vtx[i].dist] = dist[cur] + cur_vtx[i].cost;
				que.push({cur_vtx[i].dist, dist[cur_vtx[i].dist]});
			}
		}
	}
}