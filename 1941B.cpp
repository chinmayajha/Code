#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        
        string ans = "YES\n";
        for(int i = 0; i < n - 2; ++i) {
            if(a[i] < 0) ans = "NO\n";
            a[i + 1] -= (2 * a[i]);
            a[i + 2] -= a[i];
            a[i] = 0;
        }
        if(a[n - 1] != 0 || a[n - 2] != 0) ans = "NO\n";

        cout << ans;
    }
}

