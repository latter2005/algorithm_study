#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct pir {
	int idx, cnt;
}pir;

int main() {
	int r, c, k;
	scanf("%d%d%d", &r, &c, &k);
	r--, c--;
	int ary[100][100] = { 0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &ary[i][j]);

	int mx_x = 3, mx_y = 3, t = 0;

	pir hsh[100][101];

	while (t <= 100 && ary[r][c] != k) {
		memset(hsh, 0, sizeof hsh);
		if (mx_x >= mx_y) {//R연산
			
			for (int i = 0; i < mx_x; i++) {
				for (int j = 0; j < mx_y; j++) {
					if (ary[i][j]) {//0 제외
						hsh[i][ary[i][j]].idx = ary[i][j];//등장한 수 기록
						++hsh[i][ary[i][j]].cnt;//횟수 기록
					}
				}
			}

			memset(ary, 0, sizeof ary);
			for(int i=0;i<mx_x;i++)
			sort(hsh[i], hsh[i] + 101, [](const pir &a, const pir &b)->bool {
				if (!a.idx) return false;//0의 경우 등장하지 않거나 0 값이므로 고려하지 않음
				if (!b.idx) return true;
				if (a.cnt != b.cnt)return a.cnt < b.cnt;//등장횟수 비교
				return a.idx < b.idx;//횟수가 같은 경우 수를 비교
			});

			int ty = 0;
			for (int i = 0; i < mx_x; i++) {
				int cur = 0;
				while (cur < 50 && hsh[i][cur].idx) {//결과를 저장
					ary[i][cur * 2] = hsh[i][cur].idx;
					ary[i][cur * 2 | 1] = hsh[i][cur].cnt;
					cur++;
				}
				ty = ty < cur ? cur : ty;
			}
			mx_y = ty*2;//변경된 열 길이 반영

		}
		else {//C연산
			for (int i = 0; i < mx_y; i++) {
				for (int j = 0; j < mx_x; j++) {
					if (ary[j][i]) {
						hsh[i][ary[j][i]].idx = ary[j][i];
						++hsh[i][ary[j][i]].cnt;
					}
				}
			}

			memset(ary, 0, sizeof ary);
			for (int i = 0; i < mx_y; i++)
				sort(hsh[i], hsh[i] + 101, [](const pir &a, const pir &b)->bool {
				if (!a.idx) return false;
				if (!b.idx) return true;
				if (a.cnt != b.cnt)return a.cnt < b.cnt;
				return a.idx < b.idx;
			});

			int tx = 0;
			for (int i = 0; i < mx_y; i++) {
				int cur = 0;
				while (cur < 50 && hsh[i][cur].idx) {
					ary[cur * 2][i] = hsh[i][cur].idx;
					ary[cur * 2 | 1][i] = hsh[i][cur].cnt;
					cur++;
				}
				tx = tx < cur ? cur : tx;
			}
			mx_x = tx*2;
		}

		t++;
	}
	printf("%d", t > 100 ? -1 : t);
}