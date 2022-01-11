
#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    vector<int> a(n), dp(500010), dp2(500010);

    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = 0, ret = 0;
    // Find largest sum from left
    for(int i = 0; i < n; ++i) {
        mx += a[i];
        ret = max(ret, mx);
        mx = max(mx, 0ll);
        dp[i] = ret;
    }
    mx = 0, ret = 0;
    // Find largest sum from right
    for(int i = n - 1; i >= 0; --i) {
        mx += a[i];
        ret = max(ret, mx);
        mx = max(mx, 0ll);
        dp2[i] = ret;
    }
    mx = 0;
    // at each index, find max from left and right
    for(int i = 0; i < n - 1; ++i) mx = max(mx, dp[i] + dp2[i + 1]);

    cout << mx;

}

