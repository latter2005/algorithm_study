

#include <vector>
#include <algorithm>
using namespace std;
long long solution(int n, vector<int> times) {
	long long answer = 0;
	int tn = times.size();

	sort(times.begin(), times.end());

	long long mn = (long long)times.front() * n / tn, 
		mx = (long long)times.back() * n / tn,
		mid;


	while (mn <= mx) {
		mid = (mx + mn) >> 1;

		long long t = 0;
		for (int i = 0; i < tn; i++)
			t += mid / times[i];

		if (t < n)
			mn = mid + 1;
		else {
			mx = mid - 1;
			answer = mid;
		}
	}


	return answer;
}

int main() {
	vector<int> ary = { 2, 4, 10, 17 };
	solution(555550, ary);
}