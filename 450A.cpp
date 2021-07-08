
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
    int n,m; cin >> n >> m;
    vector<int> a(n);
    inarr(a,n);
    int k = n-1;
    int val = ceilldiv(a[n-1],m);
    for(int i=n-1;i>=0;--i){
        if(ceilldiv(a[i],m) > val){
            val = ceilldiv(a[i],m);
            k = i;
        }
    }
    cout << k+1;
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}