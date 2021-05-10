#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef struct node {
	int x, y, p_dir;
	unsigned cost;
	node(int x, int y, int p_dir, unsigned cost) :
		x(x), y(y), p_dir(p_dir), cost(cost) {};
}node;

int solution(vector<vector<int>> board) {
	int answer = 0;

	int n = board.size();

	queue<node> que;
	if(!board[0][1])
		que.push({ 0, 1, 0, 100});
	if (!board[1][0])
		que.push({ 1, 0, 2, 100 });

	unsigned visited[25][25];
	memset(visited, -1, sizeof visited);
	visited[0][0] = 0;

	int dx[] = { 0, 0, 1, -1 },
		dy[] = { 1, -1, 0, 0 };

	while (!que.empty()) {
		node cur = que.front();
		que.pop();
		if (cur.cost > visited[cur.x][cur.y] || cur.cost >= visited[n - 1][n - 1]) continue;
		visited[cur.x][cur.y] = cur.cost;

		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d], ny = cur.y + dy[d];

			if ((cur.p_dir^d) == 1 || nx < 0 || n <= nx || ny < 0 || n <= ny || board[nx][ny]) continue;
			if (cur.p_dir == d && cur.cost + 100 < visited[nx][ny]) //직진
				que.push({ nx, ny, d, cur.cost + 100 });
			else if(cur.cost + 600 < visited[nx][ny])
				que.push({ nx, ny, d, cur.cost + 600 });
		}
	}

	return visited[n-1][n-1];
}

int main() {
	vector<vector<int>> t = { {0, 0, 0},{0, 0, 0},{0, 0, 0} };
	solution(t);
}