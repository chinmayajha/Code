
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> cost(n);
    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

    for(int i = 0; i < n; ++i) {
        cost[i] = min(a[i].first, n - i - 1) + min(a[i].second, i);
        cerr << min(a[i].first, n - i - 1) << " " << min(a[i].second, i) << endl;
    }
    int mx = INT_MIN;
    for(int i = 0; i < n; ++i) mx = max(mx, cost[i]);
    dbg(cost);
    cout << mx << "\n";
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
