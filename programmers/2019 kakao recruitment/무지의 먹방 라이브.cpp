#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
	int n = food_times.size(), len = n;

	//loop : 루프 횟수, move : 남은 움직임 횟수
	long long loop = k / n, move = k % n;
	while (1) {
		for (int i = 0; i < n; i++) {
			if (!food_times[i])continue;//visited
			if (food_times[i] <= loop) {//루프 횟수보다 원소가 작으면
				move += loop - food_times[i];//차이만큼 추가 움직임 필요
				food_times[i] = 0;//visited
				len--;//남은 음식의 종류 --
			}
		}
		if (!len)//남은 음식이 없으면
			return -1;
		if (move >= len) {//움직임 횟수가 남은 음식의 종류보다 많으면 추가 루프 발생
			loop += move / len;
			move %= len;
		}
		else break;
	}
	for (int i = 0; i < n; i++) {//음식 위치 찾기
		if (!food_times[i])continue;
		if (!move)
			return i + 1;
		move--;
	}
	return -1;
}

int main() {
	vector<int> t = { 5, 6, 7, 8, 9, 10 };
	int i = solution(t, 40);
	cout << i;
}