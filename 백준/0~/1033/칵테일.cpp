#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
typedef struct vertex {
    int val;
    vector<int>edge;
}vertex;
int n;
vertex vtx[10];
bool visited[10];
long gcd(long a, long b) {//최대 공약수, 최소 공배수 = a * b / gcd
    long r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void dfs(int cur, int val) {
    visited[cur] = true;
    vtx[cur].val *= val;//비율 반영
 
    for (auto next : vtx[cur].edge)
        if (!visited[next])
            dfs(next, val);
}
int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, p, q;
        scanf("%d%d%d%d", &a, &b, &p, &q);
        if (!vtx[a].val)
            vtx[a].val = 1;
        if (!vtx[b].val)
            vtx[b].val = 1;//처음 방문한 경우
 
        int g = gcd(vtx[a].val, vtx[b].val);
        int a_mod = vtx[b].val / g * p, b_mod = vtx[a].val / g * q;//곱할 값 계산
        g = gcd(a_mod, b_mod);
        memset(visited, 0, sizeof visited);
        dfs(a, a_mod / g);//전체 반영
        dfs(b, b_mod / g);
 
        vtx[a].edge.push_back(b);//연결
        vtx[b].edge.push_back(a);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", vtx[i].val);
}
 