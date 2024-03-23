#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> a(n + 1, INT_MAX), b(n + 1, INT_MAX);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> b[i];

        int cost = 0;
        for(int i = m + 1; i <= n; ++i) cost += min(a[i], b[i]);

        int sumb = 0, reach = a[m], finsumb = 0;
        for(int i = m - 1; i >= 1; --i) {
            sumb += b[i + 1]; // ai is potential reach
            if(sumb + a[i] < reach + finsumb) {
                reach = a[i];
                finsumb = sumb;
            }
        }

        cout << cost + finsumb + reach << "\n";
    }
}

