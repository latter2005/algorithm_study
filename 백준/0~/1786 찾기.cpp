#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void fail_func(vector<int> &fail, string &s) {
	int n = s.length();
	for (int i = 1, m = 0; i < n; ++i) {
		if (s[i] == s[m])
			fail[i] = ++m;
		else if (m != 0) {
			--i;
			m = fail[m - 1];
		}
	}
}
vector<int> kmp(string &str, string &p) {
	int str_len = str.length(), p_len = p.length();
	vector<int> res, fail(p_len);
	fail_func(fail, p);
	for (int i = 0, m = 0; i < str_len; ++i) {
		if (str[i] == p[m]) {
			if (++m == p_len)
				res.push_back(i - p_len + 1);
		}

		else if (m != 0) {
			--i;
			m = fail[m - 1];
		}
	}
	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	string str, p;
	getline(cin, str);
	getline(cin, p);

	
	auto res = kmp(str, p);
	cout << res.size() << '\n';
	for (int t : res) {
		cout << t + 1 << ' ';
	}

}