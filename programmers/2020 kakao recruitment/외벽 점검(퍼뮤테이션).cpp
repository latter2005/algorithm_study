#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {


	int wn = weak.size(), dn = dist.size();
	sort(dist.begin(), dist.end());//퍼뮤테이션 조건 : 정렬

	int answer = dn;//최대 depth 설정
	for (int i = 0; i < wn; i++) {

		weak.push_back(weak.front() + n);//외벽 위치 순환
		weak.erase(weak.begin());

		do {
			int w_idx = 0, depth = 0;//w_idx : 현재 검사 위치, depth : 사람 수

			while (depth < answer) {
				int end = weak[w_idx] + dist[depth];//현재 위치에서 갈 수 있는 곳 까지 검사
				while (w_idx != wn && end >= weak[w_idx]) 
					++w_idx;
				
				if (w_idx != wn)
					++depth;
				else break;
			}
			if (w_idx == wn) {//모든 위치를 검사하면
				if (depth < answer) {
					answer = depth;
				}
			}

		} while (next_permutation(dist.begin(), dist.end()));
	}
	return answer < dn ? answer + 1 : -1;
}
int main() {

	vector<int> w_idx = { 1, 5, 6, 10 };
	vector<int> depth = { 1, 2, 3, 4 };


	cout << solution(100, w_idx, depth);
}
