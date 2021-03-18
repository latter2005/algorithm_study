#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;


typedef struct Trie {
	bool finish = 0;   
	int count = 0;
	Trie* next[26] = { 0 };   
	
	void insert(string &key) {
		int n = key.size();
		Trie* cur_node = this;
		for (auto c : key) {
			cur_node->count++;

			if (cur_node->next[c - 'a'] == NULL)
				cur_node->next[c - 'a'] = new Trie();
			cur_node = cur_node->next[c - 'a'];
		}
		cur_node->count++;
		cur_node->finish = true;
	}
	int find(string & key) {
		int n = key.size();
		Trie* cur_node = this;
		for (auto c : key) {
			if (!cur_node) return 0;
			else if (c != '?')
				cur_node = cur_node->next[c - 'a'];
			else
				return cur_node->count;
		}
		return cur_node ? 1 : 0;
	}
}Trie;



vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	map<int, Trie*> list, rev_list;

	for (auto &t : words) {
		int size = t.size();
		string rev_t = t;
		reverse(rev_t.begin(), rev_t.end());

		auto pos = list.find(size);
		if (pos == list.end()) {
			Trie *t_trie = new Trie(), *rev_t_trie = new Trie();
			t_trie->insert(t); 
			list.emplace_hint(pos, size, t_trie);

			rev_t_trie->insert(rev_t);
			rev_list[size] = rev_t_trie;
		}
		else {
			pos->second->insert(t);
			rev_list[size]->insert(rev_t);
		}
	}
	for (auto &qury : queries) {
		int size = qury.size();
		if (qury[0] != '?') {
			auto iter = list.find(size);
			if (iter != list.end()) 
				answer.push_back(iter->second->find(qury));
			else 
				answer.push_back(0);
			
		}
		else {
			reverse(qury.begin(), qury.end());
			auto iter = rev_list.find(size);
			if (iter != rev_list.end()) 
				answer.push_back(iter->second->find(qury));
			else 
				answer.push_back(0);
		}
	}
	return answer;
}
int main() {
	solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" }, { "frodo", "????o", "fr???", "fro???", "pro?" });
}
/*
["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"]
*/