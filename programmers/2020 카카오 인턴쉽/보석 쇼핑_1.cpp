#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {

	map <string, int> mp;//int 값이 0이 되면 들고있는 해당 보석의 수가 0개 = 모든 보석을 가지고 있지 않음
	int kind = 0, min_len = 100001, min_left, min_right;
	int cur_count = 0, left = 0, right = 0;
	for (auto &t : gems)
		if (mp.emplace(t, 0).second)//보석 종류
			kind++;
	while (right < gems.size()) {
		if (cur_count != kind) {//보석의 종류가 부족한경우
			auto &cur = mp[gems[right]];
			if (!cur)//들고 있지 않은 보석이라면 종류 수 늘림
				cur_count++;
			cur++;
			right++;
		}
		else {//모든 보석을 들고있는 경우
			if (min_len > right - left) {//짧은 경우 갱신
				min_len = (min_right = right) - (min_left = left);
			}
			auto &cur = mp[gems[left]];
			if (!(--cur))//들고 있는 보석 수 줄임
				cur_count--;//0이 되면 종류 수를 줄임
			left++;
		}
	}
	while (cur_count == kind) {//왼쪽 갱신
		if (min_len > right - left) {
			min_len = (min_right = right) - (min_left = left);
		}
		auto &cur = mp[gems[left]];
		if (!(--cur))
			cur_count--;
		left++;
	}
	return { ++min_left, min_right };
}