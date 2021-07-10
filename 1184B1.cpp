
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
    int n,g;cin >> n >> g;
    vector<int> a(n);
    vector<pair<int,int>> b(g);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<g;++i)cin>>b[i].first>>b[i].second;
    sort(all(b));
    for(int i=1;i<g;++i)b[i].second+=b[i-1].second;

    for(auto& i : a){
        int k = lower_bound(b.begin(), b.end(), make_pair(i,INT_MAX)) - b.begin();
        if(k-1>=0)cout << b[k-1].second << " ";
        else cout << "0 ";
    }
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}