
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
    i64 n,k;cin >> n >> k;
    vector<i64> b(n);inarr(b,n);
    map<i64,int> a;
    i64 mx = 0;
    for(int i=0;i<n;++i){
        a[b[i]]++;
        if(i-k >= 0){
            a[b[i-k]]--;
            if(a[b[i-k]] <= 0) a.erase(b[i-k]);
        }
        mx = max(mx,sz(a)*1ll);
    }
    cout << mx;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
