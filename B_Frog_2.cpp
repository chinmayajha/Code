
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using namespace std;
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
//
#ifndef ONLINE_JUDGE
    #include "debug.hpp"
#else
    #define print(...)
    #define debug(...)
#endif
void solve(){
	int n, m;cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> dp(n + 1);
    dp[1] = 0;
    for(int i = 2; i <= n; ++i) {
        dp[i] = 1000*1000*1000;
        for(int j = max(1, i - m); j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        } 
    }
    cout << dp[n];
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
