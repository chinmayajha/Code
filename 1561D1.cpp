
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 n,m,dp[200010];
i64 solve2(i64 k) {
    if(k == 1) return k;
    if(dp[k] != -1) return dp[k];
    i64 cnt = 0;
    //possibilities for divisibility 
    for(int i = 2; i < k + 1; ++i) cnt = (cnt + solve2(k/i)) % m;
    //possibilities for sibtraction
    for(int i = 1; i < k; ++i) cnt = (cnt + solve2(k-i)) % m;
    return dp[k] = cnt % m;
} 
void solve(){
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << solve2(n) % m;
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
