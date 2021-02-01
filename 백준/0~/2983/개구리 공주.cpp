#include <iostream>
#include <algorithm>

using namespace std;
typedef struct pir {
	int x, y;
}pir;
typedef struct point {
	int val, x, idx;
	bool operator<(point &t)const {
		if (val != t.val)return val < t.val;
		return x < t.x;
	}
}point;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	pir input[100000];
	point trans[100000];
	char tmp[100001];
	int n, k;
	cin >> n >> k;
	cin >> tmp;
	for (int i = 0; i < n; ++i)
		cin >> input[i].x >> input[i].y;

	int graph[100001][4] = { 0 };

	for (int i = 0; i < n; i++)
		trans[i] = { input[i].x + input[i].y, input[i].x, i + 1 };
	sort(trans, trans + n);
	for (int i = 0; i < n - 1; i++) {
		if (trans[i].val == trans[i + 1].val) {
			graph[trans[i].idx][1] = trans[i + 1].idx;
			graph[trans[i + 1].idx][2] = trans[i].idx;
		}
	}

	for (int i = 0; i < n; i++)
		trans[i] = { input[i].y - input[i].x, input[i].x, i + 1 };
	sort(trans, trans + n);
	for (int i = 0; i < n - 1; i++) {
		if (trans[i].val == trans[i + 1].val) {
			graph[trans[i].idx][0] = trans[i + 1].idx;
			graph[trans[i + 1].idx][3] = trans[i].idx;
		}
	}

	int cur = 1, next;
	for (int i = 0; i < k; i++) {
		if (next = graph[cur][tmp[i] - 'A']) {
			if (graph[cur][0])graph[graph[cur][0]][3] = graph[cur][3];
			if (graph[cur][3])graph[graph[cur][3]][0] = graph[cur][0];
			if (graph[cur][1])graph[graph[cur][1]][2] = graph[cur][2];
			if (graph[cur][2])graph[graph[cur][2]][1] = graph[cur][1];

			cur = next;
		}
	}
	cout << input[cur - 1].x << ' ' << input[cur - 1].y;
}

