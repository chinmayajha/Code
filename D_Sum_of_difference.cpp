
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
void solve(){
    int n;cin >> n;
    vector<i64> a(n);
    inarr(a,n);
    sort(all(a));
    i64 cnt = 0;
    for(int i=0;i<n;++i)cnt += (i*a[i]);
    for(int i=n-1;i>=0;--i)cnt -= ((n-i-1)*a[i]);
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