#include <iostream>
#include <algorithm>
#include <vector>


int solution(std::vector<int> &A) {
	int min = 1;
	std::sort(A.begin(), A.end());
	if (A.front() > 1) {
		return 1;
	}
	else if (A.back() < 1)
		return 1;
	
	for (int i = 0; i < A.size();) {
		if (A[i] < min) {
			i++;
		}
		else if (A[i] == min) {
			min++;
			i++;
		}
		else if (A[i] > min) {
			std::cout << min;
			return min;
		}
	}
	std::cout << min;
	return min;
}

int main() {
	std::vector <int> A = { -999999, 999999, 3, 5, -5, 888888, 2, 1 };
	//std::vector <int> A = { -1, -3 };
	solution(A);
}