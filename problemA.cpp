
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
    int n,k; cin >> n >> k;
    vector<int> a(n);inarr(a,n);
    cout << *max_element(all(a)) - *min_element(all(a)) << "\n";
}
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}