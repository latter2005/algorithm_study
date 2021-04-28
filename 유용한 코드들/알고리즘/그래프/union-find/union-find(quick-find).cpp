/*
union-find : quick-find
if a, b connected => parent[a] == parent[b]
find() : O(1)
union() : O(n)
*/
#include <iostream>

#include <vector>
using namespace std;

typedef struct union_find {
	int n;
	vector<int> parent;
	union_find(int n) : n(n) {
		parent.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	/*union_find(int n) : n(n) {
		parent.reserve(n);
		for (int i = 0; i < n; i++)
			parent.push_back(i);
	}*/
	bool is_connected(int a, int b) {
		return parent[a] == parent[b];
	}
	void connect(int a, int b) {
		if (!is_connected(a, b)) {
			int tmp = parent[a];
			for (int i = 0; i < n; i++)
				if (tmp == parent[i])
					parent[i] = parent[b];
		}
	}
};


int main() {
	int n = 10;
	
	union_find uf(n);

	uf.connect(0, 1);
	uf.connect(0, 2);

	uf.connect(3, 4);
	uf.connect(4, 5);
	uf.connect(5, 6);

	uf.connect(7, 9);
	uf.connect(8, 9);
	
	cout << "1, 2 : " << uf.is_connected(1, 2)<<'\n';
	cout << "1, 3 : " << uf.is_connected(1, 3) << '\n';

	uf.connect(0, 6);
	cout << "1, 3 : " << uf.is_connected(1, 3) << '\n';
}