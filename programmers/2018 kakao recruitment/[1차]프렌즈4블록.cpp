#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	char ary[30][30] = { 0 };

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			ary[j][m - i - 1] = board[i][j];//블록을 떨어뜨릴 때 매모리 접근성 향상

	bool visited[30][30] = { 0 };
	bool f = 1;
	while (f) {//지운 블록이 없을때까지
		f = 0;
		for (int i = 0; i < n - 1; i++) {//검사
			for (int j = 0; j < m - 1; j++) {
				
				if (ary[i][j] && ary[i][j] == ary[i][j + 1] && ary[i][j] == ary[i + 1][j] && ary[i][j] == ary[i + 1][j + 1]) {
					visited[i][j] = visited[i][j + 1] = visited[i + 1][j] = visited[i + 1][j + 1] = 1;
					f = 1;
				}
			}
		}
		if (f) {
			for (int i = 0; i < n; i++)//블록 지우기
				for (int j = 0; j < m; j++)
					if (visited[i][j]) {
						ary[i][j] = 0;
						answer++;
					}
			memset(visited, 0, sizeof visited);

			for (int i = 0; i < n; i++) {//빈공간 떨어뜨리기
				int pos = 0;
				while (pos < m && ary[i][pos])pos++;
				for (int j = pos + 1; j < m; j++) {
					if (ary[i][j]) {
						ary[i][pos++] = ary[i][j];
						ary[i][j] = 0;
					}	
				}
			}
		}
	}
	
	return answer;
}

int main() {
	vector<string> t = { "ttbb", "aacc","aabb", "zzcc","aabb", "aacc" };
	solution(6, 4, t);

}