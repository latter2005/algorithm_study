//https://latter2005.tistory.com/29
#include <cstdio>
#include <algorithm>
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
		rbuf = (unsigned char*)mmap(0, rsize, PROT_READ, MAP_FILE | MAP_PRIVATE, 0, 0);
	}

	inline bool isBlank() {
		return
			!(rbuf[ridx] != '\n' && rbuf[ridx] != '\t' && rbuf[ridx] != '\r' &&
			rbuf[ridx] != '\f' && rbuf[ridx] != '\v' && rbuf[ridx] != ' ');
	}
	inline void consumeBlank() { while (isBlank()) ridx++; }

	int readInt() {
		int res = 0, flag = 0;
		consumeBlank();
		if (rbuf[ridx] == '-') {
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
		while (x /= 10) cnt++;
		return cnt;
	}

	inline void check(int n) { if (widx + n >= wsize) flush(); }
	inline void writeChar(char z) { check(1); wbuf[widx++] = z; }

	void writeInt(int x) {
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
using namespace std;

int main() {
	fio fo;
	int tree[200002];
	int n = fo.readInt(), m = fo.readInt();
	for (int i = 0; i < n; i++)
		tree[n + i] = fo.readInt();
	for (int i = n - 1; i > 0; i--)
		tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
	while (m--) {
		int s = fo.readInt(), e = fo.readInt(), mn = 0x7fffffff;
		for (s += n - 1, e += n; s < e; s >>= 1, e >>= 1) {
			if (s & 1) mn = min(tree[s++], mn);
			if (e & 1) mn = min(tree[--e], mn);
		}
		fo.writeInt(mn);
		fo.writeChar('\n');
	}
	fo.flush();
}
