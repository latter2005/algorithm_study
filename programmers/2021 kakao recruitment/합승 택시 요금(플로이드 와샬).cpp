#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef struct edge {
	int dist, cost;
	bool operator<(const edge &t)const {
		return dist < t.dist;
	}
	edge(int d, int c) :dist(d), cost(c) {};
}edge;

void floyd_warshall(vector<vector<int>> &arr, unsigned dist[][201], int n) {
	
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (auto &t : arr) {
		dist[t[0]][t[1]] = t[2];
		dist[t[1]][t[0]] = t[2];
	}
	for (int i = 1; i <= n; i++) 
		for(int s=1;s<=n;s++)
			if(dist[s][i]!=-1)
			for (int e = 1; e <= n; e++) 
				if(dist[i][e]!=-1)
					if(dist[s][e] > dist[s][i] + dist[i][e])
						dist[s][e] = dist[s][i] + dist[i][e];	
}
int solution(int n, int start, int a, int b, vector<vector<int>> arr) {
	int res = 0x7fffffff;
	unsigned dist[201][201];
	memset(dist, -1, sizeof dist);
	floyd_warshall(arr, dist, n);
	
	for (int i = 1; i <= n; i++) {
		if (dist[i][start] != -1) {
			int t = dist[i][start] + dist[i][a] + dist[i][b];
			res = res > t ? t : res;
		}
	}

	return res;
}

int main() {
	vector<vector<int>> arr = { {{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}} };

	printf("%d", solution(6, 4, 5, 6, arr));

}
