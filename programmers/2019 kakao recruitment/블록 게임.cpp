/*
ㅗ, ㄴ, ㄴ반대, L, L반대 모양일 때 제거 가능한지 검사, L자 모양과 겹칠 때 돌아가서 다시 검사, 그 외 모양이 나온 행은 impossible 배열에 추가
접근한 도형에 L모양을 제외하고 다시 접근하지 않도록 visited 배열 사용
impossible 배열을 통해 검사 횟수 감소, 메모리 stride 고려하여 board 값 변경
더 큰 테스트 케이스에서 check 함수 효율을 늘리기 위해 transpose board 를 사용하면 더 줄일 수 있을 것 같음, 코드에서는 사용안함
*/
#include <string>
#include <vector>
#include <iostream>

#include <ctime>
#include <Windows.h>
//다음 두줄을 복사해서 쓰시면 됩니다.
// 이 매크로는 Win32 함수를 이용하여 nano second까지 측정할 수 있습니다.
#define CHECK_TIME_START  __int64 freq, start, end; BOOL condition; if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))  QueryPerformanceCounter((_LARGE_INTEGER*)&start);
// a는 float type  milli second이고 b가 FALSE일때는 에러입니다
#define CHECK_TIME_END(a,b) if (condition) {QueryPerformanceCounter((_LARGE_INTEGER*)&end);  a=(float)((double)(end - start)/freq*1000); b=TRUE;}                        else b=FALSE;
using namespace std;


#define go_back(x,n) x>=n?x-n:0


/*
1 2 3 
4 5 6
7 8 9
*/
bool check(vector<vector<int>> &board, int max_i, int j) {
	for (int i = max_i; i >= 1; i--) {
		if (board[i][j])return false;
	}
	return true;
}

int solution(vector<vector<int>> board) {
	int answer = 0, n = board.size();
	bool impossible[52] = { 0 }, visited[201] = { 0 };
	for (auto &i : board) { i.insert(i.begin(), 0); i.push_back(0); }
	vector<int> tmp(n + 2, 0);
	board.emplace(board.begin(), n + 2, 0);
	board.emplace_back(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j]) {
				int cur = board[i][j];
				if (visited[cur]) continue;
				if (board[i][j + 1] == cur) {//1247, 1258
					impossible[j + 1] = impossible[j] = 1;
					if (board[i][j + 2] == cur)//1234, 1235, 1236
						impossible[j + 2] = 1;
					visited[cur]=1;
				}
				if (board[i + 1][j] == cur) {
					if (board[i + 1][j - 1] == cur && board[i + 1][j + 1] == cur) { // 2456
						if (impossible[j - 1] || impossible[j + 1]|| !check(board, i, j + 1)) { // !check(board, i, j - 1)||
							impossible[j - 1] = impossible[j] = impossible[j + 1] = 1;
						}
						else{
							board[i][j] = board[i + 1][j + 1] = board[i + 1][j] = board[i + 1][j - 1] = 0;
							j = go_back(j, 3);
							answer++;
						}
						visited[cur] = 1;
					}
					else if (board[i + 1][j - 1] == cur) {
						if (board[i + 1][j - 2] != cur) {//3659
							impossible[j - 1] = impossible[j] = 1;
						}//3456
						else if (impossible[j - 2] || impossible[j - 1] || !check(board, i, j - 2) || !check(board, i, j - 1)) {
							impossible[j] = impossible[j - 1] = impossible[j - 2] = 1;
						}
						else {
							board[i][j] = board[i + 1][j] = board[i + 1][j - 1] = board[i + 1][j - 2] = 0;
							j = go_back(j, 4);
							answer++;
						}
						visited[cur] = 1;
					}
					else if (board[i + 1][j + 1] == cur) {
						if (board[i + 1][j + 2] != cur) {//1457
							impossible[j + 1] = impossible[j] = 1;
						}//1456
						else if (impossible[j + 1] || impossible[j + 2] || !check(board, i, j + 1) || !check(board, i, j + 2)) {
							impossible[j + 2] = impossible[j + 1] = impossible[j] = 1;
						}
						else {
							board[i][j] = board[i + 1][j + 2] = board[i + 1][j + 1] = board[i + 1][j] = 0;
							j = go_back(j, 2);
							answer++;
						}
						visited[cur] = 1;
					}
					else if(board[i + 2][j] == cur){
						if (board[i + 2][j - 1] == cur) {//2587
							if (!impossible[j - 1] && check(board, i + 1, j - 1)) {
								board[i + 2][j] = board[i + 2][j - 1] = board[i + 1][j] = board[i][j] = 0;
								answer++;
							}
						}
						else if (board[i + 2][j + 1] == cur) {//2587
							if (!impossible[j + 1] && check(board, i + 1, j + 1)) {
								board[i + 2][j + 1] = board[i + 2][j] = board[i + 1][j] = board[i][j] = 0;
								answer++;
							}
						}
					}
				}
			}
		}
	}
	return answer;
}

int main()
{
	vector<vector<int>> board = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,7,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,7,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,3,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,2,3,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0},
	{1,2,2,2,3,3,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0} };
	double time;
	bool b;
	CHECK_TIME_START
	
	cout<<solution(board)<<endl;

	CHECK_TIME_END(time, b);
	printf("time : %lf\n", time);
}

/*
{{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,4,4,0,0,0},{0,0,0,0,3,0,4,0,0,0},{0,0,0,2,3,0,0,0,5,5},{1,2,2,2,3,3,0,0,0,5},{1,1,1,0,0,0,0,0,0,5}}
*/