//segment tree recursive, lazy propagation
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
template <typename T>
class segment_tree {
private:
	vector<T> tree;
	vector<T> lazy;
	int ary_size, h, tree_size;
	int qury_left, qury_right;
	T qury_diff;
	T init(vector<T> &ary, int node, int start, int end) {
		if (start == end) {
			return tree[node] = ary[start];
		}
		else {
			return tree[node] = init(ary, node << 1, start, (start + end) >> 1) +
								init(ary, (node << 1) + 1, ((start + end) >> 1) + 1, end);
		}
	}
	void _update_lazy(int node, int start, int end) {
		if (lazy[node] != 0) {
			tree[node] += (end - start + 1)*lazy[node];
			// leaf가 아니면
			if (start != end) {
				lazy[node << 1] += lazy[node];
				lazy[(node << 1) + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	void _update_range(int node, int start, int end) {
		_update_lazy(node, start, end);
		if (qury_left > end || qury_right < start) {
			return;
		}
		if (qury_left <= start && end <= qury_right) {
			tree[node] += (end - start + 1)*qury_diff;
			if (start != end) {
				lazy[node << 1] += qury_diff;
				lazy[(node << 1) + 1] += qury_diff;
			}
			return;
		}
		_update_range(node << 1, start, (start + end) >> 1);
		_update_range((node << 1) + 1, ((start + end) >> 1) + 1, end);
		tree[node] = tree[node << 1] + tree[(node << 1) + 1];
	}
	T _sum(int node, int start, int end) {
		_update_lazy(node, start, end);
		if (qury_left > end || qury_right < start) {
			return 0;
		}
		if (qury_left <= start && end <= qury_right) {
			return tree[node];
		}
		return _sum(node << 1, start, (start + end) >> 1) + 
			_sum((node << 1) + 1, ((start + end) >> 1) + 1, end);
	}
public:
	segment_tree(vector<T> &ary) : ary_size(ary.size()){
		h = (int)ceil(log2(ary.size()));
		tree_size = (1 << (h + 1)) - 1;
		tree.resize(tree_size);
		lazy.resize(tree_size);
		init(ary, 1, 0, ary.size() - 1);
	}
	segment_tree(vector<T> &ary, int start, int end) : ary_size(end-start+1) {
		h = (int)ceil(log2(end - start + 1));
		tree_size = (1 << (h + 1)) - 1;
		tree.resize(tree_size);
		lazy.resize(tree_size);
		init(ary, 1, start, end);
	}
	void update_range(int left, int right, T diff) {
		qury_left = left;
		qury_right = right;
		qury_diff = diff;
		_update_range(1, 0, ary_size - 1);
	}
	T qury(int left, int right) {
		qury_left = left;
		qury_right = right;
		return _sum(1, 0, ary_size-1);
	}
};





int solution(vector<int> arr) {
	int answer = 1;
	segment_tree<int> tree(arr);
	tree.update_range(3, 4, 10);
	tree.update_range(3, 4, 10);
	tree.update_range(3, 4, 10);
	tree.update_range(3, 4, 10);
	tree.update_range(3, 4, 10);
	return tree.qury(0 ,4);
}


int main() {
	vector<int> arr = { 1, 2, 3, 4, 5 };
	printf("%d", solution(arr));
}