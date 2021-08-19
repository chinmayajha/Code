
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n,m,k;cin >> n >> m >> k;
    map<int,vector<int>> a;
    vector<int> temp1(n),temp2(n),b(n);
    inarr(temp1,n);inarr(temp2,n);
    for(int i=0;i<n;++i) a[temp2[i]].emplace_back(temp1[i]);
    inarr(b,k);
    
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


