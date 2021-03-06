#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int n = lock.size(), m = key.size();

	int zero_cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!lock[i][j])
				++zero_cnt;//맞춰야 할 홈의 개수 저장

	int key_90[20][20], key_180[20][20], key_270[20][20];

	for (int i = 0; i < m; i++)//배열 회전
		for (int j = 0; j < m; j++) {
			key_270[m - 1 - j][i] = key_180[m - 1 - i][m - 1 - j] = key_90[j][m - 1 - i] = key[i][j];
		}


	for (int i = 1 - m; i < n; i++) {
		for (int j = 1 - m; j < n; j++) {
			int lx, ly;
			int cnt = 0;
			for (int ki = 0; cnt != -1 && ki < m; ki++) {
				lx = i + ki;
				if (lx < 0 || n <= lx) continue;
				for (int kj = 0; kj < m; kj++) {
					ly = j + kj;
					if (ly < 0 || n <= ly)continue;//범위 밖
					if (lock[lx][ly] == 0 && key[ki][kj] == 1)++cnt;//홈과 돌기가 맞음
					else if (lock[lx][ly] == key[ki][kj]) { cnt = -1; break; }//0 : 일부 홈이 맞지 않음, 1 : 돌기, 돌기
				}
			}
			if (cnt == zero_cnt) return true;//맞춰야 할 홈의 개수가 맞으면 종료

			cnt = 0;
			for (int ki = 0; cnt != -1 && ki < m; ki++) {//90도
				lx = i + ki;
				if (lx < 0 || n <= lx) continue;
				for (int kj = 0; kj < m; kj++) {
					ly = j + kj;
					if (ly < 0 || n <= ly)continue;
					if (lock[lx][ly] == 0 && key_90[ki][kj] == 1)++cnt;
					else if (lock[lx][ly] == key_90[ki][kj]) { cnt = -1; break; }
				}
			}
			if (cnt == zero_cnt) return true;

			cnt = 0;
			for (int ki = 0; cnt != -1 && ki < m; ki++) {//180도
				lx = i + ki;
				if (lx < 0 || n <= lx) continue;
				for (int kj = 0; kj < m; kj++) {
					ly = j + kj;
					if (ly < 0 || n <= ly)continue;
					if (lock[lx][ly] == 0 && key_180[ki][kj] == 1)++cnt;
					else if (lock[lx][ly] == key_180[ki][kj]) { cnt = -1; break; }
				}
			}
			if (cnt == zero_cnt) return true;

			cnt = 0;
			for (int ki = 0; cnt != -1 && ki < m; ki++) {//270도
				lx = i + ki;
				if (lx < 0 || n <= lx) continue;
				for (int kj = 0; kj < m; kj++) {
					ly = j + kj;
					if (ly < 0 || n <= ly)continue;
					if (lock[lx][ly] == 0 && key_270[ki][kj] == 1)++cnt;
					else if (lock[lx][ly] == key_270[ki][kj]) { cnt = -1; break; }
				}
			}
			if (cnt == zero_cnt) return true;

		}
	}

	return false;
}

int main() {
	vector<vector<int>>lock = { { 1} };
	vector<vector<int>>key = { {1, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0} };
	cout << solution(key, lock);
}

/*
{{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}	{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}

{ {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0} }
{ {1, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0} }
*/