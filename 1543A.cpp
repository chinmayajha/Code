
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << x << "\n";
#else
    #define db(...)
#endif
//
void solve(){
    i64 n,m;cin >> n >> m;
    i64 diff = abs(m-n);
    if(diff == 0)cout << "0 0\n";
    else cout << diff << " " << min(n%diff,diff - n%diff) << "\n";
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}