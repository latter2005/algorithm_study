vector<string> string_split(string s, const char delimiter){
	size_t start = 0;
	size_t end = s.find_first_of(delimiter);

	vector<string> output;

	while (end <= string::npos)
	{
		output.emplace_back(s.substr(start, end - start));

		if (end == string::npos)
			break;

		start = end + 1;
		end = s.find_first_of(delimiter, start);
	}

	return output;
}