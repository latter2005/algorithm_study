#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct node {
    int x, y;
    bool operator<(const node &b) const {
        return x > b.x;
    }
}node;
int main() {
    node ary[100000];
    int n, d, max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < y)
            ary[i] = { x, y };
        else
            ary[i] = { y, x };
    }
    scanf("%d", &d);
    sort(ary, ary + n);
    priority_queue<int, vector<int>, less<int>> que;
    for (int i = 0; i < n; i++) {
        que.push(ary[i].y);
        while (!que.empty() && ary[i].x + d < que.top())que.pop();
        max = que.size() > max ? que.size() : max;
    }
 
 
    printf("%d", max);
}
