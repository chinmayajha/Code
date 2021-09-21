
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
	int n, k , d; cin >> n >> k >> d;
    vector<int> a(n);
    inarr(a, n);
    map<int, int> mp;
    for(int i = 0; i < d; ++i) mp[a[i]]++; 
    int ans = sz(mp);
    for(int i = d; i < n; ++i) {
        mp[a[i - d]]--;
        mp[a[i]]++;
        if(mp[a[i - d]] == 0) mp.erase(a[i - d]);
        ans = min(ans, sz(mp));
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
