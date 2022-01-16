#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n, x; cin >> n >> x;
    vector<int> a(n), dp(x + 1, 0);
    for(int i = 0; i < n; ++i) cin >> a[i];
    dp[0] = 1;
    for(int i = 1; i <= x; ++i) {
        for(auto& k : a) {
            if(i - k >= 0) dp[i] += dp[i - k];
            dp[i] = dp[i] % 1000000007;
        }
    }
    cout << dp[x] % 1000000007;
}
