#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, m, ans = INT_MAX; cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) {
            int ans2 = 0;
            for(int k = 0; k < m; ++k) ans2 += abs(a[i][k] - a[j][k]);
            ans = min(ans, ans2);
        }
        cout << ans << "\n";
    }
}
