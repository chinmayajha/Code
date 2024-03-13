#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    // cin >> T;
    while (T--) {
        int n; cin >> n;
        if(n % 2 == 0) cout << "NO\n";
        else {
            cout << "YES\n";

            vector<int> ans(2 * n);
            for(int i = 0; i < n; ++i) {
                ans[i] = 2 * i + 1;
                ans[i + n] = 2 * i + 2;

                if(i % 2 == 0) swap(ans[i], ans[i + n]);
            }

            for(int i = 0; i < 2 * n; ++i) cout << ans[i] << " ";
        }
    }
}

