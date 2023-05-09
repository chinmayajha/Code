#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, m;
bool invalid(int i, int j) {
    return !(i < n && i >= 0 && j < m && j >= 0);
}

int dfs(int i, int j, vector<vector<int>>& a, vector<vector<int>>& vis) {
    if(invalid(i, j) || vis[i][j]) return 0;
    vis[i][j] = 1;
    int cost = a[i][j];
    cost += (dfs(i + 1, j, a, vis));
    cost += (dfs(i, j + 1, a, vis));
    cost += (dfs(i - 1, j, a, vis));
    cost += (dfs(i, j - 1, a, vis));
    return cost;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m)), vis(n, vector<int>(m));
        for (int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            vis[i][j] = !a[i][j];
        }
        int cost = 0;
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
            if(!vis[i][j]) cost = max(cost, dfs(i, j, a, vis));
        }
        cout << cost << "\n";
    }
}
