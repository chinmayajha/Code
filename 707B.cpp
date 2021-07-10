
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
    int n,m,k,p,q,r;cin >> n >> m >> k;
    vector<pair<int,int>> a[n];
    vector<int> b(k);
    for(int i=0;i<m;++i){
        cin >> p >> q >> r;
        // p--;q--;
        a[p--].emplace_back(make_pair(q,r));
        a[q--].emplace_back(make_pair(p,r));
    }
    vector<bool> vis(n,0);
    for(int i=0;i<k;++i){cin>>b[i];b[i]--;vis[b[i]] = 1;}
    int ans = INT_MAX;
    for(int i=0;i<n;++i){
        if(!vis[i]){
            for(auto& w : a[i]){
                if(vis[w.first])ans = min(ans,w.second);
            }
        }
    }
    if(ans ==INT_MAX)ans = -1;
    cout << ans;
    
    
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}