
#include "bits/stdc++.h"
using lli = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];

#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << n << "\n";
#else
    #define db(...)
#endif
//
lli ans, n, m, k, cnt, vleft, vright;
void solve(){
    cin >> n >> m >> k;
    ans = 1, cnt=1;
    m -= n;
    vleft = k,vright = k;
    while(m >= 0){
        m -= cnt;
        ans++;
        vleft -= (vleft > 1);
        vright += (vright < n);
        cnt = vright - vleft + 1;
        if(cnt == n && m > 0) ans += m / n, m -= ((m / n) * n);
    }
    cout << ans - 1;
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}