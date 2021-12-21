
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
int n, k;
vector<pair<int, int>> a, b;
void solve(){
    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }
    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        b.push_back({x, y});
    }
    map<int, int> x, y;
    for(int = 0; i < n; ++i) {
        x[a[i].second]++;
        y[b[i].second]++;
    }
    int ans = INT_MAX;
    for(auto& i : x) ans = min(ans, i.second);
    for(auto& i : y) ans = min(ans, i.second);
    
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    solve();
}
