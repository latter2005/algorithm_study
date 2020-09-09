#include <iostream>
#include <algorithm>
#include <vector>


int solution(std::string &S) {
	int x = 0;
	for (auto i : S) {
		if (i == '(')
			x++;
		else if (i == ')')
			x--;
		if (x < 0)
			return 0;
	}
	return (x != 0) ? 0 : 1;

	
}
int main() {
	std::string S = "(())(";

	std::cout<<solution(S);
}