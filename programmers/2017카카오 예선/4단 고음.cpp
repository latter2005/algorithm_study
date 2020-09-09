#include <iostream>
#include <string>

#include <algorithm>
#include <queue>
using namespace std;

int cnt;
void calc(int cur, int plus) {
	if (cur < 1 || 2 * log(cur) / log(3) < plus) return;
	if (cur == 3) {
		if (plus ==  2) cnt++;
		return;
	}
	
	if (cur % 3 == 0 && plus>1) 
		calc(cur / 3, plus - 2);
	calc(cur - 1, plus + 1);
	
}

int solution(int n) {
	calc(n - 2, 2);
	return cnt;
}



int main() {
	//vector<vector<int>> board = { {10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1} };


	cout << solution(24);
}

/*
하양식 풀이로 탐색횟수 줄임, 남은 별 개수와 현재 + 개수를 비교해 +개수가 2*남은 별 개수보다 크다면 종료조건
*/