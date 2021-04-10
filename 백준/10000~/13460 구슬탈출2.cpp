#include <iostream>
#include <queue>
#include <string>

typedef struct pos {
	int y, x;
}pos;
pos start[2]; //0 blue 1 red
char map[10][11];
bool visited[10][10][10][10];
int n, m;
std::queue<pos*>que;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int solve() {
	int count = 0;
	bool f = 0;
	que.push(start);
	while (que.size() && count < 11) {
		int q_size = que.size();
		while (q_size--) {
			pos *ptr = que.front();
			pos b_now = { ptr[0].y, ptr[0].x }, r_now = { ptr[1].y, ptr[1].x };
			
			que.pop();
			if (map[r_now.y][r_now.x] == 'O') { f = 1; break; }
			for (int d = 0; d < 4; d++) {
				int t[2] = {};
				bool out[2] = { 0, 0 };
				pos tmp[2] = { {b_now.y, b_now.x}, {r_now.y, r_now.x} };
				for (int i = 0; i < 2; i++) 
					while (map[tmp[i].y + dy[d]][tmp[i].x + dx[d]] != '#') {
						t[i]++;
						tmp[i].y += dy[d];
						tmp[i].x += dx[d];
						if (map[tmp[i].y][tmp[i].x] == 'O') {
							out[i] = 1;
							break;
						}
					}
				if (out[0]) continue;
				if (tmp[0].y == tmp[1].y &&tmp[0].x == tmp[1].x) {
					if (t[0] > t[1]) tmp[0].y -= dy[d], tmp[0].x -= dx[d];
					else tmp[1].y -= dy[d], tmp[1].x -= dx[d];
				}

				if (visited[tmp[0].y][tmp[0].x][tmp[1].y][tmp[1].x]) continue;
				visited[tmp[0].y][tmp[0].x][tmp[1].y][tmp[1].x] = 1;
				pos *que_tmp = new pos[2];
				que_tmp[0].y = tmp[0].y; que_tmp[0].x = tmp[0].x; que_tmp[1].y = tmp[1].y; que_tmp[1].x = tmp[1].x;
				que.push(que_tmp);
				
			}
		}


		if (f)
			return count;
		
		count++;
		
	}
	return -1;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s",map[i]);
		for (int j = 0; j < m; j++) {
			switch (map[i][j]){
			case 'B': start[0].y = i; start[0].x = j; break;
			case 'R': start[1].y = i; start[1].x = j;
			}
		}
	}
	visited[start[0].y][start[0].x][start[1].y][start[1].x] = 1;
	std::cout << solve();
}
