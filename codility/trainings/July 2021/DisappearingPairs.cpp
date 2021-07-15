// you can use includes, for example:
#include <algorithm>
#include <string>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(string &S) {


	string tmp = "";
	int n = S.length(), prev = 0;

	for (int i = 0; i < n - 1; ) {
		if (S[i] == S[i + 1]) {
			tmp += S.substr(prev, i - prev);
			prev = i += 2;
		}
		else if (i==prev && !tmp.empty() && S[i] == tmp.back()) {
			tmp.pop_back();
			prev = ++i;
		}
		else {
			i++;
		}
	}
	if (prev < n) {
		while (prev < n && !tmp.empty() && S[prev] == tmp.back()) {
			tmp.pop_back();
			++prev;
		}
		tmp += S.substr(prev, n - prev);
	}
	//tmp += S.substr(prev, n - prev);


	return tmp;

}
int main() {
	string t = "ACCAABBC";
	solution(t);
}

/*
abccba
abcbbddc
*/