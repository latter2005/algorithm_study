class fast_io {
public:
	int next_int() {
		int x = 0;
		bool neg = false;
		register int c;
		c = _getchar_nolock();
		if (c == '-') {
			neg = true;
			c = getchar();
		}
		for (; (c > 47 && c < 58); c = _getchar_nolock())
			x = (x << 1) + (x << 3) + c - 48;
		if (neg)
			x *= -1;
		return x;
	}
};
fast_io fio;
