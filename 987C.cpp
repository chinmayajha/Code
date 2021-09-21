
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
	i64 n; cin >> n;
    vector<i64> a(n), cost(n);
    inarr(a, n);
    inarr(cost, n);
    i64 sum = INT_MAX;
    i64 chk = 0;
    for(i64 i = 1; i < n; ++i) if(a[i] > a[i - 1]) chk++;
    if(chk < 2) {
        cout << -1;
        return;
    }
    for(i64 j = 1; j < n - 1; ++j) {
        i64 mni = INT_MAX, mnk = INT_MAX;
        for(i64 i = 0; i < j; ++i) {
            if(a[i] >= a[j]) continue;
            mni = min(cost[i], mni);
        }
        for(i64 k = j + 1; k < n; ++k) {
            if(a[j] >= a[k]) continue;
            mnk = min(cost[k], mnk);
        }
        sum = min(cost[j] + mni + mnk, sum);
    }
    cout << sum;
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

