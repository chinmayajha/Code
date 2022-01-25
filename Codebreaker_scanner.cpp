#include "bits/stdc++.h"
// #define int long long
std::vector<std::vector<int>> dp(5001, std::vector<int>(5001, INT_MAX));
std::vector<std::string> a2(5001), a(5001);

signed main() {
    int n, m; std::cin >> n >> m;
    for(int i = 0; i < m; ++i) std::cin >> a2[i];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) a[i].push_back(a2[j][i]);
    }
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(a[i][j] == '1') dp[i][j] = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(dp[i][j] == INT_MAX) continue;
            if(i == 0) continue;
            dp[i][j] = dp[i - 1][j];
        }
        if(i == n - 1) break;
        for(int w = 1; w < m; ++w) {
            if(dp[i][w - 1] != INT_MAX) dp[i][w] = std::min(dp[i][w], dp[i][w - 1] + 1);
        }
        for(int w = m - 2; w >= 0; --w) {
            if(dp[i][w + 1] != INT_MAX) dp[i][w] = std::min(dp[i][w], dp[i][w + 1] + 1);
        }
        
    }
    int ans = INT_MAX;
    for(int i = 0; i < m; ++i) ans = std::min(ans, dp[n - 1][i]);
    std::cout << ans;
}

// pref-suffix optimization
