// https://codeforces.com/group/fXPc2tNEPp/contest/359387/problem/08A
#include "bits/stdc++.h"
using namespace std;

int s, n, m, qq, x1, x2, y1, y2, cur;
vector<vector<int>> a, dp;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int i, int j, int p, int q) {
    return (i >= 1 && j >= 1 && i <= n && j <= m && a[i][j] != a[p][q] && dp[i][j] == -1);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> s >> n >> m >> qq;
    a.assign(n + 1, vector<int>(m + 1));
    dp.assign(n + 1, vector<int>(m + 1, -1));
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> a[i][j];
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        if(dp[i][j] != -1) continue;
        dp[i][j] = cur;

        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(int k = 0; k < 4; ++k) {
                int newX = x + dx[k], newY = y + dy[k];
                if(valid(newX, newY, x, y)) {
                    dp[newX][newY] = cur; 
                    q.push({newX, newY});
                }
            }
        }
        cur++;
    }

    while(qq--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (dp[x1][y1] == dp[x2][y2]) << "\n";
    }
}
    
