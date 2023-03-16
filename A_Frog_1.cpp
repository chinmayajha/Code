#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> cost(n + 2, 0), dp(n + 5, 0);
    for(int i = 1; i <= n; ++i) cin >> cost[i];
    
    dp[2] = abs(cost[2] - cost[1]);
    for(int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + abs(cost[i] - cost[i - 1]), 
                    dp[i - 2] + abs(cost[i] - cost[i - 2]));
    }
    cout << dp[n];
}
