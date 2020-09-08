#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1},
	dy[] = {1, 1, 0, -1, -1, -1, 0 ,1};

int solution(vector<int> arrows) {
	
	int answer = 0;
	int cx = 0, cy = 0;
	map<pair<int, int>, bool> vtx;
	map<pair< pair<int, int>, pair<int, int>>, bool> edge;
	vtx[{0, 0}] = 1;
	for (auto cur : arrows) {
		int nx = cx + dx[cur], ny = cy + dy[cur];
		
		if (edge.find({ {cx, cy},{nx, ny} }) == edge.end() && edge.find({ {nx, ny},{cx, cy} }) == edge.end()) {
			edge[{ {cx, cy}, {nx, ny}}] = 1;
			if (vtx.find({ nx, ny }) == vtx.end()) {
				vtx[{nx, ny}] = 1;
			}
			else {
				answer++;
			}

			if (cur % 2 == 1) {
				if (edge.find({ {cx, ny},{nx, cy} }) != edge.end() || edge.find({ {nx, cy},{cx, ny} }) != edge.end()) {
					answer++;
				}
			}
		}
		cx = nx; cy = ny;
		
	}

	return answer;
}
int main() {
	vector<int> board = {4, 2, 0, 5, 0 };


	cout << solution(board);
}

/*
풀이:
map 컨테이너 활용해서 접근한 점, 간선 저장 및 탐색시간 단축
간선은 이어져 있으므로 방문한 점을 방문하게 되면 방 추가, 대각선 그리기 시 반대 대각선이 있다면 방 하나 추가
*/