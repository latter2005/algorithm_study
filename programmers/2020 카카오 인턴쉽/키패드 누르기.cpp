#include <string>
#include <vector>

using namespace std;

typedef struct pir {
	int x, y;
	int dist(const pir& dest) {
		int t;
		if (x > dest.x) t = x - dest.x;
		else t = dest.x - x;
		if (y > dest.y) t += y - dest.y;
		else t += dest.y - y;
		return t;
	}
};

string solution(vector<int> numbers, string hand) {
	string answer = "";
	
	pir ary[10] = { {3, 1}, {0, 0}, {0, 1}, {0, 2},
	{1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };

	pir left = { 3, 0 }, right = { 3, 2 };

	for (int n : numbers) {
		switch (n) {
		case 1:case 4:case 7:
			left = ary[n];
			answer.push_back('L');
			break;
		case 3:case 6:case 9:
			right = ary[n];
			answer.push_back('R');
			break;
		default:
			int d = left.dist(ary[n]) - right.dist(ary[n]);
			if (d < 0) {
				left = ary[n];
				answer.push_back('L');
			}
			else if (d) {
				right = ary[n];
				answer.push_back('R');
			}
			else if(hand !="left"){
				right = ary[n];
				answer.push_back('R');
			}
			else {
				left = ary[n];
				answer.push_back('L');
				
			}
		}
	}

	return answer;
}