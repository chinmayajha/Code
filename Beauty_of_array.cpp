#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, ans = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        set<int> window;
        for(int i = 0; i < n; ++i) {
            window.insert(a[i]);
            for(int j = i + 1; j < n; ++j) {
                // i..j subarray
                window.insert(a[j]);
                auto it = window.begin();
                int mn1 = *it;
                ++it;
                int mn2 = *it;
                ans += (mn1 ^ mn2);
            }
            window.erase(window.find(a[i]));
        }

        cout << ans << "\n";
    }
}
