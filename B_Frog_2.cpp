#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n, k; cin >> n >> k;
    vector<int> cost(n + 1, 0), dp(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> cost[i];
    
    dp[2] = abs(cost[2] - cost[1]);
    for(int i = 3; i <= n; ++i) {
        dp[i] = INT_MAX / 2;
        for(int j = 1; j <= k; ++j) {
            if(i - j >= 1) dp[i] = min(dp[i], dp[i - j] + abs(cost[i] - cost[i - j]));
        }
    }
    
    cout << dp[n];
}
