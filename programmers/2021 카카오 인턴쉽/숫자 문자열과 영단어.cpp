#include <string>
#include <vector>
#include <map>
using namespace std;



int solution(string s) {

	map<string, int> mp;
	mp.emplace("zero", 0);
	mp.emplace("one", 1);
	mp.emplace("two", 2);
	mp.emplace("three", 3);
	mp.emplace("four", 4);
	mp.emplace("five", 5);
	mp.emplace("six", 6);
	mp.emplace("seven", 7);
	mp.emplace("eight", 8);
	mp.emplace("nine", 9);


	
	string tmp;
	int num = 0;


	for (char c : s) {
		if (isalpha(c)) {
			tmp += c;

			auto iter = mp.find(tmp);
			if (iter != mp.end()) {
				num = num * 10 + iter->second;
				tmp.clear();
			}
		}
		else {
			num = num * 10 + (c - '0');
		}
	}


	return num;
}