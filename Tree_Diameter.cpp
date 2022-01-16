#include "bits/stdc++.h"
int dist = 0, mx_node = -1;

void dfs(int node, std::vector<std::vector<int>>& a, int cur_dist = 0, int parent = -1) {
    if(cur_dist > dist) mx_node = node, dist = cur_dist;
    for(auto& i : a[node]) if(i != parent) dfs(i, a,  1  + cur_dist, node);
}

signed main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n + 1);
    for(int i = 1, x, y; i <= n - 1; ++i) {
        std::cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, a);
    dist = 0;
    dfs(mx_node, a);
    std::cout << dist;
}
