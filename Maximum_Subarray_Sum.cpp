#include "bits/stdc++.h"
signed main() {
    int n; std::cin >> n; 
    std::vector<long long> dp(n + 1, 0);
    for(int i = 1, x; i <= n; ++i) std::cin >> x, dp[i] = std::max(dp[i - 1] + x, 1ll * x);
    std::cout << *max_element(dp.begin() + 1, dp.end());
}
