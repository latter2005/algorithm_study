#include <string>
#include <vector>
#include <map>
using namespace std;


vector<string> split(string &input, char delimiter) {//스트링을 문자 단위로 나누어서 리턴하는 함수
	vector<string> answer;

	for (int i = 0, prev = 0; i < input.size();) {
		while (i < input.size() && input[i] != delimiter)++i;
		answer.push_back(input.substr(prev, i - prev));
		prev = ++i;
	}

	return answer;
}

typedef struct Rule {
	string flag_name;//flag 이름
	int arg_type; //인수 타입 0: NULL, 1: NUMBER, 2: NUMBERS, 3: STRING, 3: STRINGS
	bool operator<(const Rule &t)const {
		return flag_name < t.flag_name;
	}

	bool check_arg(vector<string>& arg) {//인자가 맞는지 확인하는 함수
		switch (arg_type) {
		case 0://NULL
			return arg.empty();
		case 1://NUMBER
			if (arg.size() != 1)return false;
			for (char c : arg[0])
				if (c < '0' || '9' < c) return false;
			return true;
		case 2://NUMBERS
			for (auto &s : arg) {
				for (char c : s)
					if (c < '0' || '9' < c) return false;
			}
			return true;
		case 3://STRING
			if (arg.size() != 1)return false;
			for (char c : arg[0])
				if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) return false;
			return true;
		case 4://STRINGS
			for (auto &s : arg) {
				for (char c : arg[0])
					if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) return false;
			}
			return true;
		}
		return false;
	}
}Rule;
typedef struct Program {
	string prog_name;//프로그램 이름
	map<string, Rule*> rule_table;//프로그램의 명령어들
	Program(string& name, vector<string>& flag_rules) {
		make_program(name, flag_rules);
	}

	bool check_flag(string &flag, vector<string>& arg) {//플래그가 맞는지 확인하는 함수
		auto iter = rule_table.find(flag);
		if (iter != rule_table.end()) {
			return iter->second->check_arg(arg);
		}
		return false;
	}
	void make_program(string& name, vector<string>& flag_rules) {//프로그램 생성
		prog_name = name;//이름 입력
		for (auto &r : flag_rules) {//명령어 테이블 생성
			vector<string> tmp = split(r, ' ');
			//플래그 [0]:flag 이름, [1]: 인자 타입
			//별칭 [0] :플래그 이름, [1] : ALIAS, [2] : 별칭 이름
			auto &cur_rule = rule_table[tmp[0]];
			if (cur_rule == NULL)
				cur_rule = new Rule();
			cur_rule->flag_name = tmp[0];

			if (tmp[1] == "NULL")
				cur_rule->arg_type = 0;
			else if (tmp[1] == "NUMBER")
				cur_rule->arg_type = 1;
			else if (tmp[1] == "NUMBERS")
				cur_rule->arg_type = 2;
			else if (tmp[1] == "STRING")
				cur_rule->arg_type = 3;
			else if (tmp[1] == "STRINGS")
				cur_rule->arg_type = 4;
			else if (tmp[1] == "ALIAS") {//별칭 할당
				
				if (rule_table[tmp[2]] == NULL)
					rule_table[tmp[2]] = cur_rule;
				else
					cur_rule = rule_table[tmp[2]];
			}
		}

	}

	bool exec_program(vector<string>& arg) {
		if (prog_name != arg[0])//프로그램 이름 검사
			return false;

		map<Rule*, bool> check_dup;
		for (int i = 1; i < arg.size();) {//플래그, 인자 처리
			auto t = rule_table.find(arg[i]);
			if (t!=rule_table.end() && check_dup[(t->second)]) {//중복 플레그 발생시
				return false;
			}
			check_dup[(t->second)] = 1;

			vector<string> t_arg;//현재 플래그의 인수들
			int j = i + 1;
			while (j < arg.size() && arg[j][0] != '-') {//다음 플래그 전까지 인수들을 받음
				t_arg.push_back(arg[j]);
				j++;
			}
			if (!check_flag(arg[i], t_arg))//플래그 체크
				return false;
			i = j;
			
		}
		return true;
	}
}Program;



vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
	vector<bool> answer;

	//flag_rules 처리
	Program prog(program, flag_rules);



	//commands 처리
	for (string &c : commands) {
		vector<string> tmp = split(c, ' ');//[0]: 프로그램, [1]: flag [2]: 인자 ....

		answer.push_back(prog.exec_program(tmp));
	}


	return answer;
}
int main() {
	string p = "bank";
	vector<string> f = { "-send STRING", "-a ALIAS -amount", "-amount NUMBERS" };
	vector<string> c = { "bank -send abc -amount 500 200 -a 400", "bank -send abc -a hey" };
	solution(p, f, c);

}
/*

*/