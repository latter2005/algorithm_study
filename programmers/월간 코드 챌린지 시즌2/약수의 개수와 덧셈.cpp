#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
	int answer = 0;

	int visited[1001] = { 0 };

	for (int i = 1; i*i <= right; i++)
		visited[i*i] = 1;
	
	for (int i = left; i <= right; i++)
		answer += visited[i] ? -i : i;
	return answer;
}

int main() {
	solution(13, 17);
}