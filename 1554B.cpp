
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n,x,k;cin >> n >> k;
    map<i64,vector<int>> a;
    for(int i=0;i<n;++i){
        cin >> x;
        a[x].emplace_back(i+1);
    }
    for(auto& i : a)sort(rall(i.second));
    vector<pair<i64,vector<int>>> b;
    for(auto& i : a) b.emplace_back(make_pair(i.first,i.second));
    i64 cnt;
    if(sz(b) > 1){
        cnt = b[0].second[0]*b[1].second[0] - (k*(b[0].first | b[1].first));
        cerr << b[0].second[0]*b[1].second[0] << "-" << (k*(b[0].first | b[1].first)) << "\n";
    } else {
        cnt = b[0].second[0]*b[0].second[1] - (k*b[0].first);
        cerr << b[0].second[0]*b[0].second[1] << "-" << (k*b[0].first) << "\n";
    }
    for(auto& i : b){
        cerr << i.first << "-> ";for(auto& v : i.second) {cerr << v << " ";} cerr << "\n";
    }
    cout << cnt << "\n";
    cerr << cnt << "\n";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}


