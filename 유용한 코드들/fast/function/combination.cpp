#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

template<typename T>
vector<vector<T>> combination(vector<T> input, int r) {
	int n = input.size();
	if (n < r || r < 0) return {};

	vector<vector<T> >res;
	vector<T> tmp(r);

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
int main() {
	vector<int> input = { 1, 2, 3, 4, 5 , 6, 7, 8, 9, 10};
	
	for (auto& vec : combination(input, 5)) {
		for (auto& ele : vec)
			cout << ele << ' ';
		cout << '\n';
	}
}