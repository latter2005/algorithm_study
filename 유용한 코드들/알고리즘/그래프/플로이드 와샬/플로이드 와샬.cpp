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