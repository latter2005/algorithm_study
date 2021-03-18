#include <string>
#include <vector>
#include <map>

using namespace std;
typedef struct query {
	char op;
	string id;
	query(char op, string &id) :op(op), id(id) {};
}query;

vector<string> solution(vector<string> record) {
	int n = record.size();
	vector<string> answer;

	vector<query> qry;

	map<string, string> user;

	for (auto &s : record) {
		vector<string> t{};
		for (int i = 0, prev = 0; i < s.size();) {
			while (i < s.size() && s[i] != ' ')++i;
			t.push_back(s.substr(prev, i - prev));
			prev = ++i;
		}

		if (t[0][0] == 'E') {
			qry.emplace_back(0, t[1]);
			user[t[1]] = t[2];
		}
		else if (t[0][0] == 'C') {
			user[t[1]] = t[2];
		}
		else {
			qry.emplace_back(1, t[1]);
		}
	}

	for (auto &q : qry) {
		if (q.op) {
			answer.push_back(user[q.id] + "님이 나갔습니다.");
		}
		else {
			answer.push_back(user[q.id] + "님이 들어왔습니다.");
		}
	}

	return answer;
}
int main() {
	solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
}
