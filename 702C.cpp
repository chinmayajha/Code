
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 n,m,ans,mx;

void solve(){
    cin >> n >> m;
    vector<i64> a(n);
    set<i64> b;
    inarr(a,n);
    while(m--) b.insert(nxt());

    for(int i=0;i<n;++i){
        mx = 2000*1000*1000;
        auto it = b.lower_bound(a[i]);
        if(it != b.end()) mx = *it - a[i];
        if(it != b.begin()){
            it--;
            mx = min(mx, a[i] - *it);
        }
        ans = max(mx, ans);
    }
    cout << ans;
    
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


