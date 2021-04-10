#include <cstdio>

int main() {
	char str[1000001];
	register int i, dif = 'a' - 'A';
	int c[123] = {};
	fread(str, 1, sizeof(str), stdin);
	for (char *p = str; *p; p++)
		++c[*p];
	char m = 0, dup = 0;
	for (i = 'A'; i <= 'Z'; i++) {
		c[i] += c[i + dif];
		if (c[i] > c[m]) {
			m = i;
			dup = 0;
		}
		else if (c[i] == c[m])
			dup = 1;
	}
	if (dup)
		putchar('?');
	else
		putchar(m);
}