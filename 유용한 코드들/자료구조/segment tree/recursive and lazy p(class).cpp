#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
template <typename T>
class segment_tree {
private:
	vector<T> tree;
	vector<T> lazy;
	/*
	H : log(N)(올림)
	8 -> 3, 2^4-1 = 15
	9 -> 4, 2^5-1 = 31
	node 개수 : 2^(H+1) -> 0번 인덱스는 사용하지 않음
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h+1));
	*/
	int ary_size, h, tree_size;
	int qury_left, qury_right;
	T qury_diff;
	T init(T ary[], int node, int start, int end) {
		if (start == end) {
			return tree[node] = ary[start];
		}
		else {
			return tree[node] = init(ary, node << 1, start, (start + end) >> 1) +
				init(ary, (node << 1) + 1, ((start + end) >> 1) + 1, end);
		}
	}
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
		_update_lazy(node, start, end);//lazy값 반영
		if (qury_left > end || qury_right < start) {
			return;
		}
		if (qury_left <= start && end <= qury_right) {
			tree[node] += (end - start + 1)*qury_diff;//현재 노드 갱신
			if (start != end) {
				lazy[node << 1] += qury_diff;//자식 전파
				lazy[(node << 1) + 1] += qury_diff;
			}
			return;
		}
		_update_range(node << 1, start, (start + end) >> 1);
		_update_range((node << 1) + 1, ((start + end) >> 1) + 1, end);
		tree[node] = tree[node << 1] + tree[(node << 1) + 1];
	}
	T _sum(int node, int start, int end) {
		_update_lazy(node, start, end);//lazy값 반영
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
	segment_tree(T ary[], int size) :ary_size(size) {
		h = (int)ceil(log2(size));
		tree_size = (1 << (h + 1));
		tree.resize(tree_size);
		lazy.resize(tree_size);
		init(ary, 1, 0, size - 1);
	}
	segment_tree(vector<T> &ary) : ary_size(ary.size()){
		h = (int)ceil(log2(ary.size()));
		tree_size = (1 << (h + 1));
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

int solution(vector<double> arr) {
	int answer = 1;
	segment_tree<double> tree(arr);
	//tree.update_range(0, 3, 1);
	//tree.update_range(0, 2, 1);
	return tree.qury(0 ,7);
}

int main() {
	vector<double> arr = { 0, 1, 2, 3, 4, 5, 6, 7};
	printf("%d", solution(arr));
}