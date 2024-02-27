#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n + 1, 0);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            b[abs(x)] += a[i];
        }

        string ans = "YES\n";
        for(int i = 1; i <= n; ++i) b[i] += b[i - 1];
        for(int i = 1; i <= n; ++i) {
            if(b[i] > i * k) ans = "NO\n";
        }
        cout << ans;        
    }
}

