#include <iostream>
#include <ㅊstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef struct Trie {
	bool finish;    //끝나는 지점을 표시해줌
	int count;
	Trie* next[26];    //26가지 알파벳에 대한 트라이
	Trie() : finish(false), count(1) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0')
			finish = true;    //문자열이 끝나는 지점일 경우 표시
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL)
				next[curr] = new Trie();    //탐색이 처음되는 지점일 경우 동적할당
			else next[curr]->count++;
			next[curr]->insert(key + 1);    //다음 문자 삽입
		}
	}
	int find(const char* key) {
		if (*key == '?') {
			int result = 0;
			for (int i = 0; i < 26; i++)
				if (next[i]) result += next[i]->count;
			return result;
		}
		int curr = *key - 'a';
		if (next[curr] == NULL)return 0;//찾는 값이 존재하지 않음
		if (*(key + 1) == '?') return next[curr]->count;
		return next[curr]->find(key + 1); //다음 문자를 탐색
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
			t_trie->insert(t.c_str()); rev_t_trie->insert(rev_t.c_str());
			list[size] = t_trie; rev_list[size] = rev_t_trie;
		}
		else {
			list[size]->insert(t.c_str());
			rev_list[size]->insert(rev_t.c_str());
		}
	}
	for (auto &qury : queries) {
		int size = qury.size();
		if (qury[0] == '?') {
			if (rev_list.find(size) == rev_list.end()) { answer.push_back(0); continue; }
			auto target_trie = rev_list[size];
			reverse(qury.begin(), qury.end());
			answer.push_back(target_trie->find(qury.c_str()));
		}
		else {
			if (list.find(size) == list.end()) { answer.push_back(0); continue; }
			auto target_trie = list[size];
			answer.push_back(target_trie->find(qury.c_str()));
		}
	}
	return answer;
}


int main() {
	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
	auto t = solution(words, queries);
}

/*
{"frodo", "front", "frost", "frozen", "frame", "kakao"}
{"fro??", "????o", "fr???", "fro???", "pro?"}
https://jason9319.tistory.com/129 자료구조 트라이 참고
트라이를 통해 탐색시간 줄임, map 컨테이너로 빠른접근, 메모리 절약
*/