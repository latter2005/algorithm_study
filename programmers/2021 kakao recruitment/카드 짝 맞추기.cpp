#include <vector>
#include <cstring>
#include <queue>
using namespace std;
 
typedef struct pir {
    int first, second, cost;
    pir(int f, int s, int c) :first(f), second(s), cost(c) {};
};
int dx[] = { 1, -1, 0, 0 },
dy[] = { 0, 0, 1, -1 };
int card_count, min_val = 0x7fffffff;
 
void dfs(vector<vector<int>> &arr, int x, int y, int cost, int current, int count) {//dfs
    //current : -1 = 가장 가까운 카트 찾기, 그외 = 해당 카드 쌍 찾기
    if (cost >= min_val) return;
    if (count == card_count) {
        if (cost < min_val)min_val = cost;
        return;
    }
 
    queue<pir> next;//bfs
    bool visited[4][4] = { 0 };
    next.emplace( x, y ,0 );
    while (!next.empty()) {
        auto &cur = next.front();
        int cx = cur.first, cy = cur.second, c_cost = cur.cost, i;
        next.pop();
        if (visited[cx][cy])continue;
        visited[cx][cy] = 1;
        if (arr[cx][cy]) {
            if (current == -1) {//카드를 찾으면 카드 맞추기
                int t = arr[cx][cy];
                arr[cx][cy] = 0;
                dfs(arr, cx, cy, cost + c_cost + 1, t, count);
                arr[cx][cy] = t;
            }
 
            else if (arr[cx][cy] == current) {//카드를 맞추면 새로운 카드 찾기
                arr[cx][cy] = 0;
                dfs(arr, cx, cy, cost + c_cost + 1, -1, count + 2);
                arr[cx][cy] = current;
            }
        }
        i = cx + 1;
        if (i < 4) {//상
            for (; i < 3 && !arr[i][cy]; i++);
            if (i != cx + 1 && !visited[i][cy])next.emplace(i, cy ,c_cost + 1 );
            if (!visited[cx + 1][cy])
                next.emplace(cx + 1, cy , c_cost + 1 );
        }
        i = cx - 1;
        if (i >= 0) {//하
            for (; i > 0 && !arr[i][cy]; i--);
            if (i != cx - 1 && !visited[i][cy])next.emplace(i, cy, c_cost + 1 );
            if (!visited[cx - 1][cy])
                next.emplace( cx - 1, cy , c_cost + 1 );
        }
        i = cy + 1;
        if (i < 4) {//우
            for (; i < 3 && !arr[cx][i]; i++);
            if (i != cy + 1 && !visited[cx][i])next.emplace( cx, i , c_cost + 1 );
            if (!visited[cx][cy + 1])
                next.emplace( cx, cy + 1 , c_cost + 1 );
        }
        i = cy - 1;
        if (i >= 0) {//좌
            for (; i > 0 && !arr[cx][i]; i--);
            if (i != cy - 1 && !visited[cx][i])next.emplace( cx, i , c_cost + 1 );
            if (!visited[cx][cy - 1])
                next.emplace( cx, cy - 1, c_cost + 1 );
        }
 
    }
 
}
int solution(vector<vector<int>> arr, int x, int y) {
    vector<pair<int, int>> next;
    for (auto &i : arr)
        for (auto &j : i)
            if (j)
                card_count++;
    dfs(arr, x, y, 0, -1, 0);
    return min_val;
}