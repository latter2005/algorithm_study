#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dp[300001][2];//1참가, 0 불참
vector<int> *sale;
vector<int> edge[300001];
void dfs(int cur) {
    dp[cur][1] = (*sale)[cur - 1];
 
    if (!edge[cur].empty()) {//팀장인 경우 자식노드가 있음을 이용
        for (auto next : edge[cur]) 
            dfs(next);
        
        int min_val = 0x7fffffff;
        for (auto next : edge[cur]) {
            if (dp[next][0] < dp[next][1]) {
                dp[cur][0] += dp[next][0];
                dp[cur][1] += dp[next][0];
                min_val = min_val > dp[next][1] - dp[next][0]
                    ? dp[next][1] - dp[next][0] : min_val;//참가 여부에 따른 차이의 최소비용을 구함
            }
            else {
                dp[cur][0] += dp[next][1];
                dp[cur][1] += dp[next][1];
                min_val = 0;//자식노드에 참가한 인원이 생기면 0으로 변경
            }
        }
        if (min_val != 0x7fffffff)//모든 자식노드가 참가하지 않았다면 최소비용을 더해 강제로 하나의 팀을 참여시킴
            dp[cur][0] += min_val;
    }
        
}
int solution(vector<int> sales, vector<vector<int>> links) {
    sale = &sales;
    for (auto &t : links) 
        edge[t[0]].push_back(t[1]);
    
    dfs(1);
 
    return dp[1][0] > dp[1][1] ? dp[1][1] : dp[1][0];
}
int main() {
    vector<int> s = { 14, 17, 15, 18, 19, 14, 13, 16, 28, 17 };
    vector<vector<int>>    l = { {10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2} };
 
    cout << solution(s, l);
 
}