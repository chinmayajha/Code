#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, c; cin >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        int ans = ((c + 1) * (c + 2)) >> 1, odd = 0, even = 0;

        for(auto& i : a) {
            ans -= (1 + i / 2);
            ans -= c - i + 1;
            if(i % 2 == 0) even++;
            else odd++;
        }

        ans += (even * (even + 1)) / 2;
        ans += (odd * (odd + 1)) / 2;

        cout << ans << "\n";
    }
}

