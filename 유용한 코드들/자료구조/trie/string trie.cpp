#include <string>
#include <vector>
#include <cstdio>
using namespace std;
struct Trie {
	bool finish;    //끝나는 지점을 표시해줌
	int count = 0;
	Trie* next[26];    //26가지 알파벳에 대한 트라이
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(string key) {
		int n = key.size();
		Trie* cur_node = this;
		for (int i = 0; i < n; i++) {//for(auto &t : key)
			cur_node->count++;

			int cur_idx = key[i] - 'a';
			if (cur_node->next[cur_idx] == NULL)
				cur_node->next[cur_idx] = new Trie();
			cur_node = cur_node->next[cur_idx];
		}
		cur_node->count++;
		cur_node->finish = true;
	}
	Trie* find(string key) {
		int n = key.size();
		Trie* cur_node = this;
		for (int i = 0; i < n; i++) {//for(auto &t : key)
			int cur_idx = key[i] - 'a';
			if (cur_node->next[cur_idx] == NULL)
				return NULL;
			cur_node = cur_node->next[cur_idx];
		}
		if (cur_node->finish) return cur_node;
		else return NULL;
	}
	bool find_and_insert(string key) {
		int n = key.size();
		Trie* cur_node = this;
		for (int i = 0; i < n; i++) {//for(auto &t : key)
			cur_node->count++;

			int cur_idx = key[i] - 'a';
			if (cur_node->next[cur_idx] == NULL)
				cur_node->next[cur_idx] = new Trie();

			cur_node = cur_node->next[cur_idx];
		}
		if (cur_node->finish)
			return true;
		cur_node->count++;
		cur_node->finish = true;
		return false;
	}
	bool erase(string key) {
		int n = key.size();
		Trie* stack[11];
		Trie* cur_node = this;
		for (int i = 0; i < n; i++) {//for(auto &t : key)
			int cur_idx = key[i] - 'a';
			if (cur_node->next[cur_idx] == NULL)
				return false;
			stack[i] = cur_node;
			cur_node = cur_node->next[cur_idx];
		}
		if (cur_node->finish) {
			cur_node->count--;
			cur_node->finish = false;
			for (int i = 0; i < n; i++)
				stack[i]->count--;
			return true;
		}
		return false;
	}
	int counting(string key) {
		int n = key.size();
		Trie* cur_node = this;
		for (int i = 0; i < n; i++) {//for(auto &t : key)
			int cur_idx = key[i] - 'a';
			if (cur_node->next[cur_idx] == NULL)
				return 0;
			cur_node = cur_node->next[cur_idx];
		}
		return cur_node->count;
	}
};

int main() {
	vector<string> t = { "abdf", "abc", "a" , "at", "avvvv"};
	Trie trie;
	bool c;
	for (auto s : t) {
		c = trie.find_and_insert(s);
	}
	trie.erase("a");
	trie.erase("abc");
	trie.erase("asdf");

}