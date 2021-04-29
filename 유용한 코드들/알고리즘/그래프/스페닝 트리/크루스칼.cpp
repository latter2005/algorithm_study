/*
union-find : weighted quick-union + path compression

크루스칼 : 간선 수가 적을 때 적합한 알고리즘

*/
#include <cstdio>

#include <algorithm>
#include <vector>
using namespace std;

#define absol(a) (a>0?a:-(a))

typedef struct union_find {
	int n;
	vector<int> parent, size;
	union_find(int n) : n(n) {
		size.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	/*union_find(int n) : n(n) {
		size.resize(n, 1);
		parent.reserve(n);
		for (int i = 0; i < n; i++)
			parent.push_back(i);
	}*/
	int get_root(int idx) {
		int root = parent[idx];
		while (root != parent[root]) {
			parent[root] = parent[parent[root]];
			root = parent[root];
		}
		return root;
	}
	bool is_connected(int a, int b) {
		return get_root(a) == get_root(b);
	}
	void connect(int a, int b) {
		if (!is_connected(a, b)) {
			int a_root = get_root(a),
				b_root = get_root(b);
			if (size[a_root] >= size[b_root]) {
				parent[b_root] = a_root;
				size[a_root] += size[b_root];
			}
			else {
				parent[a_root] = b_root;
				size[b_root] += size[a_root];
			}
		}
	}
};

typedef struct edge {
	int a, b, cost;

};
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	edge ary[100000];
	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &ary[i].a, &ary[i].b, &ary[i].cost);
	sort(ary, ary + m, [](const edge &a, const edge &b)->bool {
		return a.cost < b.cost;
	});

	union_find uf(n + 1);

	int res=0, cnt = 0;
	for (int i = 0; cnt != n-1 && i < m; i++) {
		if (!uf.is_connected(ary[i].a, ary[i].b)) {
			uf.connect(ary[i].a, ary[i].b);
			res += ary[i].cost;
			cnt++;
		}
	}

	printf("%d", res);
}