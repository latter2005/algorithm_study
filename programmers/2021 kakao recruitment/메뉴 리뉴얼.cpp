#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> combination(string input, int r) {
	int n = input.size();
	if (n < r || r < 0) return {};

	vector<string>res;
	string tmp;
	tmp.resize(r);
	vector<bool> per(n);
	fill(per.end() - r, per.end(), true);
	do {
		int cur = 0;
		for (int i = 0; i < n; ++i)
			if (per[i])
				tmp[cur++] = input[i];


		res.emplace_back(tmp);
	} while (next_permutation(per.begin(), per.end()));


	return res;
}
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<map <string, int>> menu(course.size());
	vector<int> max_val(course.size());
	vector<string> answer;
	for (auto &str : orders) {
		sort(str.begin(), str.end());
		for (int i = 0; i < course.size();i++) {
			if (course[i] > str.size())break;
			auto comb = combination(str, course[i]);
			for (auto &t : comb) {
				auto res = menu[i].insert({ t, 1 });
				if (!res.second) {
					res.first->second++;
					max_val[i] = max_val[i] < res.first->second ? res.first->second : max_val[i];
				}
					
			}
		}
	}
	for (int i = 0; i < course.size(); i++) {
		for (auto &t : menu[i]) {
			if (t.second == max_val[i])
				answer.emplace_back(t.first);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	vector<string> o = { "XYZ", "XWY", "WXA" };
	vector<int> c = { 2,3,4 };
	auto v = solution(o, c);
	for (auto t : v)
		cout << t << ' ';
}

/*
{"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}	{2,3,4}	{"AC", "ACDE", "BCFG", "CDE"}
{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}	{2,3,5}	{"ACD", "AD", "ADE", "CD", "XYZ"}
{"XYZ", "XWY", "WXA"}	{2,3,4}	{"WX", "XY"}
테스트 1 〉	통과 (0.07ms, 3.95MB)
테스트 2 〉	통과 (0.05ms, 3.96MB)
테스트 3 〉	통과 (0.07ms, 3.91MB)
테스트 4 〉	통과 (0.07ms, 3.97MB)
테스트 5 〉	통과 (0.07ms, 3.94MB)
테스트 6 〉	통과 (0.15ms, 3.9MB)
테스트 7 〉	통과 (0.16ms, 3.94MB)
테스트 8 〉	통과 (1.47ms, 3.93MB)
테스트 9 〉	통과 (0.92ms, 3.73MB)
테스트 10 〉	통과 (1.40ms, 3.93MB)
테스트 11 〉	통과 (0.76ms, 3.92MB)
테스트 12 〉	통과 (0.94ms, 3.94MB)
테스트 13 〉	통과 (1.31ms, 3.98MB)
테스트 14 〉	통과 (0.83ms, 3.96MB)
테스트 15 〉	통과 (1.33ms, 3.93MB)
테스트 16 〉	통과 (0.33ms, 3.9MB)
테스트 17 〉	통과 (0.18ms, 3.85MB)
테스트 18 〉	통과 (0.07ms, 3.96MB)
테스트 19 〉	통과 (0.02ms, 3.97MB)
테스트 20 〉	통과 (0.20ms, 3.97MB)
*/