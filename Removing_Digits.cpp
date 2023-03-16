#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> dp(n + 1, INT_MAX / 2);

    dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        int temp = i;
        while(temp > 0) {
            dp[i] = min(dp[i], 1 + dp[i - (temp % 10)]);
            temp /= 10;
        }
    }
    cout << dp[n];
}
