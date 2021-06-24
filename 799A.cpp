
#include "bits/stdc++.h"
using lli = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#define ceilldiv(x, y) (x + y - 1) / y
#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << n << "\n";
#else
    #define db(...)
#endif
//
void solve(){
    int n,t,k,d; cin >> n >> t >> k >> d;
    if(k>=n){
        cout << "NO\n";
    } else {
        int cur = ceilldiv(n,k);
        int time = d/t;
        if(cur - time > 1) cout << "YES\n";
        else cout << "NO\n";
    }
    
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}