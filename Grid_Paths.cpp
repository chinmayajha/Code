
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
//
#ifndef ONLINE_JUDGE
    #include "debug.hpp"
#else
    #define print(...)
    #define debug(...)
#endif
int64_t n;
int64_t dp[1001][1001];
string a[1001];
void fillfirstrow() {
    for(int i = 0; i < n; ++i) {
        if(a[0][i] == '*') {
            for(int j = i; j < n; ++j) dp[0][j] = 0;
            return;
        }
        dp[0][i] = 1;
    }
}
void fillfirstcolumn() {
    for(int i = 0; i < n; ++i) {
        if(a[i][0] == '*') {
            for(int j = i; j < n; ++j) dp[j][0] = 0;
            return;
        }
        dp[i][0] = 1;
    }
}
void fillgrid() {
    for(int i = 1; i < n; ++i) for(int j = 1; j < n; ++j) {
        if(a[i][j] == '*') dp[i][j] = 0;
        else dp[i][j] = (dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
    }
}
void solve(){
	cin >> n;
    for(int i = 0;i < n; ++i) cin >> a[i];
    fillfirstrow();
    fillfirstcolumn();
    fillgrid();
    cout << dp[n - 1][n - 1];
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
