#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> coins(n), dp(1000010, INT_MAX / 2);
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    dp[0] = 0;
    for(int i = 1; i <= m; ++i) {
        for(auto& coin : coins) {
            if(i - coin >= 0) dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }

    cout << ((dp[m] == INT_MAX / 2) ? -1 : dp[m]);
}
