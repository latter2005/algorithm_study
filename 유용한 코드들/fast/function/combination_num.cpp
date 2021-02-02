long long nCr(int n, int r) {
    if (r > n - r) r = n - r;
    long long ans = 1;
    int i;
    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
        //if (ans > 1000000000 || ans < 0)
           // return -1;
    }
    return ans;
}