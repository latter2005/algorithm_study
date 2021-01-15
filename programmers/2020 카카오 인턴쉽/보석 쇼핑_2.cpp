#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
	map <string, int> mp;//int 값이 0이 되면 들고있는 해당 보석의 수가 0개 = 모든 보석을 가지고 있지 않음
	int min_left=0, min_right=0;
	int left = 0, right = 0;
	while (right < gems.size()) {
		auto t = mp.emplace(gems[right], 1);
		if (t.second) {//새로운 보석인 경우

			right++;
			min_right = right;//즉시 갱신
			min_left = left;

		}
		else {//들고 있는 보석인 경우
			t.first->second++;
			right++;
			while (mp[gems[left]] > 1) {//왼쪽 동선을 모든 보석을 들고있는 선에서 갱신
				mp[gems[left]]--;
				left++;
				if(min_right - min_left > right - left)//동선이 짧은 경우에만 갱신
					min_right = right, min_left = left;
			}
		}
	}
	return {++min_left, min_right};
}

int main() {
	auto t = solution({ "DIA", "RUBY", "DIA", "a", "DIA", "EMERALD", "SAPPHIRE", "RUBY" });
	printf("%d %d", t[0], t[1]);
}

