#include<cstdio>
#define clockwise(idx, m) idx < m ? idx+1 : 1
#define counterwise(idx, m) idx > 1 ? idx-1 : m
#define find_idx(bnck, j) (bnck + j < m ? bnck + j : bnck + j - m) + 1
int main() {
	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);

	int ary[51][51], bnchmark[51] = { 0 };
	int total = 0, cnt = m * n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &ary[i][j]);
			total += ary[i][j];
		}

	bool visited[51][51] = { 0 };

	while (t--) {
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);
		for (int i = x; i <= n; i += x) {
			if (d)//반시계
				bnchmark[i] = (bnchmark[i] + k) % m;
			else//시계
				bnchmark[i] = (bnchmark[i] + m - k) % m;
		}

		bool flag = 0;//수를 지워야 하는 경우의 수가 있음
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < m; ++j) {
				int idx = find_idx(bnchmark[i], j);
				if (ary[i][idx] && (ary[i][idx] == ary[i][clockwise(idx, m)] //시계방향 인접한 수
					|| ary[i][idx] == ary[i][counterwise(idx, m)] ||//반시계방향
					(i > 1 && ary[i][idx] == ary[i - 1][find_idx(bnchmark[i - 1], j)]) ||//큰 원판 인접한 수
					(i < n && ary[i][idx] == ary[i + 1][find_idx(bnchmark[i + 1], j)]))) {//작은 원판

					visited[i][idx] = 1;//지워야 할 수 체크
					flag = 1;
				}

			}

		if (flag) //지울 수가 있음
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j) {
					if (visited[i][j]) {
						total -= ary[i][j];//수를 지우면 total, cnt 반영
						cnt--;
						ary[i][j] = 0;
						visited[i][j] = 0;
					}
				}

		else {//지운 수가 없음
			if (cnt == 0)	break;//더이상 수가 없으면 빠르게 종료
			double avg = (double)total / cnt;//평균
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j) {
					if (!ary[i][j])	continue;
					if (ary[i][j] < avg) {//평균이하
						ary[i][j]++;
						total++;
					}
					else if(ary[i][j]!=avg){//이상
						ary[i][j]--;
						total--;
					}
				}
		}
	}
	printf("%d", total);
}