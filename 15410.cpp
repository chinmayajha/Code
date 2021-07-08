
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
void solve(){
    int n; 
    cin >> n;
    vector<int> a(n,0);
    iota(all(a),1);
    for(int i=0;i<n - (n%2);i+=2)swap(a[i],a[i+1]);
    if(n%2)swap(a[n-1],a[n-2]);
    for(auto i : a)cout << i << " ";
    cout << "\n";
}
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}

// ll n, ans = 0, sum = 0;
//     string s;
//     cin >> n;
//     if(n % 2 == 0){
//         vector<ll> v;
//         rep(i, 1, n) v.pb(i);
//         for(ll i = 0; i < n; i += 2) swap(v[i], v[i + 1]);
//         for(auto &x : v) cout << x <<" ";
//         return;
//     }
//     else{
//         vector<ll> v;
//         rep(i, 1, n) v.pb(i);
//         for(ll i = 0; i < n - 1; i += 2) swap(v[i], v[i + 1]);
//         swap(v[n - 1], v[n - 2]);
//         for(auto &x : v) cout << x <<" ";
//         return;
//     }

