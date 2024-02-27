#include "bits/stdc++.h"
using namespace std;
#define int long long


signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, ans = 0; cin >> n;

        vector<int> c(n), d;
        vector<pair<int, int>> lr;

        for (int i = 0, x; i < n; ++i) cin >> x, lr.push_back({x, 1});
        for (int i = 0, x; i < n; ++i) cin >> x, lr.push_back({x, -1});
        for (int i = 0; i < n; ++i) cin >> c[i];

        sort(lr.begin(), lr.end());
        sort(c.begin(), c.end());

        stack<int> stk;
        for(auto& [e, sign] : lr) {
            if(sign == 1) 
                stk.push(e);
            else {
                d.push_back(e - stk.top());
                stk.pop();
            }
        }
        
        sort(d.rbegin(), d.rend());
        
        for(int i = 0; i < n; ++i) ans += d[i] * c[i];
        cout << ans << "\n";
    }
}