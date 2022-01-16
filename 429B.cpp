#include "bits/stdc++.h"
signed main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int64_t>> a(n + 2, std::vector<int64_t>(m + 2, 0));
    auto dp1 = a, dp2 = a, dp3 = a, dp4 = a;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) std::cin >> a[i][j];

    // top left to bottom right
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) dp1[i][j] = std::max(dp1[i - 1][j], dp1[i][j - 1]) + a[i][j];
    // bottom left to top right
    for(int i = n; i >= 1; --i) for(int j = 1; j <= m; ++j) dp2[i][j] = std::max(dp2[i + 1][j], dp2[i][j - 1]) + a[i][j];
    // top right to left bottom
    for(int i = 1; i <= n; ++i) for(int j = m; j >= 1; --j) dp3[i][j] = std::max(dp3[i - 1][j], dp3[i][j + 1]) + a[i][j];
    // bottom right to top left
    for(int i = n; i >= 1; --i) for(int j = m; j >= 1; --j) dp4[i][j] = std::max(dp4[i + 1][j], dp4[i][j + 1]) + a[i][j];

    int64_t ans = 0;
    for(int i = 2; i < n; ++i) for(int j = 2; j < m; ++j) {
        ans = std::max({
            ans,
            dp1[i - 1][j] + dp2[i][j - 1] + dp4[i + 1][j] + dp3[i][j + 1],
            dp1[i][j - 1] + dp2[i + 1][j] + dp4[i][j + 1] + dp3[i - 1][j],
        });
    }
    std::cout << ans;
}