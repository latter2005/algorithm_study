// you can use includes, for example:
// #include <algorithm>

#include <string>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(int A, int B) {
	// write your code in C++14 (g++ 6.2.0)

	int ary[2][2];
	if (A > B) {
		ary[0][0] = A, ary[0][1] = 'a';
		ary[1][0] = B, ary[1][1] = 'b';
	}
	else {
		ary[0][0] = B, ary[0][1] = 'b';
		ary[1][0] = A, ary[1][1] = 'a';
	}
	string t = "";
	
	while (1) {
		if (ary[0][0] <= 2 && ary[1][0] <= 2) {
			t.append(ary[0][0], ary[0][1]);
			t.append(ary[1][0], ary[1][1]);
			break;
		}
		else if (ary[0][0] > ary[1][0]) {
			t.append(2, ary[0][1]);
			t.append(1, ary[1][1]);
			ary[0][0] -= 2;
			--ary[1][0];
		}
		else {
			t.append(1, ary[0][1]);
			t.append(2, ary[1][1]);
			--ary[0][0];
			ary[1][0] -= 2;
		}
	}
		
	return t;
}
int main() {
	solution(9, 9);
}