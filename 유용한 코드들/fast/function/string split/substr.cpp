vector<string> split(string &input, char delimiter) {
	vector<string> answer;
	
	for (int i = 0, prev = 0; i < input.size();) {
		while (i < input.size() && input[i] != delimiter)++i;
		t.push_back(s.substr(prev, i - prev));
		prev = ++i;
	}

	return answer;
}