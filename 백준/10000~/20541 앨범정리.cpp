#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef struct node {
	string name;
	int alb_count, pic_count;//자식들의 개수 관리
	map<string, node*> child;
	set<string> pic;
	node *parent;
	node(string s, node *p) :name(s), parent(p), alb_count(0), pic_count(0) {};
}node;

inline void mkalb(node *cur, string &s) {
	auto t = cur->child.lower_bound(s);
	if (t == cur->child.end() || t->first != s) {
		cur->child.emplace_hint(t, s, new node(s, cur));
		while (cur != NULL) {//부모노드 반영
			cur->alb_count++;
			cur = cur->parent;
		}
	}
	else
		cout << "duplicated album name\n";
}
inline void rmalb(node *cur, string &s) {
	if (cur->child.empty()) {
		cout << "0 0\n";
		return;
	}
	int ta, tp;
	if (s == "-1") {
		auto t = cur->child.begin();
		ta = t->second->alb_count + 1, tp = t->second->pic_count;
		cur->child.erase(t);
	}
	else if (s == "0") {
		ta = cur->alb_count, tp = cur->pic_count - cur->pic.size();
		cur->child.clear();
	}
	else if (s == "1") {
		auto t = --(cur->child.end());
		ta = t->second->alb_count + 1, tp = t->second->pic_count;
		cur->child.erase(t);
	}
	else {
		auto t = cur->child.find(s);
		if (t == cur->child.end()) {
			cout << "0 0\n";
			return;
		}
		ta = t->second->alb_count + 1, tp = t->second->pic_count;
		cur->child.erase(t);
	}
	cout << ta << ' ' << tp << '\n';
	while (cur != NULL) {//부모 반영
		cur->alb_count -= ta;
		cur->pic_count -= tp;
		cur = cur->parent;
	}
}
inline void insert(node *cur, string &s) {
	auto t = cur->pic.lower_bound(s);
	if (t == cur->pic.end() || *t != s) {
		cur->pic.emplace_hint(t, s);
		while (cur != NULL) {//부모 반영
			cur->pic_count++;
			cur = cur->parent;
		}
	}
	else
		cout << "duplicated photo name\n";
}
inline void del(node *cur, string &s) {
	if (cur->pic.empty()) {
		cout << "0\n";
		return;
	}

	int tp;
	if (s == "-1") {
		tp = 1;
		cur->pic.erase(cur->pic.begin());
	}
	else if (s == "0") {
		tp = cur->pic.size();
		cur->pic.clear();
	}
	else if (s == "1") {
		tp = 1;
		cur->pic.erase(--(cur->pic.end()));
	}
	else {
		auto t = cur->pic.find(s);
		if (t == cur->pic.end()) {
			cout << "0\n";
			return;
		}
		tp = 1;
		cur->pic.erase(t);
	}
	cout << tp << '\n';
	while (cur != NULL) {//부모 반영
		cur->pic_count -= tp;
		cur = cur->parent;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	node *root = new node(string("album"), NULL), *cur = root;

	int n;
	string op, f;
	cin >> n;
	while (n--) {
		cin >> op >> f;
		if (op == "mkalb") {
			mkalb(cur, f);
		}
		else if (op == "rmalb") {
			rmalb(cur, f);
		}
		else if (op == "insert") {
			insert(cur, f);
		}
		else if (op == "delete") {
			del(cur, f);
		}
		else if (op == "ca") {
			if (f == ".."&& cur != root)
				cur = cur->parent;

			else if (f == "/" && cur != root)
				cur = root;

			else {
				auto t = cur->child.find(f);
				if (t != cur->child.end())
					cur = t->second;

			}
			cout << cur->name << '\n';
		}
	}
}
