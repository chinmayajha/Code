#include "bits/stdc++.h"
using namespace std;

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    // cin >> T;
    while (T--) {
        int n; cin >> n;
        int a, b, c; cin >> a >> b >> c;
        // k1a + k2b + k3c = n
        // k1 + k2 + k3 = max

        int mx = 0;
        for(int k1 = 0; k1 <= 4000; k1++) {
            for(int k2 = 0, k3; k2 <= 4000; k2++) {
                k3 = (n - k1 * a - k2 * b);
                if(k3 < 0) continue;
                if(k3 % c != 0) continue;
                k3 /= c;
                mx = max(k1 + k2 + k3, mx);
            }
        }

        cout << mx << "\n";
    }
}