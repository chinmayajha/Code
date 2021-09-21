
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
int a[301][301];
void solve(){
	int n; cin >> n;
    int cnt = 1;
    for(int i = 0;i < n; i += 2) {
        for(int j = 0; j < n; j++) {
            a[j][i] = cnt;
            cnt++;
        }
        cnt += n;
    }
    cnt = n + 1;
    for(int i = 1;i < n; i += 2) {
        for(int j = n - 1; j >= 0; j--) {
            a[j][i] = cnt;
            cnt++;
        }
        cnt += n;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) cout << a[i][j] << " ";
        cout << "\n";
    }
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
