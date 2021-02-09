#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline int time_to_int(string &t, int i) {
	int res = 0;
	res += (t[i] - '0') * 36000;
	res += (t[i + 1] - '0') * 3600;

	res += (t[i + 3] - '0') * 600;
	res += (t[i + 4] - '0') * 60;

	res += (t[i + 6] - '0') * 10;
	res += (t[i + 7] - '0');
	return res;
}
inline string int_to_time(int t) {
	char tmp[9];
	sprintf(tmp, "%02d:%02d:%02d", t / 3600, t / 60 % 60, t % 60);
	
	return string(tmp);
}

string solution(string play_time, string adv_time, vector<string> logs) {
	int ary[360001] = { 0 };
	for (auto &t : logs) {
		int s = time_to_int(t, 0), e = time_to_int(t, 9);
		ary[s]++;
		ary[e]--;
	}
	long long max_val, cur_val = ary[0];
	int max_start = 0,	total = time_to_int(play_time, 0), adv_len = time_to_int(adv_time, 0);
	for (int i = 1; i < adv_len; i++) {
		ary[i] += ary[i - 1];
		cur_val += ary[i];
	}
	for (int i = adv_len; i <= total; i++)
		ary[i] += ary[i - 1];
	max_val = cur_val;

	for (int start = 0, end = adv_len; end <= total; start++, end++) {
		cur_val += ary[end] - ary[start];
		if (max_val < cur_val) {
			max_val = cur_val;
			max_start = start + 1;
		}
	}

	return int_to_time(max_start);
}
int main() {
	vector<string> arr = { "00:00:00-00:00:10"};

	cout << solution("99:59:59", "00:00:10", arr);

}
