#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
	int answer = 0;
	int len = s.length();

	for (int i = 0; i < len; i++) {
		stack<char> stk;

		bool f = true;

		for (int j = 0; f && j < len; j++) {
			if (s[j] == '(' || s[j] == '[' || s[j] == '{')
				stk.push(s[j]);
			else if (s[j] == ')') {
				if (stk.empty() || stk.top() != '(') {
					f = false;
					break;
				}
				stk.pop();
			}
			else if (s[j] == ']') {
				if (stk.empty() || stk.top() != '[') {
					f = false;
					break;
				}
				stk.pop();
			}
			else if (s[j] == '}') {
				if (stk.empty() || stk.top() != '{') {
					f = false;
					break;
				}
				stk.pop();
			}
		}
		if (stk.empty() && f)
			answer++;
		s.insert(s.begin(), s.back());
		s.pop_back();
	}

	return answer;
}
int main() {
	string t = "[]() {}";
	solution(t);
}