//https://latter2005.tistory.com/27
#include <cstdio>
#include <algorithm>
int main() {
	int n, ary[10000], ans=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	std::sort(ary, ary + n);//정렬
	int i = 0, j = n-1;
	while (i + 1 < n &&ary[i] <= 0 && ary[i + 1] <= 0) {//음수를 양수가 나올 때 까지 묶기
		ans += ary[i] * ary[i + 1];
		i += 2;
	}
	while (j > 0 &&ary[j] > 1 && ary[j - 1] > 1) {//2 이상의 양수 묶기
		ans += ary[j] * ary[j - 1];
		j -= 2;
	}
	while (i <= j) //남은 수들을 더함
		ans += ary[i++];
	printf("%d", n > 1 ? ans : ary[0]);
}

