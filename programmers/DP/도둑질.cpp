#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
	int answer = 0;
	int dp[3] = {money[0], money[0]};
	for (int i = 2; i < money.size()-1; i++) {
		int t = dp[0] + money[i];
		dp[2] = dp[1] > t ? dp[1] : t;
		dp[0] = dp[1]; dp[1] = dp[2];
	}
	answer = dp[2];

	dp[0] = 0; dp[1] = money[1];
	for (int i = 2; i < money.size(); i++) {
		int t = dp[0] + money[i];
		dp[2] = dp[1] > t ? dp[1] : t;
		dp[0] = dp[1]; dp[1] = dp[2];
	}

	return answer > dp[2] ? answer : dp[2];
}
//dp, 처음집 선택 여부에 따라 탐색 횟수 다름