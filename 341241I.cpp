
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 a[100005][2], dp[100005][2], n;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i][0];
    for (int i = 1; i <= n; i++) cin >> a[i][1];
    
    for (int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i][0]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i][1]);
    }
    cout << max(dp[n][0], dp[n][1]);
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}


