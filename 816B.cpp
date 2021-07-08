
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
const int mx = (2e5+5);
vector<int> a(mx),b(mx);

void solve(){
    int n,k,q; 
    cin >> n >> k >> q;
    int l,r;
    for(int i=0;i<n;++i){
        cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }
    for(int i=1;i<mx;++i){
        a[i]+=a[i-1];
    }
    for(int i=1;i<mx;++i){
        b[i] = b[i-1] + (a[i]>=k);
    }
    for(int i=0;i<q;++i){
        cin >> l >> r;
        cout << b[r]-b[l-1] << "\n";
    }

    
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}