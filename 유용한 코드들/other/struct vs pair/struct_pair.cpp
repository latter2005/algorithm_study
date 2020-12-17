//https://latter2005.tistory.com/30
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <Windows.h>
using namespace std;
#define MAX_SIZE 1000000
typedef struct node {
	int first, second;
	bool operator < (const node &b) const {
		if (first != b.second) return first < b.first;
		return second < b.second;
	}
}node;


void use_struct(node ary[], int data_1[], int data_2[]) {
	double time;
	bool b;
	__int64 freq, start, end;
	BOOL condition;
	if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))
		QueryPerformanceCounter((_LARGE_INTEGER*)&start);
	//
	for (int i = 0; i < MAX_SIZE; i++) {
		ary[i].first = data_1[i];
		ary[i].second = data_2[i];
	}
	sort(ary, ary + MAX_SIZE);
	//
	if (condition) {
		QueryPerformanceCounter((_LARGE_INTEGER*)&end);
		time = (float)((double)(end - start) / freq * 1000);
		printf("struct time : %lf\n", time);
	}
}
bool comp (pair<int, int> &a, pair<int,int> &b) {
	if (a.first != b.second) return a.first < b.first;
	return a.second < b.second;
}
void use_pair(pair<int, int> ary[], int data_1[], int data_2[]) {
	double time;
	bool b;
	__int64 freq, start, end;
	BOOL condition;
	if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))
		QueryPerformanceCounter((_LARGE_INTEGER*)&start);
	//
	for (int i = 0; i < MAX_SIZE; i++) {
		ary[i].first = data_1[i];
		ary[i].second = data_2[i];
	}
	sort(ary, ary + MAX_SIZE, comp);
	//
	if (condition) {
		QueryPerformanceCounter((_LARGE_INTEGER*)&end);
		time = (float)((double)(end - start) / freq * 1000);
		printf("pair time : %lf\n", time);
	}
}

int main() {
	int data_1[MAX_SIZE], data_2[MAX_SIZE];

	node st_ary[MAX_SIZE];
	pair<int, int> pr_ary[MAX_SIZE];

	mt19937 gen(1111);
	uniform_int_distribution<int> dis(0x80000000, 0x7fffffff);
	for (int i = 0; i < MAX_SIZE; i++) {
		data_1[i] = dis(gen);
		data_2[i] = dis(gen);
	}
	
	use_struct(st_ary, data_1, data_2);
	use_pair(pr_ary, data_1, data_2);
}