#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct pir {
	int idx;
	double fail;
};
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer(N);
	pir ary[502] = { 0 };

	for (auto t : stages)
		++ary[t - 1].fail;

	double t = ary[N].fail;
	for (int i = N - 1; i >= 0; i--) {
		ary[i].idx = i;
		
		t += ary[i].fail;
		ary[i].fail = t ? ary[i].fail / t : 0;
	}
	sort(ary, ary + N, [](const pir& a, const pir& b)->bool {
		if(a.fail!=b.fail)
			return a.fail > b.fail;
		return a.idx < b.idx;
	});

	for (int i = 0; i < N; i++) {
		answer[i] = ary[i].idx + 1;
	}
	return answer;
}