/*
union-find : weighted quick-union + path compression
if a, b connected => get_root(a) == get_root(b)

N + M lg*N
***** fastest version *****
*/
#include <iostream>

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


int main() {
	int n = 50;

	union_find uf(n);

	cout << "union 0~9\n";
	uf.connect(0, 1);
	uf.connect(0, 2);
	uf.connect(0, 3);
	uf.connect(0, 4);
	uf.connect(0, 5);
	uf.connect(0, 6);
	uf.connect(0, 7);
	uf.connect(0, 8);
	uf.connect(0, 9);
	cout << "0, 9 : " << uf.is_connected(0, 9) << "\n\n";

	cout << "union 10~13\n";
	uf.connect(10, 11);
	uf.connect(10, 12);
	uf.connect(10, 13);
	cout << "3, 12 : " << uf.is_connected(3, 12) << "\n";
	cout << "10, 13 : " << uf.is_connected(10, 13) << "\n\n";

	cout << "union 6 + 12\n";
	uf.connect(6, 12);
	cout << "8, 11 : " << uf.is_connected(8, 11) << "\n";
	cout << "10, 13 : " << uf.is_connected(10, 13) << "\n\n";


	cout << "union 14~49\n";
	for (int i = 15; i < 50; i++)
		uf.connect(14, i);
	cout << "8, 40 : " << uf.is_connected(8, 40) << "\n";
	cout << "30, 19 : " << uf.is_connected(30, 19) << "\n\n";

	cout << "union 3 + 32\n";
	uf.connect(3, 32);
	cout << "8, 40 : " << uf.is_connected(8, 40) << "\n";
	cout << "8, 41 : " << uf.is_connected(8, 41) << "\n";
	cout << "12, 49 : " << uf.is_connected(12, 49) << "\n\n";
}