#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	char ary[255] = { 0 };
	for (int i = 0; i < skill.size(); i++) {
		ary[skill[i]] = i + 1;
	}
	for (auto str : skill_trees) {
		int cnt = 1, fl=1;
		for (auto ch : str) {
			if (ary[ch]) {
				if (ary[ch] != cnt) { fl = 0; break; }
				else cnt++;
			}
		}
		if (fl) answer++;
	}
	return answer;
}

int main() {
	vector<string> board = { "BACDE", "CBADF", "AECB", "BDA", "CBD" };


	cout << solution("CBD", board);
}

//배열 해싱으로 속도 최적화, 처음 순번을 해싱으로 저장하고, 순번에 맞는 문자가 나오지 않는다면 break