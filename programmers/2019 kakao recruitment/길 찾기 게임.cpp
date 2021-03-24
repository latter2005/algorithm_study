#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef struct node{
	int x, y, idx;
	int left, right;//포인터 대신 인덱싱
}node;
node ary[10001];

void travl(vector<vector<int>> &ans, int cur) {
	ans[0].push_back(ary[cur].idx);//프리오더

	if (ary[cur].left)
		travl(ans, ary[cur].left);
	if (ary[cur].right)
		travl(ans, ary[cur].right);
	ans[1].push_back(ary[cur].idx);//포스트 오더
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer(2);
	int n = nodeinfo.size();

	

	for (int i = 0; i < n; i++) {
		ary[i + 1] = { nodeinfo[i][1], nodeinfo[i][0], i + 1 };//x : 세로, y : 가로
	}
	sort(ary + 1, ary + n + 1, [](const node& a, const node& b)->bool {
		if (a.x != b.x) return a.x > b.x;
		return a.y < b.y;
	});

	int root = 1;

	for (int i = 2; i <= n; i++) {//트리 생성
		int prnt = root, chld = i;
		while (1) {
			if (ary[chld].y < ary[prnt].y) {//왼쪽
				if (ary[prnt].left)
					prnt = ary[prnt].left;
				else {
					ary[prnt].left = chld;
					break;
				}
			}
			else {//오른쪽
				if (ary[prnt].right)
					prnt = ary[prnt].right;
				else {
					ary[prnt].right = chld;
					break;
				}
			}
		}
	}
	travl(answer, 1);
		
	return answer;
}

int main() {
	vector < vector<int>> t = { {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
	solution(t);

}

/*
{{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}}
*/