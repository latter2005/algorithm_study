#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};

typedef struct point {
	int x, y, cost;
}point;
struct comp {
	bool operator()(point a, point b) { return a.cost > b.cost; }
};


int solution(vector<vector<int>> land, int height) {
	int answer = 0;
	int cnt = 0, N = land.size();
	int cx, cy;
	int visited[300][300] = { 0 };
	queue<pair<int, int>> que;
	priority_queue<point, vector<point>, comp> let;
	que.push({ 0, 0 });
	while (cnt < N*N) {
		if (que.empty()) {
			auto t = let.top();
			let.pop();
			cx = t.x; cy = t.y;
			if (visited[cx][cy])continue;
			answer += t.cost;
		}
		else {
			auto t = que.front();
			que.pop();
			cx = t.first; cy = t.second; 
			if (visited[cx][cy])continue;
		}
		cnt++;
		visited[cx][cy] = 1;
		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d], ny = cy + dy[d];
			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (visited[nx][ny]) continue;
				int cost = abs(land[cx][cy] - land[nx][ny]);
				if (cost <= height) {
					que.push({ nx, ny });
				}
				else {
					let.push(point{ nx, ny, cost });
				}
			}
		}
	}


	return answer;
}



int main() {
	vector<vector<int>> board = { {10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1} };


	cout << solution(board, 1);
}

/*
{{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}}
{{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}}
우선순위 큐 사용해서 사다리를 둘 자리 선정, 사다리 없이 갈 수 있는 위치는 일반 큐 사용
*/