
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
    i64 n;
    cin >> n;
    vector<i64> a(n),b(n),ans(n);
    int mnind = -1, mnele = INT_MAX;
    generate_n(a.begin(), n, nxt);
    if(n == 1){
        cout << b[0];
        return;
    }
    for(int i=0;i<n;++i){
        cin >> b[i];
        if(b[i] < mnele) {
            mnele = b[i];
            mnind = i;
        }
    }
    ans[mnind] = b[mnind];
    for(int i = mnind+1;i < n; ++i){
        ans[i] = min(ans[i-1] + a[i-1], b[i]);
    }
    ans[0] = min(ans[n-1] + a[n-1],b[0]);
    for(int i=1;i<mnind;++i){
        ans[i] = min(ans[i-1] + a[i-1], b[i]);
    }
    for(auto& i : ans) {cout << i << "\n";}
    
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


