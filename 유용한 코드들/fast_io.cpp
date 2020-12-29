//c++

cin.tie(NULL);
ios::sync_with_stdio(false);


//윈도우
class fast_io {
public:
int next_int() {
	int x = 0;
	bool neg = false;
	register int c;
	c = getchar_unlocked();
	while (c != '-' && (c < 48 || c > 57))
		c = getchar_unlocked();
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return x;
}
};
fast_io fio;


//리눅스

#include <unistd.h>
namespace io {
    const signed IS = 1 << 13, OS = 1 << 20;
    char I[IS + 1], *J = I;
    //char O[OS], *K = O;
 
    inline void daer() { if (J >= I + IS - 64) { char*p = I; do*p++ = *J++; while (J != I + IS); p[read(0, p, I + IS - p)] = 0; J = I; } }
    template<int N = 10, typename T = int> inline T getu() { daer(); T x = 0; int k = 0; do x = x * 10 + *J - '0'; while (*++J >= '0'&&++k < N); ++J; return x; }
    template<int N = 10, typename T = int>inline  T geti() { daer(); bool e = *J == '-'; J += e; return(e ? -1 : 1)*getu<N, T>(); }
    /*inline void flush() { write(1, O, K - O); K = O; }
    template<int N = 10, typename T = int> inline void putu(T n) { char s[(N + 7) / 8 * 8], *p = s; int k = 0; do*p++ = n % 10 + 48; while ((n /= 10) && ++k < N); do*K++ = *--p; while (p != s); *K++ = 10; if (K >= O + OS - 64)flush(); }
    template<int N = 10, typename T = int> inline void puti(T n) { if (n < 0)*K++ = '-', n = -n; putu<N, T>(n); }*/
    struct f { f() { I[read(0, I, IS)] = 0; }~f() { /*flush();*/ } }flu;
};//출처 : https://cgiosy.github.io/posts/fast-io
using namespace io;


//nmap 사용

#include <sys/stat.h>
#include <sys/mman.h>

class fio {
  size_t rsize;
  unsigned char* rbuf;
  static const int wsize = 0xffff;
  unsigned char wbuf[wsize];
  int ridx, widx;

 public:
  fio() : ridx(0), widx(0) {
    struct stat rstat;
    fstat(0, &rstat);
    rsize = rstat.st_size;
    rbuf = (unsigned char*)mmap(0,rsize,PROT_READ,MAP_FILE|MAP_PRIVATE,0,0);
  }

  inline bool isBlank() {
    return
      rbuf[ridx] == '\n' || rbuf[ridx] == '\t' || rbuf[ridx] == '\r' ||
      rbuf[ridx] == '\f' || rbuf[ridx] == '\v' || rbuf[ridx] == ' ';
  }
  inline void consumeBlank() { while (isBlank()) ridx++; }

  inline int readInt(){
    int res = 0, flag = 0;
    consumeBlank();
    if (rbuf[ridx] == '-'){
      flag = 1;
      ridx++;
    }
    while (!isBlank() && ridx < rsize)
      res = 10 * res + rbuf[ridx++] - '0';
    return flag ? -res : res;
  }

  inline void flush() {
    fwrite(wbuf, 1, widx, stdout);
    widx = 0;
  }

  inline int intSize(int x) {
    int cnt = 1;
    x = (x > 0) ? x : -x;
    while( x /= 10 ) cnt++;
    return cnt;
  }

  inline void check(int n) { if (widx + n >= wsize) flush(); }
  inline void writeChar(char z) { check(1); wbuf[widx++] = z; }

  inline void writeInt(int x) {
    int sz = intSize(x);
    check(sz);
    if (x < 0) {
      writeChar('-');
      x = -x;
    }
    for (int i = 1; i <= sz; ++i) {
      wbuf[widx + sz - i] = x % 10 + '0';
      x /= 10;
    }
    widx += sz;
  }
};