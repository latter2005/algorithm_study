//풀이 : https://latter2005.tistory.com/22
#include <stdio.h>
#include <string.h>

typedef struct node {
	char x, y;
}node;
int main() {
	node que[400];
	short ary[20][20];
	char visited[20][20] = { 0 };
	char dx[] = { -1, 0, 0, 1 },
		dy[] = { 0, -1, 1, 0 },//상왼오하
		n, level = 2, count = 0;
	scanf("%hd\n", &n);
	for (short i = 0; i < n; i++) {
		for (short j = 0; j < n; j++) {
			scanf("%hd", &ary[i][j]);
			if (ary[i][j] == 9) {
				ary[i][j] = 0;
				que[0] = { i, j };
				visited[i][j] = 1;//초기 위치 설정
			}
		}
	}
	short left = 0, right = 1;//큐 인덱스
	short depth = 0, total = 0;//움직인 거리 depth
	while (left < right) {
		short cur_size = right - left;
		char tx = 21, ty = 21;
		while (cur_size--) {//같은 depth의 좌표들을 한번에 처리함
			auto &t = que[left++];
			char cx = t.x, cy = t.y;
			for (short d = 0; d < 4; d++) {
				char nx = cx + dx[d], ny = cy + dy[d];
				if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;//배열 밖
				if (visited[nx][ny] || ary[nx][ny] > level) continue;//탐색 하였거나 먹을 수 없는 물고기
				else if (!ary[nx][ny] || ary[nx][ny] == level) {//먹지 못하지만 지나갈 수 있는 물고기, 빈칸
					que[right++] = { nx, ny };
					visited[nx][ny] = 1;
				}
				else if (ary[nx][ny] < level) {//먹을 수 있는 물고기
					if (tx > nx || (tx == nx && ty > ny)) {//상, 왼 순서로 좌표 우선순위 결정 
						tx = nx;
						ty = ny;
					}
				}
			}
		}
		depth++;//이동횟수
		if (tx != 21 && ty != 21) {//먹을 물고기가 결정됨
			ary[tx][ty] = 0;
			left = 0; right = 1;
			que[0] = { tx, ty };
			memset(visited, 0, sizeof(visited));
			total += depth;
			depth = 0;//초기화
			if (++count == level) {//레벨 업
				++level;
				count = 0;
			}
		}
	}
	printf("%hd", total);
}
/*
4
4 3 2 1
0 0 0 0
0 0 9 0
1 2 3 4
*/