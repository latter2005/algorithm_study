//https://latter2005.tistory.com/58
#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int stack[100001] = { -1 }, idx[100001], top = 0;
	int n;
	cin >> n;
	while (n) {
		long long max = 0, size;

		for (int i = 0, t; i < n; i++) {
			cin >> t;
			if (stack[top] > t) {//다음 직사각형이 작은 경우
				do {
					size = ((long long)i - idx[top]) * stack[top];
					max = max < size ? size : max;
					--top;
				} while (stack[top] > t);//만들 수 있는 직사각형 체크
				if (t)
					stack[++top] = t;//i값은 남아있는 흔적을 이용하고, h값만 기록
			}
			else if (t && stack[top] < t) {//직사각형이 큰 경우
				stack[++top] = t;
				idx[top] = i;//스텍에 추가
			}

		}
		while (top != 0) {//남은 히스토그램 처리
			size = ((long long)n - idx[top]) * stack[top];
			max = max < size ? size : max;
			--top;
		}
		cout << max << '\n';
		cin >> n;
	}
}

