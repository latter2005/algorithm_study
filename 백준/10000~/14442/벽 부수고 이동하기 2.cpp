#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef struct node {
	int x, y, k;
	node(int x, int y, int k) :x(x), y(y), k(k) {};

}node;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char ary[1002][1003] = { 0 };
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> (ary[i] + 1);


	int visited[1001][1001];
	memset(visited, 0x7f, sizeof visited);
	visited[1][1] = 0;

	int dx[] = { 0, 1, 0, -1 },
		dy[] = { 1, 0, -1, 0 }, depth = 1;
	queue<node> que;
	que.emplace(1, 1, 0);

	while (!que.empty()) {

		int cur_size = que.size();
		while (cur_size--) {
			auto cur = que.front();
			que.pop();

			if (cur.x == n && cur.y == m) {
				cout << depth;
				return 0;
			}
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d], ny = cur.y + dy[d];
				if (!ary[nx][ny]) continue;
				if (cur.k < visited[nx][ny]) {
					if (ary[nx][ny] != '1') {
						visited[nx][ny] = cur.k;
						que.emplace(nx, ny, cur.k);
					}
					else if (cur.k < k) {
						visited[nx][ny] = cur.k + 1;
						que.emplace(nx, ny, cur.k + 1);
					}
				}
			}
		}

		depth++;
	}
	cout << -1;
}