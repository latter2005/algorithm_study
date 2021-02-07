#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
typedef struct vtx {
    int dp;
    vector<int>edge;
}vtx;
vtx gph[100001];
int dfs(int i, int prev) {
    vtx &cur = gph[i];
    cur.dp = 1;
    for (auto next : cur.edge)
        if (next != prev)
            cur.dp += dfs(next, i);
    return cur.dp;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, r, q;
    cin >> n >> r >> q;
 
 
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        gph[a].edge.push_back(b);
        gph[b].edge.push_back(a);
    }
 
    dfs(r, 0);
    while (q--) {
        int u;
        cin >> u;
        cout << gph[u].dp << '\n';
    }
}