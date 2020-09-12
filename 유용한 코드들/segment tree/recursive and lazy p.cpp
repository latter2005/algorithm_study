//segment tree 리커시브 with lazy propagation
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAZ_SIZE 10000
typedef struct node {
	int val, lazy;
}node;

/*
H : log(N)(올림)
8 -> 3, 2^4-1 = 15
9 -> 4, 2^5-1 = 31
1000 -> 10, 2^11-1 = 2047 
10000 -> 14, 2^15-1
node 개수 : 2^(H+1)-1
*/
node tree[(2<<15)-1];
vector<int> *arr_ptr;
 int init(int index, int start, int end) {
	if (start == end)
		return tree[index].val = (*arr_ptr)[start];
	else {
		int mid = (start + end) / 2;
		return tree[index].val = init((index << 1) + 1, start, mid) +
			init((index << 1) + 2, mid + 1, end);
	}
}


int solution(vector<int> arr) {
	int answer=1;
	int arr_size = arr.size();
	init(0, 0, arr_size - 1);

	return answer;
}

int main() {
	vector<int> arr = { 1, 7, 5, 6, 10 };
	solution(arr);
}