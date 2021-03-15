#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int SZ = 1 << 20;
char read_buf[SZ], write_buf[SZ];

namespace IO { //reference: https://blog.naver.com/jinhan814/222266396476
    int read_idx, next_idx, write_idx;
	inline bool is_blank(char c) { return c == ' ' || c == '\n'; }
	inline bool is_end(char c) { return c == '\0'; }
	inline char _readChar() {
		if (read_idx == next_idx) {
			next_idx = fread(read_buf, sizeof(char), SZ, stdin);
			if (next_idx == 0) return 0;
			read_idx = 0;
		}
		return read_buf[read_idx++];
	}
	inline char readChar() {
		char ret = _readChar();
		while (is_blank(ret)) ret = _readChar();
		return ret;
	}
	template<typename T>
	inline T _readInt() {
		T ret = 0;
		char cur = _readChar();
		bool flag = 0;
		while (is_blank(cur)) cur = _readChar();
		if (cur == '-') flag = 1, cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret = 10 * ret + cur - '0', cur = _readChar();
		return flag ? -ret : ret;
	}
	inline int readInt() { return _readInt<int>(); }
	inline long long readLL() { return _readInt<long long>(); }
	inline string readString() {
		string ret;
		char cur = _readChar();
		while (is_blank(cur)) cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret.push_back(cur), cur = _readChar();
		return ret;
	}
	inline double readDouble() {
		string ret = readString();
		return stod(ret);
	}
	template<typename T>
	inline int getSize(T n) {
		int ret = 1;
		if (n < 0) n = -n;
		while (n >= 10) ret++, n /= 10;
		return ret;
	}
	inline void bflush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	inline void writeChar(char c) {
		if (write_idx == SZ) bflush();
		write_buf[write_idx++] = c;
	}
	inline void newLine() { writeChar('\n'); }
	template<typename T>
	inline void _writeInt(T n) {
		int sz = getSize(n);
		if (write_idx + sz >= SZ) bflush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz - 1; i >= 0; i--) write_buf[write_idx + i] = n % 10 + '0', n /= 10;
		write_idx += sz;
	}
	inline void writeInt(int n) { _writeInt<int>(n); }
	inline void writeLL(long long n) { _writeInt<long long>(n); }
	inline void writeString(string s) { for (auto& c : s) writeChar(c); }
	inline void writeDouble(double d) { writeString(to_string(d)); }
}
using namespace IO;

#undef fastio
#define fastio 1
#define cin in
#define cout out

struct INPUT{} in;
INPUT& operator>> (INPUT& in, char& i) { i = readChar(); return in; }
INPUT& operator>> (INPUT& in, int& i) { i = readInt(); return in; }
INPUT& operator>> (INPUT& in, long long& i) { i = readLL(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = readString(); return in; }
INPUT& operator>> (INPUT& in, double& i) { i = readDouble(); return in; }

struct OUTPUT{ ~OUTPUT() { bflush(); } } out;
OUTPUT& operator<< (OUTPUT& out, char i) { writeChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, int i) { writeInt(i); return out; }
OUTPUT& operator<< (OUTPUT& out, long long i) { writeLL(i); return out; }
OUTPUT& operator<< (OUTPUT& out, size_t i) { writeInt(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { writeString(i); return out; }
OUTPUT& operator<< (OUTPUT& out, double i) { writeDouble(i); return out; }

int main() {
	fastio;
	char c; int n; long long m; string s; double d;
	cin >> c >> n >> m >> s >> d;
	cout << c << ' ' << n << ' ' << m << ' ' << s << ' ' << d << '\n';
}
[출처] 빠른 입출력 구현 코드 by jinhan814|작성자 박진한