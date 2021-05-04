#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int ary[5000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);

	sort(ary, ary + n);

	int ml, mm, mr;
	long long mval = 1e9 * 3, t, at;

	for (int left = 0; mval && left < n - 2; left++) {
		for (int mid = left + 1, right = n - 1; mid != right;) {
			t = (long long)ary[left] + ary[mid] + ary[right];
			at = t > 0 ? t : -t;
			if (at < mval) {
				mval = at;
				ml = left, mm = mid, mr = right;
			}
			if (t > 0)--right;
			else if (t) ++mid;
			else break;
		}
	}
	printf("%d %d %d", ary[ml], ary[mm], ary[mr]);
}