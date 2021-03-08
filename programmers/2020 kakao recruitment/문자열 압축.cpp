#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string s) {
	int answer = s.size();

	int count[1000], top = -1;
	string stack[1000];

	for (int size = (s.size() >> 1); size >= 1; size--, top = -1) {
		stack[++top] = s.substr(0, size);
		count[top] = 1;
		for (int j = size; j < s.size(); j += size) {
			auto t = s.substr(j, size);
			if (stack[top] != t) {
				stack[++top] = t;
				count[top] = 1;
			}
			else {
				count[top]++;
			}
		}
		int len = 0;
		for (int i = 0; i <= top; i++) {
			len += stack[i].size();
			if (count[i] > 1)
				len += log10(count[i]) + 1;
			
		}
		answer = answer > len ? len : answer;
	}

	return answer;
}