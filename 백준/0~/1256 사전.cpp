//https://latter2005.tistory.com/56
#include <cstdio>
 
long long nCr(int n, int r) {
    if (r > n - r) r = n - r;
    long long ans = 1;
    int i;
    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
        if (ans > 1000000000 || ans < 0)
            return -1;
    }
    return ans;
}
 
int main() {
    int n, r;
    long long k;
    scanf("%d%d%lld", &n, &r, &k);
    long long t = nCr(n + r, r);
 
    if (t == -1 || k <= t) {
        k--;
        for (; k; n--) {
            for (int j = r; j >= 0; j--) {
                long long t = nCr(n + j - 1, j);
                if (t == -1)
                    break;
                if (t <= k) {
                    k -= t;
                    r = j - 1;
                    printf("z");
                }
                else
                    break;
            }
            printf("a");
        }
        while (n--)
            printf("a");
        while (r--)
            printf("z");
    }
    else
        printf("-1");
}