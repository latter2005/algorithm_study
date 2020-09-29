#include <cstdio>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <vector>
using namespace std;
int solve(pair<int, int> t) {
	return t.first + t.second;

}
int solve2(pair<int, int> &t) {
	return t.first + t.second;
}
int solve3(pair<int, int> *t) {
	return t->first + t->second;
}
int main() {
	int x = 0;
	vector<pair<int, int>> vec(5000000, { 1,1 });

	double time;
	bool b;
	__int64 freq, start, end;
	BOOL condition;
	if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))
		QueryPerformanceCounter((_LARGE_INTEGER*)&start);
	for (auto &t : vec)
		x += solve(t);
	if (condition) {
		QueryPerformanceCounter((_LARGE_INTEGER*)&end);
		time = (float)((double)(end - start) / freq * 1000);
		printf("time : %lf\n", time);
	}//copy
	x = 0;
	if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))
		QueryPerformanceCounter((_LARGE_INTEGER*)&start);
	for (auto &t : vec)
		x += solve2(t);
	if (condition) {
		QueryPerformanceCounter((_LARGE_INTEGER*)&end);
		time = (float)((double)(end - start) / freq * 1000);
		printf("time : %lf\n", time);
	}//reference
	x = 0;
	if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))
		QueryPerformanceCounter((_LARGE_INTEGER*)&start);
	for (auto &t : vec)
		x += solve3(&t);
	if (condition) {
		QueryPerformanceCounter((_LARGE_INTEGER*)&end);
		time = (float)((double)(end - start) / freq * 1000);
		printf("time : %lf\n", time);
	}//pointer
}

/*
time : 100.064796
time : 92.421700
time : 93.090797
평균적으로 참조자, 포인터가 복사보다 빠름
*/