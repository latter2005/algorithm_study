vector<string> split(string &input, char delimiter) {
	vector<string> answer;
	
	for (int i = 0, prev = 0; i < input.size();) {
		while (i < input.size() && input[i] != delimiter)++i;
		answer.push_back(input.substr(prev, i + 1));
		prev = i + 1;
	}

	return answer;
}