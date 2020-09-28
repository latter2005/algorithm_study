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