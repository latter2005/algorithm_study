#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int solution(int n, vector<int> weak, vector<int> dist) {

	int wn = weak.size(), dn = dist.size();
	int n_bit = 1 << wn;
	sort(dist.begin(), dist.end(), [](int a, int b)->bool {
		return a > b;
	});

	int depth = 0;
	queue<int> que;
	que.push(0);
	while (!que.empty() && depth < dn) {
		int cur_size = que.size();
		while (cur_size--) {//현재 depth의 모든 경우를 검사
			int visited = que.front();
			que.pop();

			for (int i = 0; i < wn; i++) {
				if (!(visited & (1 << i))) {//현재 위치가 검사되지 않았다면
					int t = visited | (1<<i);//현재 위치 입력
					int next = (i + 1) % wn;
					int val = i < next ? weak[next] - weak[i] : n - weak[i] + weak[next];
					while (val <= dist[depth] && !(t & (1<<next))) {
						t |= (1 << next);
						next = (next + 1) % wn;
						val = i < next ? weak[next] - weak[i] : n - weak[i] + weak[next];
					}
					if (t == n_bit - 1)//모든 위치가 검사 되었다면 종료
						return depth + 1;
					if (visited != t)que.push(t);//추가로 검사한 위치가 있다면 푸쉬
				}
			}
		}
		++depth;
	}


	return -1;
}
