
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using namespace std;
#define MOD 15746
//

int64_t n, dp[1000020];
void solve(){
    cin >> n;
    dp[n - 1] = dp[n] = 1;
    for(int k = n - 1; k >= 0; --k) {
        dp[k] = ((dp[k + 1] % MOD) + (dp[k + 2] % MOD)) % MOD;
    }
    cout << dp[0] % MOD;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
