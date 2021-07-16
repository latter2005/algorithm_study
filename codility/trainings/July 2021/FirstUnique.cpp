// you can use includes, for example:
#include <algorithm>
#include <unordered_map>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	bool ary[100000] = { false };
	unordered_map<int, int> ump;
	
	int n = A.size();

	for (int i = 0; i < n; i++) {
		auto iter = ump.find(A[i]);
		if (iter == ump.end()) {
			ump[A[i]] = i;
		}
		else {
			ary[i] = true;
			ary[iter->second] = true;
		}
			
	}

	for (int i = 0; i < n; i++)
		if (!ary[i])
			return A[i];

	return -1;
}

int main() {
	vector<int> t = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	solution(t);
}