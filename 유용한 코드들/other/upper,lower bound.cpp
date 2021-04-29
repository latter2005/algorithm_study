#include <cstdio>

int upper(int ary[], int left, int right, int val) {
	if (ary[right] <= val) return right + 1;
	if (val < ary[left]) return left;
	int mid;
	while (left < right) {
		mid = (right + left) >> 1;
		if (val < ary[mid]) right = mid;
		else left = mid + 1;
	}
	return right;
}
int lower(int ary[], int left, int right, int val) {
	if (ary[right] <= val) return right;
	if (val < ary[left]) return left - 1;
	int mid;
	while (left < right) {
		mid = (right + left) >> 1;
		if (val <= ary[mid]) right = mid;
		else left = mid + 1;
	}
	return right;
}

int main() {
	int p[] = { 50, 50, 50, 51, 101 };
	printf("%d\n", upper(p, 0, 4, 100));
	printf("%d\n", lower(p, 0, 4, 102));
}