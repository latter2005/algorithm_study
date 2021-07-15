#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int solution(std::vector<int>& A){
	std::vector <int> peak;
	if (A.size() < 3)
		return 0;

	int max_interval = 0;
	peak.push_back(0);
	for (unsigned int i = 1; i < A.size() - 1; i++) {
		if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
			max_interval = std::max(max_interval, (int)i - peak.back());
			peak.push_back(i);
		}
			
	}
	peak.erase(peak.begin());
	if (peak.size() < 2)
		return peak.size();
	
	
	max_interval /= 2;
	int block_size, div = 2;
	while (A.size() / div > max_interval)
		div++;
	if (div > peak.size())
		div = peak.size();
	for (; div > 0; div--) {
		if (A.size()%div == 0) {
			block_size = A.size() / div;
			register unsigned int i = 0, count = 0;
			while (i < A.size() && count < peak.size()) {
				if (i <= peak[count] && peak[count] < i + block_size) {
					count++;
					i += block_size;
				}
				else {
					count++;
				}
			}
			if (i == A.size()) {
				return div;
			}
		}
		
	}


	return div;
}

int main() {
	std::vector <int> A = {0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0};
	std::cout << solution(A);
}