#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
struct Trie {
	bool finish;    
	int count = 0;
	Trie* next[26];    
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(char* key) {
		int n = strlen(key);
		Trie* cur_node = this;
		for (int i = 0; i < n; i++) {
			int cur_idx = key[i] - 'a';
			if (cur_node->next[cur_idx] == NULL) {
				cur_node->count++;
				cur_node->next[cur_idx] = new Trie();
			}
			cur_node = cur_node->next[cur_idx];
		}
		cur_node->finish = true;
	}
	int find(char* key) {
		int n = strlen(key), c = 1;
		Trie* cur_node = next[key[0] - 'a'];
		for (int i = 1; i < n; i++) {
			if (cur_node->count > 1 || cur_node->finish) ++c;
			int cur_idx = key[i] - 'a';
			cur_node = cur_node->next[cur_idx];
		}
		return c;
	}
	
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(2);
	cout.setf(ios::fixed);
	char ary[100000][81];
	int n;
	while (cin >> n) {
		double t = 0;

		Trie trie;
		for (int i = 0; i < n; i++) 
			cin >> ary[i];
		for (int i = 0; i < n; i++)
			trie.insert(ary[i]);
		for (int i = 0; i < n; i++)
			t += trie.find(ary[i]);
		cout  << t / n << '\n';
	}


}