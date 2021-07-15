#include <iostream>
#include <algorithm>
#include <vector>


std::vector<int> solution(std::vector<int> &A, int K) {
	if (K == A.size())
		return A;
	else if (A.size() == 0)
		return A;
	for (; K > 0; K--) {
		int tmp = A.back();
		A.pop_back();
		A.insert(A.begin(), tmp);
	}
	return A;
}
int main() {
	std::vector <int> A = { 1, 2, 3, 4, 5, 6 };

	solution(A, 3);
}