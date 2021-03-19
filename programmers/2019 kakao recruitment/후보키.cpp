#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool check(vector<int> &res, int bit) {
	for (auto t : res)
		if ((t & bit) == t)
			return true;
	return false;
}

int solution(vector<vector<string>> relation) {
	int m = relation.size(), n = relation[0].size();
	vector<int> res;

	for (int i = 1; i < (1 << n); ++i) {
		if (check(res, i)) continue;

		set<string> st;
		for (int j = 0; j < m; ++j) {
			string now = "";
			for (int k = 0, bit = 1 << k; bit <= i; bit <<= 1, ++k) {
				if (i&(bit))
					now += relation[j][k] + ' ';
			}
			st.insert(now);
		}
		if (st.size() == m)
			res.push_back(i);

	}

	return (int)res.size();
}