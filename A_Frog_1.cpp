
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int n, a[100010], dp[100010];

int solve2(int k) {
    if(k >= n - 1) return 0;
    if(dp[k] != -1) return dp[k];
    
    int cnt1 = INT_MAX, cnt2 =INT_MAX;
    cnt1 = abs(a[k] - a[k+1]) + solve2(k + 1);
    if(k+2 < n) cnt2 = abs(a[k] - a[k+2]) + solve2(k + 2);
    dp[k] = min(cnt1, cnt2);
    return dp[k];
}

void solve(){
    cin >> n; inarr(a,n);
    memset(dp, -1, sizeof(dp));
    cout << solve2(0);
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        solve();
    }
}


