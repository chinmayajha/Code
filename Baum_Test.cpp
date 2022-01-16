#include "bits/stdc++.h"
bool dfs(int node, std::vector<std::set<int>>& a,  std::vector<int>& vis, int parent) {
    if(vis[node]) return 0;
    vis[node] = 1;
    bool chk = 1;
    for(auto& i : a[node]) {
        if(i == parent) continue;
        if(dfs(i, a, vis, node) == 0) chk = 0;
    }
    return chk;
}

signed main() {
    int n, m, ans = 0; std::cin >> n >> m;
    std::vector<std::set<int>> a(n + 1);
    for(int i = 1, x, y; i <= m; ++i){
        std::cin >> x >> y;
        a[x].insert(y);
        a[y].insert(x);
    }
    std::vector<int> vis(n + 1, 0);
    for(int i = 1; i <= n; ++i) ans += dfs(i, a, vis, -1);
    std::cout << ans;
}
