#include "bits/stdc++.h"

int dfs(int node, std::vector<std::vector<int>>& a, std::vector<int>& ans) {
    int temp = 0;
    for(auto& i : a[node]) temp += dfs(i, a, ans);
    return ans[node] = 1 + temp;
}

signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n + 1);
    std::vector<int> ans(n + 1, 0);
    for(int i = 2, x; i <= n; ++i) {
        std::cin >> x;
        a[x].push_back(i);
    }
    dfs(1, a, ans);

    for(int i = 1; i <= n; ++i) std::cout << ans[i] - 1 << " ";
}
