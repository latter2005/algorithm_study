/*

*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


void point2D_compression(int n, vector<vector<int>> &data) {
	vector<int> x(n), y(n);
	sort(data.begin(), data.end());
	for (auto &t : data) {
		x.push_back(t[0]);
		y.push_back(t[1]);
	}
	unordered_set<int> sx(x.begin(), x.end()), sy(y.begin(), y.end());
	x.assign(sx.begin(), sx.end());
	sort(x.begin(), x.end());
	y.assign(sy.begin(), sy.end());
	sort(y.begin(), y.end());
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < x.size(); j++)
			if (data[i][0] == x[j]) {
				data[i][0] = j;
				break;
			}
		for (int j = 0; j < y.size(); j++)
			if (data[i][1] == y[j]) {
				data[i][1] = j;
				break;
			}
	}
	for (auto &i : data) {
		printf("%d %d\n", i[0], i[1]);
	}
}

void main() {
	vector<vector<int>> data = { {6, 10}, {0, 0}, {1, 1}, {0, 1}, {2, 0}, {700, 15}, {200, 400} };
	point2D_compression(4, data);
}

/*
4	{{0, 0}, {1, 1}, {0, 2}, {2, 0}}	3
*/