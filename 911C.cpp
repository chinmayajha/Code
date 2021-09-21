
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
#ifndef ONLINE_JUDGE
    #include "debug.hpp"
#else
    #define print(...)
    #define debug(...)
#endif
void solve(){
    vector<int> a = {nxt(), nxt(), nxt()};
    sort(all(a));
    bool chk = 0;
    if(a[0] == 1) chk = 1;
    if(a[0] == a[1] && a[0] == 2) chk = 1;
    if(a[0] == 2 && a[1] == 4 && a[2] == 4)chk = 1;
    if(a[0] == a[1] && a[1] == a[2] && a[2] == 3) chk = 1;
    cout << (chk ? "YES" : "NO");
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

