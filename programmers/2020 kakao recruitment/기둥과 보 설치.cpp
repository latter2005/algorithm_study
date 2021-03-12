#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check_row(bool ary[101][101][2], int x, int y) {//보 검사
	if (!x) return false;//보는 바닥에 있을 수 없음
	if (ary[x - 1][y][0] || ary[x - 1][y + 1][0])//기둥 위
		return true;
	if (0 < y && ary[x][y - 1][1] && ary[x][y + 1][1])//양 끝이 보
		return true;
	return false;
}
bool check_col(bool ary[101][101][2], int x, int y) {//기둥 검사
	if (!x)//바닥
		return true;
	if (ary[x - 1][y][0])//기둥 위
		return true;
	if ((0 < y && ary[x][y - 1][1]) || ary[x][y][1])//보 위
		return true;
	return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	bool ary[101][101][2] = { 0 };// 1 : 보, 0 : 기둥
	for (auto &t : build_frame) {
		if (t[2]) {//보
			if (t[3]) {//설치
				if (check_row(ary, t[1], t[0]))
					ary[t[1]][t[0]][1] = 1;
			}
			else {//삭제
				ary[t[1]][t[0]][1] = 0;
				if (0 < t[0] && ary[t[1]][t[0] - 1][1] && !check_row(ary, t[1], t[0] - 1))
					ary[t[1]][t[0]][1] = 1;
				else if (ary[t[1]][t[0]][0] && !check_col(ary, t[1], t[0]))
					ary[t[1]][t[0]][1] = 1;
				else if (ary[t[1]][t[0] + 1][0] && !check_col(ary, t[1], t[0] + 1))
					ary[t[1]][t[0]][1] = 1;
				else if (ary[t[1]][t[0] + 1][1] && !check_row(ary, t[1], t[0] + 1))
					ary[t[1]][t[0]][1] = 1;
				else if (t[1] && ary[t[1] - 1][t[0]][0] && !check_col(ary, t[1] - 1, t[0]))
					ary[t[1]][t[0]][1] = 1;
				else if (t[1] && ary[t[1] - 1][t[0] + 1][0] && !check_col(ary, t[1] - 1, t[0] + 1))
					ary[t[1]][t[0]][1] = 1;
			}
		}
		else {//기둥
			if (t[3]) {//설치
				if (check_col(ary, t[1], t[0]))
					ary[t[1]][t[0]][0] = 1;
			}
			else {//삭제
				ary[t[1]][t[0]][0] = 0;
				if (ary[t[1]][t[0]][1] && !check_row(ary, t[1], t[0]))
					ary[t[1]][t[0]][0] = 1;
				else if (0 < t[0] && ary[t[1]][t[0] - 1][1] && !check_row(ary, t[1], t[0] - 1))
					ary[t[1]][t[0]][0] = 1;
				else if (t[1] && ary[t[1] - 1][t[0]][0] && !check_col(ary, t[1] - 1, t[0]))
					ary[t[1]][t[0]][0] = 1;
				else if (0 < t[0] && ary[t[1] + 1][t[0] - 1][1] && !check_row(ary, t[1] + 1, t[0] - 1))
					ary[t[1]][t[0]][0] = 1;
				else if (ary[t[1] + 1][t[0]][1] && !check_row(ary, t[1] + 1, t[0]))
					ary[t[1]][t[0]][0] = 1;
				else if (ary[t[1] + 1][t[0]][0] && !check_col(ary, t[1] + 1, t[0]))
					ary[t[1]][t[0]][0] = 1;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (ary[i][j][0]) answer.push_back({ j, i, 0 });
			if (ary[i][j][1]) answer.push_back({ j, i, 1 });
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
int main() {
	int n = 5;
	vector < vector<int>> t= { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
	auto res = solution(n, t);

}
/*
5	{{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}}	
{{1,0,0},{1,1,1},{2,1,0},{2,2,1},{3,2,1},{4,2,1},{5,0,0},{5,1,0}}

5	{{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}}	
{{0,0,0},{0,1,1},{1,1,1},{2,1,1},{3,1,1},{4,0,0

*/