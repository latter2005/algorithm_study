#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;

int solution(vector<string> arr){
	int mx[101][101], mn[101][101];
	int num = arr.size() / 2 + 1;
	for (int i = 0, j=0; i < arr.size(); i += 2, j++) {
		mn[j][j] = mx[j][j] = stoi(arr[i]);
		for (int k = j + 1; k < num; k++) {
			mx[j][k] = 0x7fffffff + 1;
			mn[j][k] = 0x7fffffff;
		}
	}

	for (int c = 1; c < num; c++) {
		for (int i = 0; i < num - c; i++) {
			int j = i + c;						//계산 결과 [i][j]
			for (int cur = i; cur < j; cur++) {
				if (arr[(cur << 1) + 1] == "-") {
					mx[i][j] = max(mx[i][cur] - mn[cur + 1][j], mx[i][j]);
					mn[i][j] = min(mn[i][cur] - mx[cur + 1][j], mn[i][j]);
				}
				else {
					mx[i][j] = max(mx[i][cur] + mx[cur + 1][j], mx[i][j]);
					mn[i][j] = min(mn[i][cur] + mn[cur + 1][j], mn[i][j]);
				}
			}
		}
	}

	

	return mx[0][num-1];

}



int main() {
	vector<string> arr = { "1", "-", "3", "+", "5", "-", "8" };
	cout << solution(arr);
}

/*
2차원 dp 문제, min max 따로 둬서 +계산은 그대로, -계산 시 max = max-min, min = min-max
*/