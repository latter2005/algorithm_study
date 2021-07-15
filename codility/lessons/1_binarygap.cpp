#include <iostream>
#include <algorithm>
#include <vector>


//int solution(int N) {
//	int exp = 1;
//	int max = 0;
//	int cur;
//	int last = 1;
//	while ((exp & N) == 0) {
//		exp <<= 1;
//		last++;
//	}
//	for (cur = last + 1, exp<<=1; exp < N; exp <<= 1) {
//		if ((exp & N) != 0) {
//			if (cur - last - 1 > max) {
//				max = cur - last - 1;
//			}
//			last = cur;
//		}
//		cur++;
//	}
//
//	return max;
//}
int solution(int N) {
	int max = 0;
	register int count = 0;
	while ((N & 1) == 0) 
		N >>= 1;
	for (N >>= 1; N > 0; N >>= 1) {
		if ((N & 1) != 0) {
			if (max < count)
				max = count;
			count = 0;
		}
		else
			count++;
	}
	return max;
}
int main() {
	int x = 0b110110000101;
	std::cout << solution(x);
}