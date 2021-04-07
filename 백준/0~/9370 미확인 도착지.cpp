#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef struct edge {
	int dest, cost;
	bool operator<(const edge &t)const {
		return cost > t.cost;
	}
	edge(int d, int c) :dest(d), cost(c) {};
}edge;

void solve() {
	int n, m, t;
	cin >> n >> m >> t;

	int s, g, h;
	cin >> s >> g >> h;

	vector<edge> vtx[2001];
	int a, b, d;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		d <<= 1;//비용 2배
		vtx[a].emplace_back(b, d);
		vtx[b].emplace_back(a, d);
	}
	for (auto &t : vtx[g])
		if (t.dest == h) --t.cost;//g-h 간선 비용 --
	for (auto &t : vtx[h])
		if (t.dest == g) --t.cost;//h-g 간선 비용 --


	int cand[100];
	for (int i = 0; i < t; i++)
		cin >> cand[i];
	sort(cand, cand + t);

	priority_queue <edge, vector<edge>> que;

	bool check[2001] = { 0 };
	int dist[2001];
	memset(dist, 0x7f, sizeof dist);
	que.push({ s, 0 });
	dist[s] = 0;
	while (!que.empty()) {//다익스트라 알고리즘
		int cur = que.top().dest, cost = que.top().cost;
		auto &cur_vtx = vtx[cur];
		que.pop();
		for (int i = 0; i < cur_vtx.size(); i++) {
			if (dist[cur_vtx[i].dest] > dist[cur] + cur_vtx[i].cost) {

				dist[cur_vtx[i].dest] = dist[cur] + cur_vtx[i].cost;
				que.push({ cur_vtx[i].dest, dist[cur_vtx[i].dest] });


				check[cur_vtx[i].dest] = check[cur];//전 경로의 check 값 상속
				if ((cur == g && cur_vtx[i].dest == h) || (cur == h && cur_vtx[i].dest == g))
					check[cur_vtx[i].dest] = 1;//경로가 g-h 간선을 지나는 경우 체크
			}

		}
	}
	for (int i = 0; i < t; i++) {
		if (check[cand[i]])
			cout << cand[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
		cout << '\n';
	}
}
