#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> a) {
	int answer = 0;
	vector<vector<int>> graph(a.size());
	for (int i = 0; i < a.size(); i++)
		graph[a[i]].push_back(i);//그래프 생성

	for (auto &t : graph) {
		if (!t.size())continue;//간선이 없는 수
		if (t.size() < answer)continue;//간선의 개수가 최대 스타 수열의 길이보다 작은 경우
		if (t.size() == 1) {//최대 스타수열의 길이가 1인 경우 
			answer = (a.size() > 1 && !answer) ? 1 : answer;
			continue;
		}

		int cnt = 0;
		//처음위치
		bool left_possible;//전 단계에서 오른쪽에 수를 둠 = 다음 단계에서 고려해야함
		if (t[0])
			left_possible = true, cnt++;//왼쪽에 둘 수 있는 경우
		else
			left_possible = false;//오른쪽 체크

		//중간위치
		for (int i = 1; i < t.size() - 1; i++) {
			if (t[i] - t[i - 1] == 1) {//붙어있는 경우
				left_possible = false;
			}
			else if (t[i] - t[i - 1] == 2) {//1개의 공간이 있는 경우
				cnt++;
			}
			else {//2개 이상의 공간이 있는 경우
				cnt++;
				if (!left_possible)cnt++;//전 단계의 체크 해 둔것을 count로 변환
				left_possible = true;
			}
		}

		//마지막 위치
		if (t.back() - t[t.size() - 2] == 1) {//붙어있는 경우
			if (t.back() < a.size() - 1)cnt++;//오른쪽에 둘 수 있다면
		}	
		else if (t.back() - t[t.size() - 2] == 2) {//1개의 공간이 있는 경우
			if (left_possible)cnt++;
			else if (t.back() < a.size() - 1)cnt++;
		}
		else {
			if (left_possible)cnt++;
			else cnt += 2;
		}
		
		answer = cnt > answer ? cnt : answer;
	}

	return answer<<1;
}

int main() {
	vector<int> a = { 1,0,1,0 };
	cout << solution(a);
}
/*
{0}	0
{5,2,3,3,5,3}	4
{0,3,3,0,7,2,0,2,2,0}	8
*/