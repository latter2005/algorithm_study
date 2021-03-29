#include <cstdio>
#include <cstring>

int main() {
	char ary[101];
	int visited[100] = { 0 };

	scanf("%s", ary);
	int n = strlen(ary);

	for (int i = 0; i < n; i++) {
		int j = n - 1;
		while (visited[j])--j;//여러 구간 중 뒤의 구간부터 탐색

		int mn = j--;//최솟값 찾기

		while (j >= 0 && !visited[j]) {
			mn = ary[mn] >= ary[j] ? j : mn;//등호를 통해 예외 처리
			--j;
		}
		visited[mn] = 1;//최솟값 선택

		for (int j = 0; j < n; j++)//방문한 문자 출력
			if (visited[j])
				putc(ary[j], stdout);
		putc('\n', stdout);
	}

}