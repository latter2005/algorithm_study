#include <string>
#include <vector>
#include <map>
#include <regex>
using namespace std;

typedef struct page {
	double basic, link;
}page;


int solution(string word, vector<string> pages) {
	int wlen = word.length(), n = pages.size();

	regex re_pname("<meta [^>]*content=\"https://(\\S*)\"[^>]*/>", regex::icase | regex::optimize);
	regex	re_href("<a[\\s]*href=\"https://(\\S*)\"[\\s]*>", regex::icase | regex::optimize);
	regex	re_word("[^a-z](" + word + "[^a-z])+", regex::icase | regex::optimize);
	smatch mch;


	map<string, int> mp;//주소 : 인덱스
	page pg[20] = { 0 };

	auto e = sregex_iterator();
	for (int i = 0; i < n; ++i) {
		regex_search(pages[i], mch, re_pname);
		mp[mch[1].str()] = i;

		auto s = sregex_iterator(pages[i].begin(), pages[i].end(), re_word);//basic
		while (s != e) {
			pg[i].basic += (s->str().length() - 1) / (wlen + 1);
			++s;

		}
	}

	for (int i = 0; i < n; i++) {
		auto s = sregex_iterator(pages[i].begin(), pages[i].end(), re_href);//link
		int dv = distance(s, e);
		while (s != e) {
			auto t = mp.find((*s)[1].str());//링크된 웹사이트가 기록되어 있으면
			if (t != mp.end())
				pg[t->second].link += pg[i].basic / dv;
			++s;
		}

	}

	double mx = pg[0].basic + pg[0].link;//최댓값 찾기
	int mx_idx = 0;
	for (int i = 1; i < n; i++) {
		if (pg[i].basic + pg[i].link > mx) {
			mx = pg[i].basic + pg[i].link;
			mx_idx = i;
		}
	}

	return mx_idx;
}
