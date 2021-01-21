#include <cstdio>

void upper() {
	int stack[] = { 1, 3, 5, 7, 9, 11, 13}, top = sizeof(stack)/4 - 1;
	int left = 0, right = top, mid, t = 7;
	while (left < right) {
		mid = (right + left) >> 1;
		if (t < stack[mid]) right = mid;
		else if (t != stack[mid]) left = mid + 1;
		else { right = mid; break; }
	}
	printf("%d", right);
}
void lower() {
	int stack[] = { 1, 3, 5, 7, 9, 11, 13 }, top = sizeof(stack) / 4 - 1;
	int left = 0, right = top, mid, t = 7;
	while (left < right) {
		mid = (right + left + 1) >> 1;
		if (t < stack[mid]) right = mid - 1;
		else if (t != stack[mid]) left = mid;
		else { left = mid; break; }
	}
	printf("%d", left);
}
int main() {
	//upper();
	lower();
}