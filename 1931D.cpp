#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, x, y; cin >> n >> x >> y;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

        map<pair<int, int>, int> mp; int ans = 0;
        for(auto& i : a) {
            ans += mp[{(x - (i % x)) % x, i % y}];
            mp[{i % x, i % y}] += 1;
        }
        
        cout << ans << "\n";
    }
}