/*
1 =>1
2 => 2
3 => 4
4 => 11
진수 표현 문제
*/


#include <iostream>

#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(int n) {
	string answer = "";
	
	int ex = 1, s = 3;
	while (s < n) {
		ex *= 3;
		s += 3 * ex;
	}

	for (; ex >= 3; ex /= 3) {
		int t = (n - (ex)/3) / ex;

		answer.push_back(t);
		n -= t * ex;
	}
	answer.push_back(n);

	for(int i = answer.length()-1;i>0;i--)
		if (!answer[i]) {
			answer[i] = 3;
			answer[i - 1]--;
		}
	for (char &c : answer) {
		if (c == 3)c = '4';
		else c += '0';
	}

	return answer;
}
//(n != 3 ? n : 4) + '0'
int main() {
	solution(93);
	for(int i=50000000;i<= 50000000;i++)
		cout << i << " : " << solution(i) << '\n';
}