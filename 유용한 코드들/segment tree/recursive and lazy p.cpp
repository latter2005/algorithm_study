//segment tree iterative 버전
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAX_SIZE 100000

/*
H : log(N)(올림)
8 -> 3, 2^4-1 = 15
9 -> 4, 2^5-1 = 31
node 개수 : 2^(H+1)-1
int h = (int)ceil(log2(n));
int tree_size = (1 << (h+1)) - 1;
*/



int init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1)*lazy[node];
		// leaf가 아니면
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update_range(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right, int diff) {
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) {
		return;
	}
	if (left <= start && end <= right) {
		tree[node] += (end - start + 1)*diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	update_range(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff);
	update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int sum(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right) {
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right) + sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int solution(vector<int> arr) {
	int answer = 1;
	int arr_size = arr.size();
	int h = (int)ceil(log2(arr_size));
	int tree_size = (1 << (h + 1)) - 1;
	vector<int> tree(tree_size);
	vector<int> lazy(tree_size);
	init(arr, tree, 1, 0, arr_size-1);
	update_range(tree, lazy, 1, 0, arr_size - 1, 0, 5, 1);
	return sum(tree, lazy, 1, 0, arr_size - 1, 0, 4);
}


int main() {
	
	vector<int> arr = { 1, 7, 5, 6, 10 };
	printf("%d", solution(arr));
}