
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
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    a[0] = 0, b[0] = 0;
    
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i] += b[i-1];
    }
    int mx2 = INT_MAX;
    for(int i = 1;i <= n; ++i) mx2 = min(mx2, max(a[n] - a[i], b[i - 1]));
    cout << mx2 << "\n";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}


