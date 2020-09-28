/*
트라이 사용, 속도와 메모리 사용 줄이기 위해 iterative 버전 사용
count가 1이면 더이상의 단어가 없으므로 현재 탐색한 글자의 수가 답
*/
#include <string>
#include <vector>
#include <iostream>
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
	int autocomplete(string key) {
		int n = key.size();
		Trie* cur_node = this;
		for (int i = 0; i < n; i++) {//for(auto &t : key)
			if (cur_node->count == 1)
				return i;
			cur_node = cur_node->next[key[i] - 'a'];
		}
		return key.size();
	}
	
};

int solution(vector<string> words) {
	int answer = 0;
	Trie *root = new Trie();
	for (auto &i : words)
		root->insert(i);
	for (auto &i : words)
		answer += root->autocomplete(i);
	return answer;
}

void main() {
	vector<string> words = { "go","gone","guild" };
	cout << solution(words);
}

/*
{go,gone,guild}	7
{abc,def,ghi,jklm}	4
{word,war,warrior,world}	15
*/