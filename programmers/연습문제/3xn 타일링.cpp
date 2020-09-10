#include <iostream>
#include <string>

#include <algorithm>
#include <queue>
using namespace std;

int solution(int n) {
	if (n % 2) return 0;
	else {
		unsigned long long f_2 = 3, prev = 3;
		unsigned long long sum = 3, cur = 3;
		for (int i = 2; i < n; i += 2) {
			cur = prev + sum * 2 + 2 ;
			cur %= 1000000007;
			prev = cur;
			sum += cur;
		}
		return (int)(cur % 1000000007);
	}

}


int main() {
	cout << solution(40);
}

/*
점화식 f(n) = 3f(n-2) + 2f(n-4) + ~ + 2f(2) + 2
총 합 변수와 그전 단계의 값만 저장을 하여 메모리 사용 줄임
*/