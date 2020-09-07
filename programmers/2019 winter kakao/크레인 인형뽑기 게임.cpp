#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int n = board.size();
	int stack[30][30], top[30] = { 0 };
	for (int i = n-1; i >= 0;i--) {
		for (int j = 0; j < n; j++) {
			int t = board[i][j];
			if (t) {
				stack[j][top[j]++] = t;
			}
		}
	}
	int bucket[900], b_top=-1;
	for (auto i : moves) {
		i--;
		if (top[i]) {
			int t = stack[i][--top[i]];
			bucket[++b_top] = t;
			while (b_top > 0 && bucket[b_top] == bucket[b_top - 1]) {
				answer += 2;
				b_top -= 2;
			}
		}
		
	}
	return answer;
}

int main() {
	vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	cout << solution(board, moves);
}

//stack 활용, 많은 연산 대비하여 board를 느린 vector 대신 stack(2차원 배열)으로 변환