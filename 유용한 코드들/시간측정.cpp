
#include <ctime>
#include <Windows.h>
//다음 두줄을 복사해서 쓰시면 됩니다.
// 이 매크로는 Win32 함수를 이용하여 nano second까지 측정할 수 있습니다.
#define CHECK_TIME_START  __int64 freq, start, end; BOOL condition; if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))  QueryPerformanceCounter((_LARGE_INTEGER*)&start);
// a는 float type  milli second이고 b가 FALSE일때는 에러입니다
#define CHECK_TIME_END(a,b) if (condition) {QueryPerformanceCounter((_LARGE_INTEGER*)&end);  a=(float)((double)(end - start)/freq*1000); b=TRUE;}                        else b=FALSE;


	double time;
	bool b;
	CHECK_TIME_START
		

	CHECK_TIME_END(time, b);
	printf("time : %lf\n", time);


	double time;
	bool b;
	__int64 freq, start, end; 
	BOOL condition; 
	if (condition = QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))  
		QueryPerformanceCounter((_LARGE_INTEGER*)&start);
	
	if (condition) {
		QueryPerformanceCounter((_LARGE_INTEGER*)&end);  
		time=(float)((double)(end - start)/freq*1000); 
		printf("time : %lf\n", time);
	}