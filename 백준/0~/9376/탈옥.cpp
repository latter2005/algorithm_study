#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef struct point {
	int x, y;
	point(int x, int y) :x(x), y(y) {};
}point;

int main() {
	short a_cost[102][102], b_cost[102][102], s_cost[102][102];
	char ary[102][102];
	int dx[] = { 0, 0, 1, -1 },
		dy[] = { 1, -1, 0, 0 };
	queue<point> que[2];

	int n, h, w;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &h, &w);
		memset(ary, '.', w + 2);
		int ax = -1, ay, bx, by;
		for (int i = 1; i <= h; i++) {
			ary[i][0] = '.';
			scanf("%s", ary[i] + 1);
			for (int j = 1; j <= w; j++) {
				if (ary[i][j] == '$') {
					if (ax == -1)
						ax = i, ay = j;
					else
						bx = i, by = j;
				}
			}
			ary[i][w + 1] = '.';
		}
		memset(ary[h + 1], '.', w + 2);//초기화

		bool flag;//배열 뒤집기
		short depth = 0;//문 개수
		memset(a_cost, -1, sizeof a_cost);
		a_cost[ax][ay] = 0;//죄수 1
		que[flag = 0].emplace(ax, ay);
		while (!que[0].empty() || !que[1].empty()) {
			if (que[flag].empty())//더이상 문을 열지 않고 탐색할 수 있는 점이 없음
				depth++, flag = !flag;
			int x = que[flag].front().x, y = que[flag].front().y;
			que[flag].pop();
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || h + 1 < nx || ny < 0 || w + 1 < ny || ary[nx][ny] == '*') continue;//벽, 배열 밖
				if (a_cost[nx][ny] == -1) {
					a_cost[nx][ny] = depth;
					if (ary[nx][ny] == '#')
						que[!flag].emplace(nx, ny);//문을 열어야 탐색할 수 있는 위치 => depth ++
					else
						que[flag].emplace(nx, ny);//문을 열지 않고 탐색할 수 있는 위치 => depth 같음, 우선 탐색
				}
			}
		}

		depth = 0;
		memset(b_cost, -1, sizeof b_cost);
		b_cost[bx][by] = 0;//죄수 2
		que[flag = 0].emplace(bx, by);
		while (!que[0].empty() || !que[1].empty()) {
			if (que[flag].empty())
				depth++, flag = !flag;
			int x = que[flag].front().x, y = que[flag].front().y;
			que[flag].pop();
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || h + 1 < nx || ny < 0 || w + 1 < ny || ary[nx][ny] == '*') continue;
				if (b_cost[nx][ny] == -1) {
					b_cost[nx][ny] = depth;
					if (ary[nx][ny] == '#')
						que[!flag].emplace(nx, ny);
					else
						que[flag].emplace(nx, ny);
				}
			}
		}

		depth = 0;
		memset(s_cost, -1, sizeof s_cost);
		s_cost[0][0] = 0;//상근
		que[flag = 0].emplace(0, 0);
		while (!que[0].empty() || !que[1].empty()) {
			if (que[flag].empty())
				depth++, flag = !flag;
			int x = que[flag].front().x, y = que[flag].front().y;
			que[flag].pop();
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || h + 1 < nx || ny < 0 || w + 1 < ny || ary[nx][ny] == '*') continue;
				if (s_cost[nx][ny] == -1) {
					s_cost[nx][ny] = depth;
					if (ary[nx][ny] == '#')
						que[!flag].emplace(nx, ny);
					else
						que[flag].emplace(nx, ny);
				}
			}
		}

		int ans = a_cost[0][0] + b_cost[0][0] + s_cost[0][0];//가장자리 동일한 depth 이므로 한번만 검사
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) {
				if (s_cost[i][j] != -1) {
					ans = min(ans, (ary[i][j] == '#') + s_cost[i][j] + a_cost[i][j] + b_cost[i][j]);
				}
			}
		printf("%d\n", ans);
	}
}