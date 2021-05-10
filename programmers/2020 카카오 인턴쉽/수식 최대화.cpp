#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef struct node {
	//char type;
	long long num;
	int l, r;
}node;

long long solution(string expression) {
	long long answer = 0;
	
	int len = expression.length(), n=0;
	node ary[50];
	unordered_map<int, vector<int>> mp;

	int prev = 0;
	for (int i = 0; i < len; i++) 
		if (!isdigit(expression[i])) {
			ary[n] = { /*expression[i] ,*/ stoi(expression.substr(prev, i - prev)), n - 1, n + 1 };
			prev = i + 1;

			mp[expression[i]].push_back(n);
			++n;
		}
	ary[n++] = { /*0,*/ stoi(expression.substr(prev)), n-1, -1 };
	


	int seq[3] = { '*', '+', '-' };
	do {

		node tary[50];
		memcpy(tary, ary, sizeof ary);

		for (int i = 0; i < 3; i++) {
			for (int idx : mp[seq[i]]) {
				node &cur = tary[idx];
				if (seq[i] == '*') {
					tary[cur.r].num = cur.num * tary[cur.r].num;
				}
				else if (seq[i] == '+') {
					tary[cur.r].num = cur.num + tary[cur.r].num;
				}
				else {
					tary[cur.r].num = cur.num - tary[cur.r].num;
				}
				tary[cur.r].l = cur.l;
				tary[cur.l].r = cur.r;
			}
		}
		

		tary[n-1].num = llabs(tary[n - 1].num);
		answer = answer < tary[n - 1].num ? tary[n - 1].num : answer;
	} while (next_permutation(seq, seq + 3));

	return answer;
}

int main() {
	string t = "100-200*300-500+20";
	solution(t);
}