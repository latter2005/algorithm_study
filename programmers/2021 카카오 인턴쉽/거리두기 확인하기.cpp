#include <string>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

typedef struct node {
	int x, y, val;
}node;


vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	int dx[] = { 0, 0, 1, -1 },
		dy[] = { 1, -1, 0, 0 };

	bool visited[5][5];

	for (auto t : places) {
		memset(visited, 0, sizeof visited);
		bool flag = 1;

		for (int i = 0; i < 5 && flag; i++) {
			for (int j = 0; j < 5 && flag; j++) {
				if (t[i][j] != 'P')continue;

				queue<node> que = {};
				que.push({ i, j, 2 });
				while (!que.empty() && flag) {
					auto cur = que.front();
					que.pop();
					visited[cur.x][cur.y] = 1;

					for (int d = 0; d < 4; d++) {
						node next = { cur.x + dx[d], cur.y + dy[d], cur.val - 1 };
						if (next.x < 0 || next.x >4 || next.y < 0 || next.y > 4 ||
							visited[next.x][next.y] || t[next.x][next.y] == 'X')continue;
						if (t[next.x][next.y] == 'P') {
							flag = 0;
							break;
						}
						if(next.val)
							que.push(next);
					}



				}
			}
		}

		answer.push_back(flag);
	}



	return answer;
}


int main() {
	solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
	{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
	{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
}
/*
	{{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, 
	{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, 
	{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}}
*/