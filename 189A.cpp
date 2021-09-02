
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
#define sz(x) ((int)(x).size()) 
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n,a,b,c; cin >> n >> a >> b >> c;
    if(a == 1 || b == 1 || c == 1) {cout << n; return;}
    int mx = 1;
    for(int k1 = 0; k1 <= 800; ++k1) for(int k2 = 0; k2 <= 800; ++k2) for(int k3 = 0; k3 <= 800; ++k3) {
        if(n == k1*a + k2*b + k3*c) mx = max(mx,k1+k2+k3);
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


