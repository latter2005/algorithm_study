#include <string>
#include <vector>
using namespace std;
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	int ary[3][2][2][2][100001] = { 0 };
	for (auto &str : info) {
		int a, b, c, d, score;
		int i = 0;
		if (str[i] == 'c') a = 0;
		else if (str[i] == 'j')a = 1;
		else a = 2;

		while (str[i] != ' ')i++;
		b = str[++i] != 'b' ? 1 : 0;

		while (str[i] != ' ')i++;
		c = str[++i] != 'j' ? 1 : 0;

		while (str[i] != ' ')i++;
		d = str[++i] != 'c' ? 1 : 0;

		while (str[i] != ' ')i++;
		score = stoi(str.substr(++i));
		ary[a][b][c][d][score]++;
	}
	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 2; b++)
			for (int c = 0; c < 2; c++)
				for (int d = 0; d < 2; d++)
					for (int i = 100000; i > 1; --i)
						ary[a][b][c][d][i - 1] += ary[a][b][c][d][i];
	for (auto &str : query) {
		int a, b, c, d, score;
		int count = 0, i = 0;

		if (str[i] == '-') a = -1;
		else if (str[i] == 'c') a = 0;
		else if (str[i] == 'j')a = 1;
		else a = 2;

		while (str[i] != ' ')i++;
		i += 5;
		if (str[i] == '-') b = -1;
		else if (str[i] == 'b') b = 0;
		else b = 1;

		while (str[i] != ' ')i++;
		i += 5;
		if (str[i] == '-') c = -1;
		else if (str[i] == 'j') c = 0;
		else c = 1;

		while (str[i] != ' ')i++;
		i += 5;
		if (str[i] == '-') d = -1;
		else if (str[i] == 'c') d = 0;
		else d = 1;

		while (str[i] != ' ')i++;
		score = stoi(str.substr(++i));

		for (int q = (a == -1) ? 0 : a; q <= ((a == -1) ? 2 : a); q++)
			for (int w = (b == -1) ? 0 : b; w <= ((b == -1) ? 1 : b); w++)
				for (int e = (c == -1) ? 0 : c; e <= ((c == -1) ? 1 : c); e++)
					for (int r = (d == -1) ? 0 : d; r <= ((d == -1) ? 1 : d); r++)
						count += ary[q][w][e][r][score];


		answer.push_back(count);
	}
	return answer;
}

