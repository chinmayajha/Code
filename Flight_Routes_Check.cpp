#include "bits/stdc++.h"
using namespace std;

void dfs(int node, vector<vector<int>>& a, vector<int>& vis) {
    vis[node] = 1;
    for(auto& i : a[node]) {
        if(!vis[i]) dfs(i, a, vis);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1), b(n + 1);
    vector<int> vis1(n + 1), vis2(n + 1);
    
    for(int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        b[y].push_back(x);
    }
    dfs(1, a, vis1);
    dfs(1, b, vis2);
    
    for(int i = 1; i <= n; ++i) {
        if(vis1[i] == 0) {
            cout << "NO\n";
            cout << 1 << " " << i;
            return 0;
        }
        if(vis2[i] == 0) {
            cout << "NO\n";
            cout << i << " " << 1;
            return 0;
        }
    }
    
    cout << "YES\n";
}
