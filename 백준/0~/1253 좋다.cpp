#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int ary[2000];
	int n, res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);

	sort(ary, ary + n);
	for (int i = 0; i < n; i++) {
		int left = 0, right = n - 1;
		while (left < right) {
			if (ary[i] > ary[left] + ary[right]) left++;
			else if (ary[i] < ary[left] + ary[right])right--;
			else {
				if (left == i) left++;
				else if (right == i) right--;
				else {
					++res;
					break;
				}
			}
		}
	}
	printf("%d", res);
}