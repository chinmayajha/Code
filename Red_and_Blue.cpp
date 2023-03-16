#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int ans = 0, fixed = -1, covered = -1;
        for(int i = 0; i < n; ++i) {
            if(i > fixed && s[i] == 'B') {
                if(i > covered) {
                    ans = -1;
                    break;
                }
                ans += 1;
                fixed = covered;
            }
            covered = max(covered, i + a[i]);
        }

        cout << ans << "\n";
    }
}
