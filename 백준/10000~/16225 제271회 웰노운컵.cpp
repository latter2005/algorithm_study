#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef struct pir {
    int a, b;
}pir;
using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
 
    priority_queue <int> que;
    int n;
    pir ary[200000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ary[i].a;
    for (int i = 0; i < n; i++)
        cin >> ary[i].b;
    sort(ary, ary + n, [](const pir&x, const pir&y)->bool {//정렬
        return x.b < y.b;
    });
    long long ans = ary[0].a;
 
    for (int i = 1; i < n - 1; i += 2) {
        que.push(ary[i].a);
        que.push(ary[i + 1].a);//2칸 삽입
        ans += que.top();//최댓값 선택
        que.pop();
    }
    cout << ans;
}