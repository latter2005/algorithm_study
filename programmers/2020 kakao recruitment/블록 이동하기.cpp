#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct node{
	int ax, ay, bx, by, stat;
	node(int ax, int ay, int bx, int by, int s) :ax(ax), ay(ay), bx(bx), by(by), stat(s) {};
}node;

int solution(vector<vector<int>> board) {

	int n = board.size();

	bool visited[100][100][2] = { 0 };//0: - 가로, 1: | 세로
	queue<node> que;
	
	que.emplace( 0, 0, 0, 1, 0 );

	int depth = 0;
	while (!que.empty()) {
		int cur_size = que.size();//최단경로를 찾는 문제이므로 같은 depth를 한번에 처리
		while (cur_size--) {
			node cur = que.front();
			que.pop();
			if (cur.bx == n - 1 && cur.by == n - 1) return depth;//목적지 도달
			if (visited[cur.ax][cur.ay][cur.stat]) continue;
			visited[cur.ax][cur.ay][cur.stat] = 1;//방문 체크

			node next = { cur.ax, cur.ay + 1, cur.bx, cur.by + 1, cur.stat }; //오
			if (next.by < n && !visited[next.ax][next.ay][next.stat] && !board[next.ax][next.ay] && !board[next.bx][next.by]) {
				que.push(next);
				if (cur.stat) {//회전
					que.emplace( cur.ax, cur.ay, cur.ax, cur.ay + 1, 0 );
					que.emplace( cur.bx, cur.by, cur.bx, cur.by + 1, 0 );
				}
			}

			next = { cur.ax, cur.ay - 1, cur.bx, cur.by - 1, cur.stat }; //왼
			if (0 <= next.ay && !visited[next.ax][next.ay][next.stat] && !board[next.ax][next.ay] && !board[next.bx][next.by]) {
				que.push(next);
				if (cur.stat) {
					que.emplace( cur.ax, cur.ay - 1, cur.ax, cur.ay, 0 );
					que.emplace( cur.bx, cur.by - 1, cur.bx, cur.by, 0 );
				}
			}

			next = { cur.ax + 1, cur.ay, cur.bx + 1, cur.by, cur.stat }; //하
			if (next.bx < n && !visited[next.ax][next.ay][next.stat] && !board[next.ax][next.ay] && !board[next.bx][next.by]) {
				que.push(next);
				if (!cur.stat) {
					que.emplace( cur.ax, cur.ay, cur.ax + 1, cur.ay, 1 );
					que.emplace( cur.bx, cur.by, cur.bx + 1, cur.by, 1 );
				}
			}

			next = { cur.ax - 1, cur.ay, cur.bx - 1, cur.by, cur.stat }; //상
			if (0 <= next.ax && !visited[next.ax][next.ay][next.stat] && !board[next.ax][next.ay] && !board[next.bx][next.by]) {
				que.push(next);
				if (!cur.stat) {
					que.emplace( cur.ax - 1, cur.ay, cur.ax, cur.ay, 1 );
					que.emplace( cur.bx - 1, cur.by, cur.bx, cur.by, 1 );
				}
			}
		}

		depth++;
	}

	
}

int main() {
	vector<vector<int>> b = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} };
	cout << solution(b);
}

