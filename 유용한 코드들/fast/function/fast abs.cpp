#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <Windows.h>
#define MAX 4000000
#define bit_abs(x) x&0x80000000 ? -(x) : x
#define bit_fabs(x) (*reinterpret_cast<std::uint64_t*>(&x)) &= 0x7fffffffffffffff
using namespace std;
template<typename T = int>
void use_if(T ary[]) {
	for (int i = 0; i < MAX; i++) {
		if (ary[i] < 0)
			ary[i] = -ary[i];
	}
}
template<typename T = int>
void use_bitop(T ary[]) {
	for (int i = 0; i < MAX; i++)
		ary[i] = bit_abs(ary[i]);
}
template<typename T = int>
void use_bitif(T ary[]) {
	for (int i = 0; i < MAX; i++)
		if (ary[i] & 0x80000000)
		ary[i] = -ary[i];
}
template<typename T = int>
void use_abs(T ary[]) {
	for (int i = 0; i < MAX; i++)
		ary[i] = abs(ary[i]);
}
template<typename T = double>
void use_fabs(T ary[]) {
	for (int i = 0; i < MAX; i++)
		ary[i] = fabs(ary[i]);
}
template<typename T = double>
void use_bit_fabs(T ary[]) {
	for (int i = 0; i < MAX; i++)
		bit_fabs(ary[i]);
}
template<typename T, typename F>
void query(T ary[], F f, const char *s) {
	T tmp[MAX];
	memcpy(tmp, ary, sizeof ary);
	double time;
	bool b;
	__int64 freq, start, end;
	BOOL condition;
	if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))
		QueryPerformanceCounter((_LARGE_INTEGER*)&start);

	f(tmp);

	if (condition) {
		QueryPerformanceCounter((_LARGE_INTEGER*)&end);
		time = (float)((double)(end - start) / freq * 1000);
		printf("use %s => time : %lf\n", s, time);
	}
}
int main() {
	
	mt19937 gen(12345);
	
	/*uniform_int_distribution<int> dist(-0x7fffffff, 0x7fffffff);
	int ary[MAX], tmp[MAX];
	for (int i = 0; i < MAX; i++) {
		ary[i] = dist(gen);
	}
	
	
	query(ary, &use_bitop<int>, "bit");
	query(ary, &use_bitif<int>, "bitif");
	query(ary, &use_if<int>, "if");
	query(ary, &use_abs<int>, "abs");*/
	
	
	uniform_real_distribution<double>dist(-0x7fffffff, 0x7fffffff);
	double ary[MAX], tmp[MAX];
	for (int i = 0; i < MAX; i++) {
		ary[i] = dist(gen);
	}
	query(ary, &use_if<double>, "if");
	query(ary, &use_bit_fabs<double>, "bit");
	query(ary, &use_fabs<double>, "fabs");
	
}
