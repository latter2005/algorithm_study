#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(string &s) {
	int count = 0;
	for (auto c : s)
		if ((count += c != ')' ? 1 : -1) < 0)return false;
	return true;
}
string rec(string p) {
	if (p.empty())return p;//1

	string u, v;
	int i = 1, count = p[0] != ')' ? 1 : -1;
	while (i < p.length() && count)
		count += p[i++] != ')' ? 1 : -1;
	u = p.substr(0, i), v = p.substr(i);//2

	if (check(u))//3
		return u + rec(v);//3-1
	
	//4
	string t = string("(") + rec(v) + ")";//4 - 1, 2, 3
	for (int i = 1; i < u.length() - 1; i++)
		t += u[i] ^ 1;//4-4
	return t;//4-5
}
string solution(string p) {
	if (check(p))return p;
	return rec(p);
}

int main() {

	cout << solution(")(");
}