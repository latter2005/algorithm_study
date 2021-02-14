#include <cstdio>
#define absol(x) (x&0x80000000 ? -(x) : x)
using namespace std;
int main() {
	int n;
	int ary[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &ary[i]);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		ary[i] -= t;
	}
		
	int count = absol(ary[n - 1]), prev = ary[0];
	for (int i = 1; i < n; prev = ary[i++]) {
		if ((ary[i] ^ prev) < 0)//부호가 바뀌는 경우
			count += absol(prev);
		else if((ary[i] ^ (ary[i] - prev)) < 0)//== |ary[i-1]| < |ary[i]|
			count += absol(ary[i] - prev);
	}
	printf("%d", count);
}
