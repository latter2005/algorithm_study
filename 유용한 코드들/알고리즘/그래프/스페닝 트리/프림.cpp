#include <cstdio>
#include <cstring>

#include <queue>
#include <vector>
using namespace std;

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
	int idx, cost;
	bool operator<(const edge &a)const {
		return cost > a.cost;
	}
};
int main() {
	int n, m;
	vector<edge> ary[100001];
	int s, e, cost;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &s, &e, &cost);
		ary[s].push_back({ e, cost });
		ary[e].push_back({ s, cost });
	}

	bool visited[100001] = { 0 };
	visited[1] = 1;
	priority_queue <edge, vector<edge>> que;
	for (auto &i : ary[1])
		que.push(i);

	int res = 0;
	
	for (int i = 0; i < n - 1;) {//!que.empty()
		auto cur = que.top();
		que.pop();
		if (visited[cur.idx])continue;

		visited[cur.idx] = 1;
		res += cur.cost;
		i++; //

		for (auto &next : ary[cur.idx]) {
			if (visited[next.idx]) continue;
			que.push(next);
		}
	}

	printf("%d", res);
}