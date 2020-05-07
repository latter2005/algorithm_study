#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
int n, result;

typedef struct node {
	int ary[20][20];
	node() {};
	node(short val) { memcpy(this->ary, (void*)val, sizeof(ary)); };
	void operator=(const node &m) const { memcpy((void*)m.ary, this->ary, sizeof(ary)); }
	bool operator==(const node &m) const {
		for (int i = 0, j = 0; i < n; i++, j = 0) {
			while (j < n)
				if (this->ary[i][j] != m.ary[i][j++]) return false;
		}
		return true;
	}
}node;

int move(int d, int A[][20]){
	int Max_Value = 0;
	if (d == 0){
		for (int i = 0; i < n; i++){
			int Value = -1;
			int Idx = n;

			for (int j = n - 1; j >= 0; j--){
				if (A[i][j] == 0) continue;
				if (A[i][j] == Value){
					A[i][Idx] = A[i][Idx] * 2;
					Value = -1;
				}
				else{
					Value = A[i][j]; Idx--;
					A[i][Idx] = A[i][j];
				}
				Max_Value = std::max(Max_Value, A[i][Idx]);
			}
			for (int j = Idx - 1; j >= 0; j--) A[i][j] = 0;
		}
	}
	else if (d == 1){
		for (int i = 0; i < n; i++){
			int Value = -1;
			int Idx = -1;
			for (int j = 0; j < n; j++) {
				if (A[i][j] == 0) continue;

				if (A[i][j] == Value) {
					A[i][Idx] = A[i][Idx] * 2;
					Value = -1;
				}
				else {
					Value = A[i][j]; Idx++;
					A[i][Idx] = A[i][j];
				}
				Max_Value = std::max(Max_Value, A[i][Idx]);
			}
			for (int j = Idx + 1; j < n; j++) A[i][j] = 0;
		}
	}
	else if (d == 2){
		for (int j = 0; j < n; j++){
			int Value = -1;
			int Idx = n;

			for (int i = n - 1; i >= 0; i--){
				if (A[i][j] == 0) continue;

				if (A[i][j] == Value){
					A[Idx][j] = A[Idx][j] * 2;
					Value = -1;
				}
				else{
					Value = A[i][j]; Idx--;
					A[Idx][j] = A[i][j];
				}

				Max_Value = std::max(Max_Value, A[Idx][j]);
			}
			for (int i = Idx - 1; i >= 0; i--) A[i][j] = 0;
		}
	}
	else if (d == 3){
		for (int j = 0; j < n; j++){
			int Value = -1;
			int Idx = -1;

			for (int i = 0; i < n; i++){
				if (A[i][j] == 0) continue;

				if (A[i][j] == Value){
					A[Idx][j] = A[Idx][j] * 2;
					Value = -1;
				}
				else{
					Value = A[i][j]; Idx++;
					A[Idx][j] = A[i][j];
				}
				Max_Value = std::max(Max_Value, A[Idx][j]);
			}
			for (int i = Idx + 1; i < n; i++) A[i][j] = 0;
		}
	}
	return Max_Value;
}
void dfs(int cur, node nd, int max) {
	if (cur > 4) {
		result = max;
		return;
	}
	for (int d = 0; d < 4; d++) {
		node tmp = nd;
		int max_value = move(d, tmp.ary);
		if (tmp == nd) continue;
		if(result < max_value * std::pow(2, 4-cur))
			dfs(cur + 1, tmp, max_value);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	node tmp;
	std::cin >> n;
	for (int i = 0, j = 0; i < n; i++, j = 0)
		while (j < n) {
			std::cin >> tmp.ary[i][j];
			if (tmp.ary[i][j] > result) result = tmp.ary[i][j];
			j++;
		}
			
	dfs(0, tmp, 0);
	std::cout << result;
	return 0;
}
