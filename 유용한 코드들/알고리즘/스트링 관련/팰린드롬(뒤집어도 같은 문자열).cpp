#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
	int answer = 0;

	int len = strlen(s);
	int dp[2500][2500] = { 0 };
	
	for (int i = 0; i < len - 1; i++) {
		dp[i][i] = 1;
		if (s[i] == s[i + 1])
			dp[i][i + 1] = 1;
	}
	dp[len - 1][len - 1] = 1;


	for (int i = 2; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			if (s[j] == s[j + i] && dp[j + 1][j + i - 1]) {
				dp[j][j + i] = 1;
				answer = i;
			}
		}
	}

	return answer + 1;
}

int main() {
	solution("abeccbb");
}