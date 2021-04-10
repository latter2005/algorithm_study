#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int time_to_int(string &t) {
	return (t[0] - '0') * 600 + (t[1] - '0') * 60 + (t[3] - '0') * 10 + (t[4] - '0');
}
string int_to_time(int t) {
	char tmp[6];
	sprintf(tmp, "%02d:%02d", t / 60, t % 60);
	return string(tmp);
}
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	int ary[2000], size = timetable.size();
	for (int i = 0; i < size; i++)
		ary[i] = time_to_int(timetable[i]);
	sort(ary, ary + size);

	int cur_time = 9 * 60, wait = 0, i = 0;

	for (;n > 1; cur_time += t) {
		for (; i < size && ary[i] <= cur_time; ++wait, ++i);
		
		wait = wait > m ? wait - m : 0;
		n--;
	}
	for (; i < size && ary[i] <= cur_time; ++wait, ++i);

	if (wait < m)
		return int_to_time(cur_time);


	return int_to_time(ary[i - (wait - m) - 1]-1);
}

int main() {
	vector<string> time = { "09:00","09:00","09:01","09:01" };
	solution(3, 2, 2, time);
}