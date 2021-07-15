#include <iostream>
#include <algorithm>
#include <vector>


int solution(int X, int Y, int D) {
	if (D <= 0)
		return -1;
	else {
		double tmp = ((double)Y - X)/D;
		int i = tmp;
		return (tmp - i != 0) ?  i + 1 : i;
	}
}
int main() {
	

	std::cout<<solution(10, 100, 30);
}