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