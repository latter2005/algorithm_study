#include <iostream>
#include <algorithm>
#include <vector>

//0 -> ,1 <-
int solution(std::vector<int> &A) {
	std::vector <int> pos_0;
	register int start = 0, end=A.size()-1;
	
	while (A[start] == 1 && start < end) 
		start++;
	while (A[end] == 0 && start < end)
		end--;
	if (end - start < 1)
		return 0;
	for (int i = start; i < end; i++) {
		if (A[i] != 1) { //0
			pos_0.push_back(i);
		}
	}
	int count_1 = end - start - pos_0.size() + 1;
	int total = count_1;
	int gap = 0;
	for (int i = 1; i < pos_0.size(); i++) {
		gap += pos_0[i] - pos_0[i - 1]-1;
		total += count_1 - gap;
		if (total > 1000000000)
			return -1;
	}
	return total;
}
int main() {
	std::vector<int> A = {1, 0};

	std::cout<<solution(A);
}