#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> que;
	priority_queue<int, vector<int>, less<int>> dup;
	sort(rocks.begin(), rocks.end());
	rocks.push_back(distance);
	int * ary = &rocks[0];
	int size = rocks.size();

	for (int i = 0, prev=0; i < size; i++) {
		que.push({i, ary[i]-prev});
		prev = ary[i];
	}
	

	for (int i = 0; i < n;) {
		auto &que_top = que.top();
		if (dup.empty()) {
			dup.push(que_top.second);
			que.pop();
			i++;
		}
		else {
			auto &dup_top = dup.top();
			if (que_top.second == dup_top) {
				dup.pop();
			}
			else {
				que.pop();
				i++;
			}
		}
		
	}
	while (!dup.empty() && que.top().second == dup.top()) {
		que.pop();
		dup.pop();
	}
	return que.top().second;
}

int main() {
	vector<int> rocks = { 2, 14, 11, 21, 17 };
	cout << solution(25, rocks, 2);
}

/*
{2, 14, 11, 21, 17}
distance 기준으로 이분탐색
*/