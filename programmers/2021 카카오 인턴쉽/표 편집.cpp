#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef struct node {
	int up, down;
	bool alive;
};

string solution(int n, int k, vector<string> cmd) {
	string answer = "";

	node ary[1000000];
	stack<int> stk;
	for (int i = 0; i < n; i++) {
		ary[i] = { i - 1, i + 1, true };
	}

	for (auto c : cmd) {
		char op = c[0];

		if (op == 'U') {
			int cnt = stoi(c.substr(2));
			while (cnt && ary[k].up != -1) {
				k = ary[k].up;
				cnt--;
			}

		}
		else if (op == 'D') {
			int cnt = stoi(c.substr(2));
			while (cnt && ary[k].down != n) {
				k = ary[k].down;
				cnt--;
			}
		}
		else if (op == 'C') {
			stk.push(k);
			ary[k].alive = false;


			if (ary[k].up != -1)
				ary[ary[k].up].down = ary[k].down;

			if (ary[k].down != n) {
				ary[ary[k].down].up = ary[k].up;
				k = ary[k].down;
			}
			else
				k = ary[k].up;

		
				
		}
		else {// Z
			int idx = stk.top();
			stk.pop();

			ary[idx].alive = true;
			if(ary[idx].up!=-1)
				ary[ary[idx].up].down = idx;
			if (ary[idx].down != n)
				ary[ary[idx].down].up = idx;
			 
		}

	}

	for (int i = 0; i < n; i++) {
		if (ary[i].alive)
			answer.push_back('O');
		else
			answer.push_back('X');
	}
		
	return answer;
}

int main() {
	vector<string> t = { "C","C","C","C", "Z","Z" ,"Z" ,"Z" };
	solution(10, 9, t);
}