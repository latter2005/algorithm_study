#include <cstdio>
#include <vector>
using namespace std;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 },
dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<pair<int, int>> tree[10][10];//나이 개수
int ary[10][10], s2d2[10][10];
int N, M, K;
void spring_summer_winter() {
	//spring
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int total_add = s2d2[i][j];
			for (int t = tree[i][j].size() - 1; t >= 0; t--) {
				int level = tree[i][j][t].first;
				if (level * tree[i][j][t].second <= ary[i][j]) {//그 나이대 나무를 모두 살릴 수 있는 경우
					ary[i][j] -= level * tree[i][j][t].second;
					tree[i][j][t].first++;
				}
				else {//일부 혹은 전부 죽는 경우
					int e = t + 1;
					int alive = ary[i][j] / level, dead = tree[i][j][t].second - alive;
					if (alive) {
						ary[i][j] -= alive * level;
						tree[i][j][t].first++;
						tree[i][j][t].second = alive;
						e--;//아직 살아있는 나무가 있기 때문에 삭제할 벡터 위치를 당김
					}
					//summer
					total_add += dead * (level >> 1); //죽은 나무 양분으로 변경
					for (t--; t >= 0; t--)//뒤에 나이가 더 많은 나무들을 모두 죽임
						total_add += (tree[i][j][t].first >> 1) * tree[i][j][t].second;
					tree[i][j].erase(tree[i][j].begin(), tree[i][j].begin() + e);//지정된 위치까지 나무들 정보 삭제
				}
			}
			ary[i][j] += total_add; //winter
		}
}
void winter() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (auto &t : tree[i][j])
				if (t.first % 5 == 0)
					for (int d = 0; d < 8; d++) {
						int nx = dx[d] + i, ny = dy[d] + j;
						if (0 <= nx && nx < N && 0 <= ny && ny < N) {
							if (tree[nx][ny].size() && tree[nx][ny].back().first == 1)
								tree[nx][ny].back().second += t.second;
							else
								tree[nx][ny].emplace_back(1, t.second);
						}
					}
}
void solve() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (auto t : tree[i][j])
				cnt += t.second;
	printf("%d", cnt);
}
int main() {
	
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			ary[i][j] = 5;
			scanf("%d", &s2d2[i][j]);
		}
	int x, y, z;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &x, &y, &z);
		tree[--x][--y].emplace_back( z, 1 );
	}
	while (K--) {
		spring_summer_winter();
		winter();
	}
	solve();
}
