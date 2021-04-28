/*
역순 조회
이미 방문한 노드는 dfs 특성에 따라 경로 개수 바로 리턴
경유지->출발지 가는 경로에서 체크 후 목적지->경유지로 갈 때 체크해둔 경로는 가지않음(first_step 활용)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef struct node {
	string name;
	int path;
	bool visited, first_step;
	vector<node*> next;
	node(string t) :name(t), path(0), visited(0) {};
}node;

int dfs(node* cur, node* dest, bool first_step) {
	if (cur->visited) {
		if (cur->first_step == first_step)
			return cur->path;
		else
			return 0;
	}
	int count = 0;
	cur->visited = true;
	cur->first_step = first_step;
	for (auto &t : cur->next) {
		if (t == dest) {
			count++;
		}
		else {
			count += dfs(t, dest, first_step);
		}
	}
	return cur->path = count;
}

int solution(string depar, string hub, string dest, vector<vector<string>> list) {
	map<string, node*> graph;
	for (auto &t : list) {
		node *tmp_a, *tmp_b;
		auto a = graph.lower_bound(t[0]);
		if (a == graph.end() || std::less<string>()(t[0], a->first)) {
			tmp_a = new node({ t[0] });
			graph.insert(a, { t[0], tmp_a });
		}
		else tmp_a = a->second;
		auto b = graph.lower_bound(t[1]);
		if (b == graph.end() || std::less<string>()(t[1], b->first)) {
			tmp_b = new node({ t[1] });
			graph.insert(a, { t[1], tmp_b });
		}
		else tmp_b = b->second;
		tmp_b->next.push_back(tmp_a);
	}
	node *s = graph[depar], *h = graph[hub], *d = graph[dest];
	int x = dfs(h, s, true);
	int y = dfs(d, h, false);

	return x * y;
}


int main(){
	vector<vector<string>> list = { {"a", "h"},{"a", "b"},{"a", "c"}, {"b", "e"}, {"c", "e"}, {"e", "d"},{"d", "i"}, {"e", "f"},{"f", "g"}, {"e", "g"}, {"g", "h"}, {"g", "i"}, {"h", "i"} };
	cout << solution("a",   "g",   "i", list);

	return 0;
}


/*

*/