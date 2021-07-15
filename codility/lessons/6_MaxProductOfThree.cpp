#include <iostream>
#include <algorithm>
#include <vector>


int solution(std::vector<int> &A) {
	std::sort(A.begin(), A.end());
	register int size = A.size() - 1;

	if (A[0] < 0 && A[1] < 0) {
		int x = A[size] * A[size - 1] * A[size - 2];
		int y = A[0] * A[1] * A[size];
		return (x > y) ? x : y;
	}
	else {
		return A[size] * A[size - 1] * A[size - 2];
	}
	
	
}
int main() {
	std::vector<int> A = {-3, 1, 2, -2, 5};

	std::cout<<solution(A);
}