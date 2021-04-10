//https://latter2005.tistory.com/34
#include <cstdio>
#include <vector>
#include <queue>
#include <sys/stat.h>
#include <sys/mman.h>
typedef struct data {
	int val, left, right;
	bool operator <(data &b)const {
		return val < b.val;
	}
}data;
//struct comp {
//	bool operator()(data a, data b) {
//		return a.val > b.val;
//	}
//};


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
			rbuf[ridx] == '\n' || rbuf[ridx] == '\t' || rbuf[ridx] == '\r' ||
			rbuf[ridx] == '\f' || rbuf[ridx] == '\v' || rbuf[ridx] == ' ';
	}
	inline void consumeBlank() { while (isBlank()) ridx++; }

	inline int readInt() {
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
int main() {
	fio fo;
	std::priority_queue<data, std::vector<data>, comp> pty_queue;
	int n = fo.readInt(), k = fo.readInt(), res = 0, p;
	data point[100001];
	scanf("%d%d", &n, &k);
	getchar();
	p = fo.readInt();
	for (int i = 1, tmp; i < n; i++) {
		tmp = fo.readInt();
		point[i].val = tmp - p;
		point[i].left = i - 1;
		point[i].right = i + 1;

		pty_queue.push(data{ point[i].val , i, i + 1 });
		p = tmp;
	}
	point[n] = { 0, n - 1, n + 1 };

	for (int i = 0; i < k;) {
		data t = pty_queue.top();
		pty_queue.pop();
		int cl = t.left, cr = t.right;
		if (cl >= 1 && cr <= n && cr == point[cl].right && cl == point[cr].left) {
			res += t.val;
			if (++i >= k) break;
			int nl = point[cl].left, nr = point[cr].right;
			t.left = nl; t.right = nr;
			point[nl].val = point[nl].val + point[cr].val - t.val;
			t.val = point[nl].val;
			pty_queue.push(t);
			point[nl].right = nr;
			point[nr].left = nl;

		}
	}
	printf("%d", res);
	return 0;
}
