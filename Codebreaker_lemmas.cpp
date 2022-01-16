#include "bits/stdc++.h"
using namespace std;
#define int long long

void dfs(int& node, vector<vector<int>>& a, vector<int>& vis, vector<int>& cost) {
    vis[node] = 2;
    for(auto& i : a[node]) {
        if(vis[i] != 2) dfs(i, a, vis, cost);
    }
}

signed main() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1);
    vector<int> vis(n + 1, 0), parent(n + 1);
    for(int i = 1, x; i <= n; ++i) {
        cin >> x;
        a[x].push_back(i);
        parent[i] = x;
    } 
    vector<int> cost(n + 1);
    for(int i = 1; i <= n; ++i) cin >> cost[i];

    int ans = 0;
    for(int root2 = 1; root2 <= n; ++root2) {
        int root = root2;
        if(vis[root] == 2) continue;
        stack<int> s;
        while(vis[root] == 0) {
            vis[root] = 1;
            s.push(root);
            root = parent[root];
        }
        int temp = cost[root];
        while(s.top() != root) {
            int cur = s.top(); s.pop();
            temp = min(temp, cost[cur]);
        }
        ans += temp;
        dfs(root, a, vis, cost);
    }
    cout << ans;
}
