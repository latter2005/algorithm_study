#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int solution(std::vector<int>& A){

	if (A.size() <= 3) return 0;
	int* firsts = new int[A.size()];
	int* seconds = new int[A.size()];
	memset(firsts, 0, sizeof(int) * A.size());
	memset(seconds, 0, sizeof(int) * A.size());

	for (unsigned int i = 1; i < A.size() - 1; ++i){

		firsts[i] = std::max(firsts[i - 1] + A[i], 0);

		int iInv = A.size() - i - 1;

		seconds[iInv] = std::max(seconds[iInv + 1] + A[iInv], 0);

	}

	int sumMax = 0;

	for (unsigned int i = 1; i < A.size() - 1; ++i){

		sumMax = std::max(sumMax, firsts[i - 1] + seconds[i + 1]);

	}
	delete[] firsts;
	delete[] seconds;
	return sumMax;
}

int main() {
	std::vector <int> A = {3, 2, 6, 4, -1, 5, -1, 2};
	std::cout << solution(A);
}