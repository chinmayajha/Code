#include "bits/stdc++.h"
using i64 = long long int;
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
const i64 MOD = 1000000007;
void solve(){
    int n;cin >> n;
    vector<i64> a(n),b(n);inarr(a,n);
    b[n-1] = a[n-1];
    for(int i=n-2;i>=0;--i)b[i]+=a[i]+b[i+1];
    i64 cnt = 0;
    for(int i=0;i<n-1;++i){
        cnt = (cnt%MOD +  (((a[i]%MOD) * (b[i+1]%MOD))%MOD));
        cnt %= MOD;
    }
    cout << cnt;
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}