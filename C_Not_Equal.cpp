
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) {cin >> a[i];}
#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << x << "\n";
#else
    #define db(...)
#endif
//
void solve(){
    int n; cin >> n;
    i64 cnt = 1;
    vector<int> a(n);inarr(a,n);sort(all(a));
    for(int i=0;i<n;++i){
        cnt = cnt * max(0,a[i]-i) % MOD; 
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
