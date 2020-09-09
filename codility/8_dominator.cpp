#include <iostream>
#include <algorithm>
#include <map>
#include <vector>


int solution(std::vector<int> &A){
	int half = A.size() / 2;
	std::map <int,std::vector<int>> tmp;
	for (int i = 0; i < A.size(); i++) {
		auto iter = tmp.find(A[i]);
		if (iter == tmp.end()) {
			std::vector <int> val = {1, i};
			tmp[A[i]] = val;
			if (half < 1)
				return i;
		}
		else {
			(*iter).second[0]++;
			if ((*iter).second[0] > half)
				return (*iter).second[1];
		}	
	}
	return -1;
}
int main() {
	std::vector <int> A= {1};

	std::cout<<solution(A);
}