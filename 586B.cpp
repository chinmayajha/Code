
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
	int n; cin >> n;
    vector<int> a(n),b(n),c(n);
    a[0] = 0;
    for(int i = 1;i < n; ++i) cin >> a[i];
    b[n - 1] = 0;
    for(int i = 0;i < n - 1; ++i) cin >> b[i];
    inarr(c, n);
    
    for(int i = 1; i < n; ++i) a[i] += a[i - 1];
    for(int i = n - 2; i >= 0; --i) b[i] += b[i + 1];

    vector<int> time;
    for(int i = 0;i < n; ++i) {
        time.emplace_back(a[i]+b[i]+c[i]);
    }
    sort(all(time));
    cout << time[0] + time[1];
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

