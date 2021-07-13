#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge {
	int dest, cost;
	bool traped;
}edge;
typedef struct pir {
	int bit, idx, cost;
}pir;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	int answer = 0x7fffffff;

	int trp[1001] = { 0 };
	for (int i = 0, bit = 1; i < traps.size(); i++, bit<<=1)
		trp[traps[i]] = bit;
	vector<edge> ary[1001];

	for (auto &t : roads) {
		ary[t[0]].push_back({ t[1], t[2], false });
		if(trp[t[0]] || trp[t[1]])
			ary[t[1]].push_back({ t[0], t[2], true });
	}

	int dp[1 << 15][1000];
	memset(dp, 0x7f, sizeof dp);

	queue<pir> que;
	que.push({ 0, start, 0 });
	while (!que.empty()) {
		auto cur = que.front(); que.pop();

		if (cur.idx == end) {
			answer = cur.cost < answer ? cur.cost : answer;
			continue;
		}
		else if (answer < cur.cost || dp[cur.bit][cur.idx] < cur.cost)continue;


		dp[cur.bit][cur.idx] = cur.cost;
		if (trp[cur.idx])
			cur.bit ^= trp[cur.idx];

		bool cur_bit = trp[cur.idx] & (cur.bit & trp[cur.idx]);
		for (auto &next : ary[cur.idx]) {
			bool next_bit = trp[next.dest] & (cur.bit & trp[next.dest]);
			
			if ((cur_bit ^ next_bit) == next.traped)
				que.push({cur.bit, next.dest, cur.cost + next.cost});
		}
	}


	return answer;
}

int main() {
	solution(4, 1, 4, { {1, 2, 1}, {3, 2, 1}, {2, 4, 1} }, {2, 3});
}