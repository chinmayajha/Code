#include "bits/stdc++.h"
#define int long long
std::vector<int> dp(1000010, 0);
signed main() {
    dp[0] = 1;
    int n; std::cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= 6 && i - j >= 0; ++j) dp[i] = (dp[i] + dp[i - j]) % 1000000007;
    }
    std::cout << dp[n] % 1000000007;
}
