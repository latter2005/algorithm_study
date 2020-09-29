#include <cstdio>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <vector>
using namespace std;

int main(){
	int x = 0;
	vector<int> vec(50000000, 1);

	double time;
	bool b;
	__int64 freq, start, end; 
	BOOL condition; 
	if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))  
		QueryPerformanceCounter((_LARGE_INTEGER*)&start);
	for (auto t : vec)
		x += t;
	if (condition) {
		QueryPerformanceCounter((_LARGE_INTEGER*)&end);
		time = (float)((double)(end - start) / freq * 1000);
		printf("time : %lf\n", time);
	}//copy
	x = 0;
	if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))
		QueryPerformanceCounter((_LARGE_INTEGER*)&start);
	for (auto &t : vec)
		x += t;
	if (condition) {
		QueryPerformanceCounter((_LARGE_INTEGER*)&end);
		time = (float)((double)(end - start) / freq * 1000);
		printf("time : %lf\n", time);
	}//reference
	
}

/*
time : 99.631798
time : 102.600800


*/