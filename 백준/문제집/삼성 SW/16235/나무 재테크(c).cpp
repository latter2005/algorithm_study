﻿#include <stdio.h>
typedef struct tile {
	short level[2], max_level;
	short resource, s2d2;
}tile;
tile tree[10][10];
short N;
char dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 },
dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void spring_summer_winter() {
	//spring
	for (char i = 0; i < N; i++)
		for (char j = 0; j < N; j++) {
			short total_add = tree[i][j].s2d2;
			if (tree[i][j].max_level) {
				char new_max = 0;
				for (char t = 1; t <= tree[i][j].max_level; t++) {
					if (tree[i][j].level[t]) {
						if (t * tree[i][j].level[t] <= tree[i][j].resource) {
							tree[i][j].resource -= t * tree[i][j].level[t];
							new_max = t;
						}
						else {
							short alive = tree[i][j].resource / t, dead = tree[i][j].level[t] - alive;
							if (alive) {
								tree[i][j].level[t] = alive;
								tree[i][j].resource -= alive * t;
								new_max = t;
							}
							//summer
							total_add += dead * (t >> 1);
							for (t++; t <= tree[i][j].max_level; t++)
								if (tree[i][j].level[t])
									total_add += (t >> 1) *  tree[i][j].level[t];
							break;
						}
					}
				}
				tree[i][j].max_level = new_max;
				if (new_max)
					for (short t = tree[i][j].max_level++; t >= 1; t--)
						tree[i][j].level[t + 1] = tree[i][j].level[t];
				tree[i][j].level[1] = 0;

			}
			tree[i][j].resource += total_add; //winter
		}
	for (char i = 0; i < N; i++)
		for (char j = 0; j < N; j++) {
			short total_count = 0;
			for (short t = 5; t <= tree[i][j].max_level; t += 5) {
				if (tree[i][j].level[t])
					total_count += tree[i][j].level[t];
			}
			if (total_count) {
				for (char d = 0; d < 8; d++) {
					short nx = dx[d] + i, ny = dy[d] + j;
					if (0 <= nx && nx < N && 0 <= ny && ny < N) {
						tree[nx][ny].level[1] += total_count;
						if (!tree[nx][ny].max_level)
							tree[nx][ny].max_level = 1;
					}
				}
			}
		}
}



int main() {
	short M, K;
	scanf("%hd%hd%hd", &N, &M, &K);

	for (char i = 0; i < N; i++)
		for (char j = 0; j < N; j++) {
			scanf("%hd", &tree[i][j].s2d2);
			tree[i][j].resource = 5;
		}
	short x, y, z;
	for (char i = 0; i < M; i++) {
		scanf("%hd%hd%hd", &x, &y, &z);
		tree[--x][--y].level[z] = 1;
		tree[x][y].max_level = z;
	}

	while (K--) {
		spring_summer_winter();
	}
	short cnt = 0;
	for (char i = 0; i < N; i++)
		for (char j = 0; j < N; j++)
			for (char t = 1; t <= tree[i][j].max_level; t++)
				if (tree[i][j].level[t])
					cnt += tree[i][j].level[t];
	printf("%hd", cnt);
}

