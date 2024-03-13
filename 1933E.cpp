#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) a[i] += a[i - 1];

        int q, l, u, r; cin >> q;
        while(q--) {
            cin >> l >> u; 
            u += a[l - 1];
            r = lower_bound(a.begin(), a.end(), u) - a.begin();
            r = min(n, r);
            if(r - 1 >= l && (a[r] - u) > (u - a[r - 1])) r--;

            cout << r << " ";
        }

        cout << "\n";
    }
}

