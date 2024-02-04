#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first;
        for (int i = 0; i < n; ++i) cin >> b[i].first;
        for (int i = 0; i < n; ++i) cin >> c[i].first;

        for(int i = 0; i < n; ++i) a[i].second = i, b[i].second = i, c[i].second = i;
        sort(a.rbegin(), a.rend()); sort(b.rbegin(), b.rend()); sort(c.rbegin(), c.rend());

        int ans = 0;
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                for(int k = 0; k < 3; ++k) {
                    if(a[i].second == b[j].second || a[i].second == c[k].second || b[j].second == c[k].second) continue;
                    ans = max(ans, a[i].first + b[j].first + c[k].first);
                }
        
        cout << ans << "\n";
    }
}
