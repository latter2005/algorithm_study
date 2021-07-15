#include <iostream>

#include <vector>
#include <algorithm>

#include <string.h>
std::vector<int> solution(int N, std::vector<int> &P, std::vector<int> &Q) {
	/*bool * ary = new bool[N + 1];
	memset(ary, 4, sizeof(int)*(N + 1));*/
	std::vector <int> result;
	std::vector <int> prime_list;
	bool prime[50001];
	int semiprime[50002];
	register int i;
	memset(prime, true, sizeof(bool)*(N + 1));
	memset(semiprime, 0, sizeof(int)*(N + 1));
	for (i = 2; i * i < N + 1; i++) {
		if (prime[i]) {
			prime_list.push_back(i);
			for (int j = i * i; j < N/2 + 1; j += i) {
				prime[j] = false;
				
			}
		}	
	}
	for (; i < N/2 + 1; i++) {
		if (prime[i])
			prime_list.push_back(i);
	}
	
	for (int i = 0; i < prime_list.size(); i++) {
		for (int j = i; ; j++) {
			if (j >= prime_list.size() || prime_list[i] * prime_list[j] > N ) //|| j < prime_list.size()
				break;
			semiprime[prime_list[i] * prime_list[j]] = 1;
		}
			
	}
	register int count = 0;
	for (int i = 0; i < N + 2; i++) {
		if (semiprime[i])
			semiprime[i] = count++;
		else
			semiprime[i] = count;
	}
	for (int i = 0; i < P.size(); i++) {
		
		result.push_back(semiprime[Q[i]+1] - semiprime[P[i]]);
	}
	
	//delete[] prime;
	return result;
}

int main() {
	/*std::vector <int> A = {10000, 40000, 0};
	std::vector <int> B = { 26000, 50000, 50000};*/
	std::vector <int> A = { 1, 4, 16 };
	std::vector <int> B = { 26, 10, 20 };
	std::vector <int> tmp = solution(26,A, B);
	for (auto i : tmp)
		std::cout << i << ' ';
}