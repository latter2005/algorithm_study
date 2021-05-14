#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {

	int n = numbers.size();
	vector<long long> answer(n);

	for (int i = 0; i < n; i++) {
		if (!(numbers[i] & 1))
			answer[i] = numbers[i] | 1;
		else {
			long long ex = 2;
			while (numbers[i] & ex)
				ex <<= 1;
			answer[i] = (numbers[i] | ex) - (ex >> 1);
		}
	}

	return answer;
}