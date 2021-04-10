#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int>gph_1[300000], gph_2[300000];
    priority_queue<int, vector<int>, greater<int>>pq;
    int d_1[300000] = { 0 }, d_2[300000] = { 0 }, val[300000];
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        gph_1[b].push_back(a);//역순
        gph_2[a].push_back(b);
        d_1[a]++;//역순 indegree = a
        d_2[b]++;
    }
    //최댓값
    for (int i = 0; i < k; i++)
        if (!d_1[i])
            pq.push(i);
    int cur = n - k - 1;
    while (!pq.empty()) {
        int t = pq.top();
        pq.pop();
        val[t] = ++cur;//n-k -> n-1
        for (int next : gph_1[t])
            if (!--d_1[next])
                pq.push(next);
    }
    //최솟값
    for (int i = 0; i < k; i++)
        if (!d_2[i])
            pq.push(i);
    cur = k;//k -> 0
    while (!pq.empty()) {
        int t = pq.top();
        pq.pop();
        val[t] -= --cur;
        for (int next : gph_2[t])
            if (!--d_2[next])
                pq.push(next);
    }
    auto fast_pow = [](int base, int power, int m) {//함수보다 람다식이 더 빠름
        long long res = 1, t = base % m;
        while (power > 0) {
            if (power & 1)
                res = res * t % m;
            power >>= 1;
            t = t * t % m;
        }
        return res;
    };
    long long res = 0;
    for (int i = 0; i < k; i++)
        res = (res + val[i] * fast_pow(n, i, 1000000007)) % 1000000007;
    cout << res;
 
}
