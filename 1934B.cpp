#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, ans; cin >> n;
        ans = n;
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 5; c++) {
                    for (int d = 0; d < 3; d++) {
                        int cur = n - a - 3 * b - 6 * c - 10 * d;
                        if (cur >= 0 && cur % 15 == 0) 
                            ans = min(ans, (cur / 15) + a + b + c + d);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}

