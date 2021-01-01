//리눅스
#include <unistd.h>
namespace fio 
{
	const int CHUNK_SIZE = 1 << 20;
	static char inBuffer[CHUNK_SIZE];
 
    static char* rCurPos = inBuffer + CHUNK_SIZE;
 
	static inline char read()
	{
	    if(rCurPos == inBuffer + CHUNK_SIZE) {
	    	syscall(0x00, 0, inBuffer, sizeof(inBuffer));
	        rCurPos = inBuffer;
	    }
	    return *rCurPos++;
	}

	static inline long long readInt() 
	{
		bool neg = false;
	    register char c;
	    register long long val = 0;
	    while (((c=read()) < '0' || c > '9') && c != '-');
	    if (c == '-') {
	        neg = true;
	        c = read();
	    }
	    val = c - '0';
	    while ('0' <= (c=read()) && c <= '9')
	        val = (val << 1) + (val << 3) + (c - '0');
	    if (neg) val = -val;
	    return val;
	}
}
