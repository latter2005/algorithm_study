/*
프로그래머스 캠핑 문제
참고 : https://jayrightthere.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%BA%A0%ED%95%91
쐐기 개수 누적합 구할 때 조건식 삭제, 아직 이해하기엔 조금 부족함
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int solution(int n, vector<vector<int>> &data) {
	int dp[5000][5000] = { 0 }, answer = 0;
	vector<int> x(n), y(n);
	sort(data.begin(), data.end());
	for (auto &t : data) {
		x.push_back(t[0]);
		y.push_back(t[1]);
	}
	unordered_set<int> sx(x.begin(), x.end()), sy(y.begin(), y.end());
	x.assign(sx.begin(), sx.end());
	sort(x.begin(), x.end());
	y.assign(sy.begin(), sy.end());
	sort(y.begin(), y.end());
	int tx, ty;
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < x.size(); j++)
			if (data[i][0] == x[j]) {
				tx = data[i][0] = j;
				break;
			}
		for (int j = 0; j < y.size(); j++)
			if (data[i][1] == y[j]) {
				ty = data[i][1] = j;
				break;
			}
		dp[tx][ty] = 1;
	}
	for (int j = 1; j < n; j++)
		dp[0][j] += dp[0][j - 1];
	for (int i = 1; i < n; i++) {
		dp[i][0] += dp[i - 1][0];
		for(int j = 1; j < n; j++){
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	int ax, ay, bx, by;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (data[i][0] == data[j][0] || data[i][1] == data[j][1]) continue;
			ax = data[i][0] < data[j][0] ? data[i][0] : data[j][0];
			bx = data[i][0] > data[j][0] ? data[i][0] : data[j][0];
			ay = data[i][1] < data[j][1] ? data[i][1] : data[j][1];
			by = data[i][1] > data[j][1] ? data[i][1] : data[j][1];
			if (ax + 1 > bx - 1 || ay + 1 > by - 1) 
				answer++;
			else if (!(dp[bx - 1][by - 1] - dp[bx - 1][ay] - dp[ax][by - 1] + dp[ax][ay])) answer++;
		}
	}
	return answer;
}

void main() {
	vector<vector<int>> data = { {0, 0}, {1, 1}, {0, 1}, {2, 0} };
	solution(4, data);
}

/*
4	{{0, 0}, {1, 1}, {0, 2}, {2, 0}}	3
*/