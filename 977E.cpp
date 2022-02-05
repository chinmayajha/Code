#include "bits/stdc++.h"

std::vector<std::vector<int>> adj;
std::vector<int> vis;
int n, e, ans;

bool dfs(int node) {
    vis[node] = 1;
    bool check = (int) adj[node].size() == 2;
    for(auto& i : adj[node]) {
        check = std::min((int) (adj[i].size()) == 2, check);
        if(!vis[i]) check = std::min(check, dfs(i));
    }
    return check;
}

signed main() {
    std::cin >> n >> e;
    adj.resize(n + 1); 
    vis.assign(n + 1, 0);

    for(int i = 0, x, y; i < e; ++i) {
        std::cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i) {
        if(vis[i]) continue;
        ans += dfs(i);
    }

    std::cout << ans;
}
