#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> coins(n), dp(1000010, 0);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    dp[0] = 1;
    for(int i = 1; i <= m; ++i) {
        for(auto& coin : coins) {
            if(i - coin >= 0) dp[i] = (dp[i] + dp[i - coin]) % 1000000007;
        }
    }
    cout << dp[m] % 1000000007;
}
