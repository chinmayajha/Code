#include "bits/stdc++.h"
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int n, m;
vector<int> a, dp;

signed main() {
    cin >> n >> m;
    a.resize(n); dp.assign(m + 1, 0);
    for(int i = 0; i < n; ++i) cin >> a[i];
    dp[0] = 1;
    for(int i = 1; i <= m; ++i) {
        for(auto& coin : a) {
            if(i - coin >= 0) dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }
    cout << dp[m] % MOD;
}