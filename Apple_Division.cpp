
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 a[21], n;
i64 solve2(i64 k, i64 sum1, i64 sum2) {
    if(k == n) return abs(sum1 - sum2);
    return min(solve2(k + 1, sum1 + a[k], sum2), solve2(k + 1, sum1, sum2 + a[k]));
}
void solve(){
    cin >> n;
    inarr(a, n);
    cout << solve2(0, 0, 0);
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


