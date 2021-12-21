
#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 10;
int64_t a[N], n, dp[N][3];

void solve(){
    cin >> n;
    for(int64_t i = 0; i < n; ++i) cin >> a[i];

    dp[0][0] = 0, dp[0][1] = a[0], dp[0][2] = -1000*N;

    for(int64_t i = 1; i < n; ++i) {
        dp[i][1] = dp[i - 1][0] + a[i];
        dp[i][2] = dp[i - 1][1] + a[i];
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
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
