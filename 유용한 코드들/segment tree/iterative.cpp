//segment tree iterative 버전
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAZ_SIZE 10000

/*
H : log(N)(올림)
8 -> 3, 2^4-1 = 15
9 -> 4, 2^5-1 = 31
1000 -> 10, 2^11-1 = 2047
10000 -> 14, 2^15-1
node 개수 : 2^(H+1)-1
*/
int tree[(2 << 15) - 1];
vector<int> *arr_ptr;
int n;
inline void init(vector<int> &arr) { // 트리 순서가 알고리즘이랑 조금 다름
	int n = arr.size();
	for (int i = 0; i < n; i++)
		tree[n + i] = arr[i];
	for (int i = n - 1; i > 0; i--)
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
int query(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += tree[l++];
		if (r & 1) res += tree[--r];
	}
	return res;
}
int solution(vector<int> arr) {
	int answer = 1;
	arr_ptr = &arr;
	n = arr.size();

	init(arr);


	return query(1, 5);
}

int main() {
	vector<int> arr = { 1, 7, 5, 6, 10 };
	printf("%d", solution(arr));
}