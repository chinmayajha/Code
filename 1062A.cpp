
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 1; i <= n; ++i) cin >> a[i];
//
#ifndef ONLINE_JUDGE
    #include "debug.hpp"
#else
    #define print(...)
    #define debug(...)
#endif
void solve(){
	int n; cin >> n;
    vector<int> a(102, 0);
    a[n + 1] = 1001;
    inarr(a, n);
    if(n <= 2) {
        if(n == 2 && (a[1] == 999 || a[2] == 2)) cout << 1;
        else cout << 0;
        return;
    }
    int mx = 0;
    int cur = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] - a[i + 1] == -1 && a[i + 2] - a[i + 1] == 1) {
            cur++;
        } else cur = 0;
        mx = max(mx, cur);
    }
    cout << mx;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

