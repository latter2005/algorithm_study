#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	char answer[16];
	int i = 0, cur = 0;
	bool p = 1;
	while (new_id[i] == '.')i++;
	for (; i < new_id.size() && cur<15;i++) {
		
		if (isupper(new_id[i]))
			answer[cur++] = (new_id[i] - 'A' + 'a'), p = false;
		else if (isalnum(new_id[i]) || new_id[i] == '-' || new_id[i] == '_')
			answer[cur++] = (new_id[i]), p = false;

		else if (new_id[i] == '.' && !p) 
			answer[cur++] = (new_id[i]), p = true;
		
	}
	if (!cur) return "aaa";
	else if (answer[cur - 1] == '.')
		answer[cur - 1] = '\0', cur -= 1;
	else answer[cur] = '\0';
	
	if (cur < 3) {
		while (cur != 3) {
			answer[cur] = answer[cur - 1];
			cur++;
		}
		answer[3] = '\0';
	}

	return answer;
}