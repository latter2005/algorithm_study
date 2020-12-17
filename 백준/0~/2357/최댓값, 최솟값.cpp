//https://latter2005.tistory.com/31
#include <cstdio>
#include <algorithm>
#include <sys/stat.h>
#include <sys/mman.h>

class fio {
	size_t rsize;
	unsigned char* rbuf;
	static const int wsize = 0x7eeee;
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
typedef struct node {
	int min, max;
}node;
int main() {
	fio fo;
	node min_max_tree[200002];
	int n = fo.readInt(), m = fo.readInt();
	;
	for (int i = 0; i < n; i++)
		min_max_tree[n + i].max = min_max_tree[n + i].min = fo.readInt();

	for (int i = n - 1; i > 0; i--) {
		min_max_tree[i].min = min(min_max_tree[i << 1].min, min_max_tree[i << 1 | 1].min);
		min_max_tree[i].max = max(min_max_tree[i << 1].max, min_max_tree[i << 1 | 1].max);
	}
	while (m--) {
		int s = fo.readInt(), e = fo.readInt(), min_val = 0x7fffffff, max_val = 0x80000000;
		for (s += n - 1, e += n; s < e; s >>= 1, e >>= 1) {
			if (s & 1) {
				min_val = min(min_max_tree[s].min, min_val);
				max_val = max(min_max_tree[s++].max, max_val);
			}
			if (e & 1) {
				min_val = min(min_max_tree[--e].min, min_val);
				max_val = max(min_max_tree[e].max, max_val);
			}
		}
		fo.writeInt(min_val);
		fo.writeChar(' ');
		fo.writeInt(max_val);
		fo.writeChar('\n');
	}
	fo.flush();
}