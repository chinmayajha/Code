#include "bits/stdc++.h"
#define int long long
std::vector<int> dp(1000010, INT_MAX);
signed main() {
    dp[0] = 0;
    int n; std::cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(auto& k : std::to_string(i)) {
            if(i - (k - '0') >= 0) dp[i] = std::min(dp[i], 1 +  dp[i - (k - '0')]);
        }
    }
    std::cout << dp[n];
}
